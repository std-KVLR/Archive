e build version
			BuildVersion Version;
			if (!BuildVersion.TryParse(RawObject.GetObjectField("Version"), out Version))
			{
				throw new JsonParseException("Invalid 'Version' field");
			}

			// Create the receipt
			TargetReceipt Receipt = new TargetReceipt(TargetName, Platform, Configuration, BuildId, Version);

			// Read the build products
			JsonObject[] BuildProductObjects;
			if (RawObject.TryGetObjectArrayField("BuildProducts", out BuildProductObjects))
			{
				foreach (JsonObject BuildProductObject in BuildProductObjects)
				{
					string Path;
					BuildProductType Type;
					if (BuildProductObject.TryGetStringField("Path", out Path) && BuildProductObject.TryGetEnumField("Type", out Type))
					{
						string Module;
						BuildProductObject.TryGetStringField("Module", out Module);

						BuildProduct NewBuildProduct = Receipt.AddBuildProduct(Path, Type);

						bool IsPrecompiled;
						if (BuildProductObject.TryGetBoolField("IsPrecompiled", out IsPrecompiled))
						{
							NewBuildProduct.IsPrecompiled = IsPrecompiled;
						}
					}
				}
			}

			// Read the runtime dependencies
			JsonObject[] RuntimeDependencyObjects;
			if (RawObject.TryGetObjectArrayField("RuntimeDependencies", out RuntimeDependencyObjects))
			{
				foreach (JsonObject RuntimeDependencyObject in RuntimeDependencyObjects)
				{
					string Path;
					if (RuntimeDependencyObject.TryGetStringField("Path", out Path))
					{
						StagedFileType Type;
						if(!RuntimeDependencyObject.TryGetEnumField("Type", out Type))
						{
							// Previous format included an optional IgnoreIfMissing flag, which was only used for debug files. We can explicitly reference them as DebugNonUFS files now.
							bool bI