// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/CommandLine.h"
#include "Misc/Guid.h"
#include "Misc/AutomationTest.h"
#include "Misc/App.h"
#include "EngineAnalytics.h"
#include "AnalyticsEventAttribute.h"
#include "Interfaces/IAnalyticsProvider.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
* Artificial Record Event for analytics - Simulates the engine startup simulation.  
*/
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAnalyticStartUpSimTest, "System.Engine.Analytic.Record Event - Simulate Program Start", EAutomationTestFlags::FeatureMask | EAutomationTestFlags::ClientContext | EAutomationTestFlags::EngineFilter)

bool FAnalyticStartUpSimTest::RunTest(const FString& Parameters)
{
	if (FEngineAnalytics::IsAvailable())
	{
		//Setup a temp AccountID.
		FGuid TempAccountID(FGuid::NewGuid());
		FString OldEpicAccountID = FPlatformMisc::GetEpicAccountId();
		FString NewEpicAccountID = TempAccountID.ToString().ToLower();
		FPlatformMisc::SetEpicAccountId(NewEpicAccountID);

		//Setup the 'Event Attributes'
		TArray<FAnalyticsEventAttribute> EventAttributes;
		EventAttributes.Add(FAnalyticsEventAttribute(TEXT("LoginID"),		FPlatformMisc::GetLoginId()));
		EventAttributes.Add(FAnalyticsEventAttribute(TEXT("AccountID"),		FPlatformMisc::GetEpicAccountId()));
		EventAttributes.Add(FAnalyticsEventAttribute(TEXT("OSID"),			FPlatformMisc::GetOperatingSystemId()));
		EventAttributes.Add(FAnalyticsEventAttribute(TEXT("GameName"),		FApp::GetGameName()));
		EventAttributes.Add(FAnalyticsEventAttribute(TEXT("CommandLine"),	FCommandLine::Get()));
		
		//Record the event with the 'Engine.AutomationTest.Analytics.ProgramStartedEvent' title
		FEngineAnalytics::GetProvider().RecordEvent(TEXT("Engine.AutomationTest.Analytics.ProgramStartedEvent"), EventAttributes);

		//Get the event strings used
		FString LoginIDTest		=	FPlatformMisc::GetLoginId();
		FString AccountIDTest	=	FPlatformMisc::GetEpicAccountId();
		FString OSID			=	FPlatformMisc::GetOperatingSystemId();
		FString GameNameTest	=	FApp::GetGameName();
		FString CommandLineArgs	=	FCommandLine::Get();

		//Test the strings to verify they have data.
		TestFalse(TEXT("'LoginID' is not expected to be empty!"), LoginIDTest.IsEmpty());
		TestFalse(TEXT("'AccountID' is not expected to be empty!"), AccountIDTest.IsEmpty());
		TestFalse(TEXT("'OperatingSystemID' is not expected to be empty!"), OSID.IsEmpty());
		TestFalse(TEXT("'GameName' is expected."), GameNameTest.IsEmpty());


		//Verify record event is holding the actual data.  This only triggers if the command line argument of 'AnalyticsDisableCaching' was used.
		if (CommandLineArgs.Contains(TEXT("AnalyticsDisableCaching")))
		{
			FString FullLoginIDTestEventName = FString::Printf(TEXT("LoginID\":\"%s"), *LoginIDTest);
			FString FullAccountIDTestEventName = FString::Printf(TEXT("AccountID\":\"%s"), *AccountIDTest);
			FString FullOSIDTestEventName = FString::Printf(TEXT("OSID\":\"%s"), *OSID);

			for (int32 i = 0; i < ExecutionInfo.LogItems.Num(); i++)
			{
				if (ExecutionInfo.LogItems[i].Contains(TEXT("Engine.AutomationTest.Analytics.ProgramStartedEvent")))
				{
					TestTrue(TEXT("Recorded event name is expected to be in the sent event."), ExecutionInfo.LogItems[i].Contains(TEXT("Engine.AutomationTest.Analytics.ProgramStartedEvent")));
					TestTrue(TEXT("'LoginID' is expected to be in the sent event."), ExecutionInfo.LogItems[i].Contains(*FullLoginIDTestEventName));
					TestTrue(TEXT("'AccountID' is expected to be in the sent event."), ExecutionInfo.LogItems[i].Contains(*FullAccountIDTestEventName));
					TestTrue(TEXT("'OperatingSystemID' is expected to be in the sent event."), ExecutionInfo.LogItems[i].Contains(*FullOSIDTestEventName));
					TestTrue(TEXT("'GameName' is expected to be in the sent event."), ExecutionInfo.LogItems[i].Contains(*GameNameTest));
					TestTrue(TEXT("'CommandLine arguments' are expected to be in the sent event."), ExecutionInfo.LogItems[i].Contains(TEXT("AnalyticsDisableCaching")));
				}
			}
		}

		//Set the AccountID to it's original state.
		FPlatformMisc::SetEpicAccountId(OldEpicAccountID);
		return true;
	}

	ExecutionInfo.LogItems.Add(TEXT("SKIPPED 'FAnalyticStartUpSimTest' test.  EngineAnalytics are not currently available."));
	return true;	
}


/**
* FAnalyticsEventAttribute Unit Test.
*/
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAnalyticsEventAttributeUnitTest, "System.Engine.Analytic.EventAttribute Struct Unit Test", EAutomationTestFlags::FeatureMask | EAutomationTestFlags::ClientContext | EAutomationTestFlags::EngineFilter)

bool FAnalyticsEventAttributeUnitTest::RunTest(const FString& Parameters)
{
	if (FEngineAnalytics::IsAvailable())
	{
		FString AttributeName;
		FString AttributeValue;

		AttributeName = "Test of";
		AttributeValue = "FAnalyticsEventAttribute '(const FString InName, const FString& InVaue)'";

		//Setup the 'Event Attributes'
		FAnalyticsEventAttribute EventAttributesFStringTest(AttributeName, AttributeValue);
		TestTrue(TEXT("Expected to take in these type of values '(const FString&, const FString&)'"), (EventAttributesFStringTest.AttrName == TEXT("Test of") && EventAttributesFStringTest.AttrValue == "FAnalyticsEventAttribute '(const FString InName, const FString& InVaue)'"));

		FAnalyticsEventAttribute EventAttributesTCHARTest(AttributeName, TEXT("FAnalyticsEventAttribute '(const FString InName, const TCHAR* InValue)'"));
		TestTrue(TEXT("Expected to take in these type of values '(const FString&, const TCHAR*')"), (EventAttributesTCHARTest.AttrName == TEXT("Test of") && EventAttributesTCHARTest.AttrValue == TEXT("FAnalyticsEventAttribute '(const FString InName, const TCHAR* InValue)'")));

		bool bIsBoolTest = true;
		FAnalyticsEventAttribute EventAttributesBoolTest(AttributeName, bIsBoolTest);
		TestTrue(TEXT("Expected to take in these types of values '(const FString&, bool)'"), (EventAttributesBoolTest.AttrName == TEXT("Test of") && EventAttributesBoolTest.AttrValue == "true"));

		FGuid GuidTest(FGuid::NewGuid());
		FAnalyticsEventAttribute EventAttributesGuidTest(AttributeName, GuidTest);
		TestTrue(TEXT("Expected to take in these type of values '(const FString&, FGuid)'"), (EventAttributesGuidTest.AttrName == TEXT("Test of") && EventAttributesGuidTest.AttrValue == GuidTest.ToString()));

		int32 InNumericType = 42;
		FAnalyticsEventAttribute EventAttributesTInValueTest(AttributeName, InNumericType);
		TestTrue(TEXT("Expected to take in a arithmetic type (example int32)"), (EventAttributesTInValueTest.AttrName == TEXT("Test of") && EventAttributesTInValueTest.AttrValue == TEXT("42")));

		TArray<int32> InNumericArray;
		InNumericArray.Add(0);
		InNumericArray.Add(1);
		InNumericArray.Add(2);
		FAnalyticsEventAttribute EventAttributesTArray(AttributeName, InNumericArray);
		TestTrue(TEXT("Expected to take in am arithmetic TArray"), (EventAttributesTArray.AttrName == TEXT("Test of") && EventAttributesTArray.AttrValue == TEXT("0,1,2")));

		FString TMapKey1 = "TestKey 1";
		FString TMapKey2 = "TestKey 2";
		FString TMapKey3 = "TestKey 3";
		int32 NumericValue1 = 0;
		int32 NumericValue2 = 1;
		int32 NumericValue3 = 99;
		TMap<FString, int32> InTMap;
		InTMap.Add(TMapKey1, NumericValue1);
		InTMap.Add(TMapKey2, NumericValue2);
		InTMap.Add(TMapKey3, NumericValue3);
		FAnalyticsEventAttribute EventAttributesTMap(AttributeName, InTMap);
		TestTrue(TEXT("Expected to take in a TMap "), (EventAttributesTMap.AttrName == TEXT("Test of") && EventAttributesTMap.AttrValue == TEXT("TestKey 1:0,TestKey 2:1,TestKey 3:99")));

		return true;
	}

	ExecutionInfo.LogItems.Add(TEXT("SKIPPED 'FAnalyticsEventAttributeUnitTest' test.  EngineAnalytics are not currently available."));
	return true;
}

#endif //WITH_DEV_AUTOMATION_TESTS
                                                                                                                                                                                                                                                                                                             // Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "CoreMinimal.h"
#include "HAL/PlatformProcess.h"
#include "HAL/FileManager.h"
#include "Misc/Paths.h"
#include "Misc/AutomationTest.h"
#include "Tests/AutomationTestSettings.h"

#if WITH_DEV_AUTOMATION_TESTS

DEFINE_LOG_CATEGORY_STATIC(LogBaseAutomationTests, Log, All);

/**
 * Holds the process info for an external tool
 */
namespace ExternalProcessHelper
{
	struct ExternalProcessInfo
	{
		ExternalProcessInfo()
			: ProcessHandle()
			, ReadPipe(NULL)
			, WritePipe(NULL)
		{
		}
		// Holds the process handle
		FProcHandle		ProcessHandle;
		// Holds the read pipe.
		void* ReadPipe;
		// Holds the write pipe.
		void* WritePipe;
	};
}
/**
 * Wait for an external process to finish
 */
DEFINE_LATENT_AUTOMATION_COMMAND_ONE_PARAMETER(FWaitForProcessToCompleteLatentCommand, ExternalProcessHelper::ExternalProcessInfo, ProcessInfo);

bool FWaitForProcessToCompleteLatentCommand::Update()
{
	if( ProcessInfo.ProcessHandle.IsValid() )
	{
		//Check for any output
		FString ProcessOutput = FPlatformProcess::ReadPipe(ProcessInfo.ReadPipe);
		if( ProcessOutput.Len() > 0 )
		{
			TArray<FString> OutputLines;
			ProcessOutput.ParseIntoArray(OutputLines, TEXT("\n"), false);
			for( int32 i = 0; i < OutputLines.Num(); i++ )
			{
				UE_LOG(LogBaseAutomationTests, Log, TEXT("%s"), *OutputLines[i]);
			}
		}

		//We aren't done until the process stops
		if( FPlatformProcess::IsProcRunning(ProcessInfo.ProcessHandle) )
		{
			return false;
		}

		FPlatformProcess::ClosePipe(ProcessInfo.ReadPipe,ProcessInfo.WritePipe);
		ProcessInfo.ReadPipe = NULL;
		ProcessInfo.WritePipe = NULL;

		//Check for any return codes
		int32 ReturnCode;
		if( !FPlatformProcess::GetProcReturnCode(ProcessInfo.ProcessHandle,&ReturnCode) )
		{
			ReturnCode = -1;
		}

		if( ReturnCode != 0 )
		{
			UE_LOG(LogBaseAutomationTests, Error, TEXT("External Tool failed with error code: %i"),ReturnCode);
		}
	}

	return true;
}

/**
 * RunExternalToolTest
 */
IMPLEMENT_COMPLEX_AUTOMATION_TEST(FRunExternalToolTest, "External", EAutomationTestFlags::EditorContext | EAutomationTestFlags::NonNullRHI | EAutomationTestFlags::EngineFilter)

/** 
 * Find all the external too commands
 */
void FRunExternalToolTest::GetTests(TArray<FString>& OutBeautifiedNames, TArray <FString>& OutTestCommands) const
{
	UAutomationTestSettings const* AutomationTestSettings = GetDefault<UAutomationTestSettings>();
	check(AutomationTestSettings);

	for( int32 i = 0; i < AutomationTestSettings->ExternalTools.Num(); i++ )
	{
		const FExternalToolDefinition& ToolIt = AutomationTestSettings->ExternalTools[i];
		if( ToolIt.ExecutablePath.FilePath.Len() > 0 )
		{
			// Check for multiple scripts if we have a script extension to look for
			if( ToolIt.ScriptExtension.Len() > 0 && ToolIt.ScriptDirectory.Path.Len() > 0 )
			{
				TArray<FString> ScriptFileNames;

				//Remove the "." before the extension if it exists
				const FString ScriptExtension = ToolIt.ScriptExtension.StartsWith(TEXT(".")) ? ToolIt.ScriptExtension.Right(ToolIt.ScriptExtension.Len() - 1) : ToolIt.ScriptExtension;

				IFileManager::Get().FindFiles(ScriptFileNames, *(ToolIt.ScriptDirectory.Path / TEXT("*.") + ScriptExtension), true, false);

				for (TArray<FString>::TConstIterator ScriptIt(ScriptFileNames); ScriptIt; ++ScriptIt)
				{
					const FString ScriptName = FString::Printf(TEXT("%s: %s"),*ToolIt.ToolName,*FPaths::GetBaseFilename(*ScriptIt));
					OutBeautifiedNames.Add(*ScriptName);

					const FString SctiptCommand = FString::Printf(TEXT("%s;%s;%s"),*ToolIt.ExecutablePath.FilePath,**ScriptIt,ToolIt.WorkingDirectory.Path.Len() > 0 ? *ToolIt.WorkingDirectory.Path : *ToolIt.ScriptDirectory.Path);
					OutTestCommands.Add(*SctiptCommand);
				}
			}
			else
			{
				OutBeautifiedNames.Add(*ToolIt.ToolName);
				const FString ToolCommand = FString::Printf(TEXT("%s;%s;%s"),*ToolIt.ExecutablePath.FilePath,*ToolIt.CommandLineOptions,*ToolIt.WorkingDirectory.Path);
				OutTestCommands.Add(*ToolCommand);
			}
		}
	}
}

/** 
 * Launch the external tool as a process and wait for it to complete
 *
 * @param Parameters - The command to launch the external tool
 * @return	TRUE if the test was successful, FALSE otherwise
 */
bool FRunExternalToolTest::RunTest(const FString& Parameters)
{
	TArray<FString> Commands;
	Parameters.ParseIntoArray(Commands,TEXT(";"),false);

	if( Commands.Num() != 3 )
	{
		UE_LOG(LogBaseAutomationTests, Error, TEXT("ERROR Parsing commands for external tool: %s"),*Parameters);
		return false;
	}

	const FString& Executable       = Commands[0];
	const FString& Options          = Commands[1];
	const FString& WorkingDirectory = Commands[2];

	//Create the pipes that we can use to read the output of the process
	ExternalProcessHelper::ExternalProcessInfo ProcessInfo;
	if (!FPlatformProcess::CreatePipe(ProcessInfo.ReadPipe, ProcessInfo.WritePipe))
	{
		return false;
	}
	
	//Create the new process
	ProcessInfo.ProcessHandle = FPlatformProcess::CreateProc(*Executable,
															*Options,
															true,
															false,
															false,
															NULL,
															0,
															WorkingDirectory.Len() > 0 ? *WorkingDirectory : NULL,
															ProcessInfo.WritePipe);

	//Check that we got a valid process handle
	if( ProcessInfo.ProcessHandle.IsValid() )
	{
		ADD_LATENT_AUTOMATION_COMMAND(FWaitForProcessToCompleteLatentCommand(ProcessInfo));
	}
	else
	{
		UE_LOG(LogBaseAutomationTests, Error, TEXT("Failed to launch executable (%s) for external tool %s"),*Executable, *Parameters);
		FPlatformProcess::ClosePipe(ProcessInfo.ReadPipe, ProcessInfo.WritePipe);
		return false;
	}

	return true;
}

#endif //WITH_DEV_AUTOMATION_TESTS
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          // Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "CoreMinimal.h"
#include "Serialization/MemoryWriter.h"
#include "Serialization/MemoryReader.h"
#include "Misc/AutomationTest.h"
#include "UObject/Package.h"
#include "UObject/TextProperty.h"
#include "Tests/TextPropertyTestObject.h"

#define LOCTEXT_NAMESPACE "TextPropertyTest"

UTextPropertyTestObject::UTextPropertyTestObject(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer), DefaultedText(LOCTEXT("DefaultedText", "DefaultValue"))
{
}

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTextPropertyTest, "System.Engine.Internationalization.Text Property Test", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)

bool FTextPropertyTest::RunTest (const FString& Parameters)
{
	UClass* const TextPropertyTestObjectClass = UTextPropertyTestObject::StaticClass();
	UTextProperty* const DefaultedTextProperty = FindField<UTextProperty>(TextPropertyTestObjectClass, "DefaultedText");
	UTextProperty* const UndefaultedTextProperty = FindField<UTextProperty>(TextPropertyTestObjectClass, "UndefaultedText");
	UTextPropertyTestObject* const TextPropertyTestCDO = Cast<UTextPropertyTestObject>( TextPropertyTestObjectClass->ClassDefaultObject );

	{
		UTextPropertyTestObject* NewUObject = NewObject<UTextPropertyTestObject>(GetTransientPackage(), TextPropertyTestObjectClass);

		// Test Identical - Newly constructed object properties should be identical to class default object properties.
		if ((DefaultedTextProperty->Identical(&(NewUObject->DefaultedText), &(TextPropertyTestCDO->DefaultedText), 0) != true)
			||
			(UndefaultedTextProperty->Identical(&(NewUObject->UndefaultedText), &(TextPropertyTestCDO->UndefaultedText), 0) != true))
		{
			AddError(TEXT("UTextProperty::Identical failed to return true comparing a newly constructed object and the class default object."));
		}

		// Test ExportText - Export text should provide the localized form of the text.
		{
			FString ExportedStringValue;
			DefaultedTextProperty->ExportTextItem(ExportedStringValue, &(NewUObject->DefaultedText), NULL, NULL, 0, NULL);
			FText ExportedTextValue;
			FTextStringHelper::ReadFromString(*ExportedStringValue, ExportedTextValue);
			if (ExportedTextValue.ToString() != NewUObject->DefaultedText.ToString())
			{
				AddError(TEXT("UTextProperty::ExportTextItem failed to provide the display string."));
			}
		}

		// Test ImportText - Import text should set the source string to the input string.
		{
			FString ImportedStringValue = TEXT("ImportValue");
			DefaultedTextProperty->ImportText(*ImportedStringValue, &(NewUObject->DefaultedText), 0, NULL);
			const FString* const SourceString = FTextInspector::GetSourceString(NewUObject->DefaultedText);
			if( !SourceString || ImportedStringValue != *SourceString )
			{
				AddError(TEXT("UTextProperty::ImportText failed to alter the source string to the provided value."));
			}
		}
	}

	// Test Identical - Altered text properties should not be identical to class default object properties.
	{
		UTextPropertyTestObject* NewUObject = NewObject<UTextPropertyTestObject>(GetTransientPackage(), TextPropertyTestObjectClass);

		NewUObject->DefaultedText = LOCTEXT("ModifiedDefaultedText", "Modified DefaultedText Value");
		NewUObject->UndefaultedText = LOCTEXT("ModifiedUndefaultedText", "Modified UndefaultedText Value");
		if( 
			DefaultedTextProperty->Identical(&(NewUObject->DefaultedText), &(TextPropertyTestCDO->DefaultedText), 0)
			||
			UndefaultedTextProperty->Identical(&(NewUObject->UndefaultedText), &(TextPropertyTestCDO->UndefaultedText), 0)
		  )
		{
			AddError(TEXT("UTextProperty::Identical failed to return false comparing a modified object and the class default object."));
		}
	}

	{
		TArray<uint8> BackingStore;
		
		auto SavedObject = NewObject<UTextPropertyTestObject>();

		FText::FindText( TEXT("TextPropertyTest"), TEXT("DefaultedText"), /*OUT*/SavedObject->DefaultedText );
		SavedObject->UndefaultedText = LOCTEXT("ModifiedUndefaultedText", "Modified UndefaultedText Value");
		const FText TransientText = FText::Format( LOCTEXT("TransientTest", "{0}"), LOCTEXT("TransientTestMessage", "Testing Transient serialization detection") );
		SavedObject->TransientText = TransientText;

		// Test Identical - Text properties with the same source as class default object properties should be considered identical. 
		if( !( DefaultedTextProperty->Identical(&(SavedObject->DefaultedText), &(TextPropertyTestCDO->DefaultedText), 0) ) )
		{
			AddError(TEXT("UTextProperty::Identical failed to return true comparing an FText with an identical source string to the class default object."));
		}

		// Save.
		{
			FMemoryWriter MemoryWriter(BackingStore, true);
			SavedObject->Serialize(MemoryWriter);
		}

		auto LoadedObject = NewObject<UTextPropertyTestObject>();

		// Load.
		{
			FMemoryReader MemoryReader(BackingStore, true);
			LoadedObject->Serialize(MemoryReader);
		}

		// Test Serialization - Loaded object should be identical to saved object. 
		if( 
			!( DefaultedTextProperty->Identical(&(LoadedObject->DefaultedText), &(SavedObject->DefaultedText), 0) )
			||
			!( UndefaultedTextProperty->Identical(&(LoadedObject->UndefaultedText), &(SavedObject->UndefaultedText), 0) )
		  )
		{
			AddError(TEXT("Saving and loading a serialized object containing FText properties failed to maintain FText values."));
		}

		// Test Identical - Text properties with the same source as the class default object property should save and load as the class default object property.
		if( !( DefaultedTextProperty->Identical(&(LoadedObject->DefaultedText), &(TextPropertyTestCDO->DefaultedText), 0) ) )
		{
			AddError(TEXT("UTextProperty::Identical failed to collapse identical source strings into the same namespace and key during serialization."));
		}

		// Test Transient - Transient text properties should save out an error message instead of their actual string value
		const FString* const LoadedTransientTextString = FTextInspector::GetSourceString(LoadedObject->TransientText);
		const FString* const TransientTextString = FTextInspector::GetSourceString(TransientText);
		if ( GIsEditor && LoadedTransientTextString && TransientTextString && *(LoadedTransientTextString) != *(TransientTextString) )
		{
			AddError(TEXT("Transient Texts should not exist in the editor."));
		}
		else if ( !GIsEditor && LoadedObject->TransientText.ToString() != FText::Format( LOCTEXT("Error_SerializationFailure", "ERR: Transient text cannot be serialized \"{0}\"."), TransientText ).ToString() )
		{
			//AddError(TEXT("Transient Texts should persist an error message when they are serialized."));
		}
	}

	return true;
}

#undef LOCTEXT_NAMESPACE

#endif //WITH_DEV_AUTOMATION_TESTS
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         // Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OnlineLeaderboardInterface.h"
#include "AndroidRuntimeSettings.h"

struct FOnlinePendingLeaderboardWrite
{
	FString LeaderboardName;
	uint64 Score;
};

/**
 * Interface definition for the online services leaderboard services 
 */
class FOnlineLeaderboardsGooglePlay : public IOnlineLeaderboards
{
public:
	FOnlineLeaderboardsGooglePlay(class FOnlineSubsystemGooglePlay* InSubsystem);

	virtual bool ReadLeaderboards(const TArray< TSharedRef<const FUniqueNetId> >& Players, FOnlineLeaderboardReadRef& ReadObject) override;
	virtual bool ReadLeaderboardsForFriends(int32 LocalUserNum, FOnlineLeaderboardReadRef& ReadObject) override;
	virtual void FreeStats(FOnlineLeaderboardRead& ReadObject) override;
	virtual bool WriteLeaderboards(const FName& SessionName, const FUniqueNetId& Player, FOnlineLeaderboardWrite& WriteObject) override;
	virtual bool FlushLeaderboards(const FName& SessionName) override;
	virtual bool WriteOnlinePlayerRatings(const FName& SessionName, int32 LeaderboardId, const TArray<FOnlinePlayerScore>& PlayerScores) override;

private:
	/** Pointer to owning subsystem */
	FOnlineSubsystemGooglePlay* Subsystem;

	/**
	 * Helper function to get the platform- and game-specific leaderboard ID from the JSON config file.
	 *
	 * @param LeaderboardName the cross-platform name of the leaderboard to look up
	 * @return The unique ID for the leaderboard as specified in the config file.
	*/
	FString GetLeaderboardID(const FString& LeaderboardName);

	/** Scores are cached here in WriteLeaderboards until FlushLeaderboards is called */
	TArray<FOnlinePendingLeaderboardWrite> UnreportedScores;
};

typedef TSharedPtr<FOnlineLeaderboardsGooglePlay, ESPMode::ThreadSafe> FOnlineLeaderboardsGooglePlayPtr;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         /****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Quick Controls module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Private 1.0

Style {
    property Component panel: StyleItem {
        id: styleitem
        elementType: "button"
        sunken: control.pressed || (control.checkable && control.checked)
        raised: !(control.pressed || (control.checkable && control.checked))
        hover: control.hovered
        text: control.iconSource === "" ? "" : control.text
        hasFocus: control.activeFocus
        hints: control.styleHints
        // If no icon, let the style do the drawing
        activeControl: control.isDefault ? "default" : "f"

        properties: {
            "icon": control.__iconAction.__icon,
            "menu": control.menu
        }
    }
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        qv4cdata   
                                                 '      ?     ?       ?      ?       ?       ?                   ?      ?      ?      x  ?    h  q                      D             H       H      *                                                      p      $            H       X       0                                          ?	      +            H       L       <                                     ?
      ?            H       P       4                                          +            H       L       8                                     @      5            H       X       *                                              L  t  ?  ?  ?  ?  $  <  D  T  d  t  ?  ?  ?  ?  ?  ?               u n d e r l i n e A m p e r s a n d s          s t y l i z e M n e m o n i c s        r e p l a c e A m p e r s a n d s      r e m o v e M n e m o n i c s          r e m o v e A m p e r s a n d s        c o n c a t    ( [ ^ & ] * ) & ( . ) ( [ ^ & ] * )    r e p l a c e          &      < u >          < / u >        % e n t r y    m a t c h      p 1    p 2    p 3    t e x t        r e p l a c e F u n c t i o n          x 8 6 _ 6 4 - l i t t l e _ e n d i a n - l p 6 4      j i t           UH??H??PL?e?L?m?L?u?I?      ??I??M?fH?        A?
   I?$I??A???????M?fH?? A?   H?        L??A??8  H?? E?VE????  H?? A?   H?        L??A??8  H?? E?VE????  H?? A?   H?        L??A??8  H?? E?VE???Z  H?? A?   H?        L??A??8  H?? E?VE???*  H?? A?   H?        L??A??8  H?? E?VE????  H?? H?        ?   L??A??0  H?? E?VE????  I?D$?H?? M?D$??   L??A???   H?? E?VE????  H?? H?        ?   L??A??0  H?? E?VE???m  I?D$?H?? M?D$??   L??A???   H?? E?VE???>  H?? H?        ?   L??A??0  H?? E?VE???  I?D$?H?? M?D$??   L??A???   H?? E?VE????   H?? H?        ?   L??A??0  H?? E?VE????   I?D$?H?? M?D$??   L??A???   H?? E?VE????   H?? H?        ?   L??A??0  H?? E?VE???S   I?D$?H?? M?D$??   L??A???   H?? E?VE???$   H?        I??PM?fL?u?L?m?L?e?H??P]?H?        ?????            UH??H??PL?e?L?m?L?u?I?      ??I??M?fH?        A?   I?$I??A???????M?fM?M?R?AB?AD$?M?M?R?AB ?AD$?M?M?R?AB(?AD$?M?A?B01   A?D$?   A?D$?   I?D$?I?D$??AD$??AD$??AD$??AD$?H?? M?D$??   L??A?V@H?? E?VE???$   I?D$?I?D$?I??`M?fL?u?L?m?L?e?H??P]?H?        ?????            UH??H??PL?e?L?m?L?u?I?      ??I??M?fH?        A?   I?$I??A???????M?fM?M?R?AB?AD$?M?A?B0=   H?? ?   L??A???   H?? E?VE????   I?D$?A?D$?   A?D$?   I?        M?\$??AD$??AD$??AD$??AD$?H?? M?D$??   L??A?V(H?? E?VE???$   I?D$?I?D$?I??XM?fL?u?L?m?L?e?H??P]?H?        ?????     UH??H??PL?e?L?m?L?u?I?      ??I??M?fH?        A?   I?$I??A???????M?fM?M?R?AB?AD$?M?M?R?AB?AD$?H?? H?        L??A??`  H?? E?VE????   I?D$?M?A?B05   A?D$?   A?D$?   I?D$?I?D$??AD$??AD$??AD$??AD$?H?? M?D$??   L??A?V@H?? E?VE???$   I?D$?I?D$?I??`M?fL?u?L?m?L?e?H??P]?H?        ????? UH??H??PL?e?L?m?L?u?I?      ??I??M?fH?        A?   I?$I??A???????M?fM?M?R?AB?AD$?M?A?B09   H?? ?   L??A???   H?? E?VE????   I?D$?A?D$?   A?D$?   I?        M?\$??AD$??AD$??AD$??AD$?H?? M?D$??   L??A?V(H?? E?VE???$   I?D$?I?D$?I??XM?fL?u?L?m?L?e?H??P]?H?        ?????     UH??H??PL?e?L?m?L?u?I?      ??I??M?fH?        A?   I?$I??A???????M?fM?M?R?AB?AD$?M?M?R?AB ?AD$?M?M?R?AB(?AD$?M?M?R(I?H?@HI?D$?M?A?B0+   H?? I?T$?I?L$?A???  H?? E?VE???Z  ????   M?A?B0,   A?D$?   A?D$?   I?D$?I?D$??AD$??AD$??AD$??AD$?H?? M?D$??   L??A?V@H?? E?VE????   I?D$??AD$??AD$???   M?M?R(I?H?@PI?D$?M?M?R(I?H?@XI?D$?M?A?B0-   A?D$?   A?D$?   I?D$?I?D$??AD$??AD$??AD$??AD$??AD$??AD$??AD$??AD$?H?? M?D$??   L??A?V@H?? E?VE???$   I?D$?I?D$?I??pM?fL?u?L?m?L?e?H??P]?H?        ?????                                                                                                                                           ????            ?                                        ?      ?      P?                   __text          __TEXT                  4?      ?      ?  f    ?            __literal8      __TEXT          8?      h      ??                            __literal16     __TEXT          ??      ?       P?                            __StaticInit    __TEXT           ?      ?      ??     0W ?     ?            __bss           __DATA          P?      ?                                    __ustring       __TEXT          ?      J      ??                             __const         __DATA          h?      P;      ?     ?\                   __cstring       __TEXT          ??      w      h?                             __const         __TEXT          /?             ??                              __data          __DATA          2?             ??                              __mod_init_func __DATA          @?             ??     ?|    	               __objc_imageinfo__DATA          H?             ??                             %        
     .      ?| !        ?? ?  ?? l    P       Z  Z  ?  ?                                                    ?O???{??C ?? ?`@?@  ?   ????{A??O???_??_??_?  ? @?@  ??_??C??O??{????? 9  ? ?? ?	  ?)@?
  ?J ??#?  ? ?	  ?) ??+ ?!	 ?   ?   ?  ?s ?  ?c  ?  ??  ??2? ?R ?r?? ??   ?`@??{D??OC??C??_?  ? @?@  ??_??C??O??{????? 9  ? ?? ?	  ?)@?
  ?J ??#?  ? ?	  ?) ??+ ?!	 ?   ?   ?  ?s ?  ?c  ?  ??  ??2? ?R ?r?? ??   ?`@??{D??OC??C??_?? 2?9?_?? 2?9?_?  ? @?@  ??_??O???{??C ?  ?s ?  ?!  ???   ?`@??{A??O???_?  ? @?@  ??_??C??O??{????? 9  ? ?? ?	  ?)@?
  ?J ??#?  ? ?	  ?) ??+ ?!	 ?   ?   ?  ?s ?  ?c  ?  ??  ??2? ?R ?r?? ??   ?`@??{D??OC??C??_?? ? @???     ???_?   ?{??? ?   ?  ? ?A ?  ?|?|?|??{???_??{??? ?   ?  ? ?A ?  ?|?|?|??{???_??O???{??C ??C?? ?  ?@?@????? ?   ?? ???   ?? ?   ???^?	  ?)@?)@????  T?C??{A??O???_?   ??_??O???{??C ?  ?`@??  ??{A??O???_?   ?? ?   ?   ?  ?B  ?   ?` ??{A??O???_? ??R???r?_?  ? @?@  ??_??O???{??C ?  ?s ?  ?!  ???   ?`@??{A??O???_??O???{??C ?  ?`@??  ??{A??O???_?   ?? ?   ?   ?  ?B  ????R??r?R   ?` ??{A??O???_?  ? @?@  ??_??O???{??C ?  ?s ?  ?!  ???   ?`@??{A??O???_????R ??r?_??{??? ??2   ?  ? @?  ?  ? ?A ?  ??{???_?  ? @?@  ??_??O???{??C ?  ?s ?  ?!  ???   ?`@??{A??O???_??O???{??C ?  ?`@??  ??{A??O???_?   ?? ?   ?   ?  ?B  ??#?RD??r?2   ?` ??{A??O???_??#?R@??r?_??{??? ??2   ?  ? @?  ?  ? ?A ?  ??{???_?  ? @?@  ??_??O???{??C ?  ?s ?  ?!  ???   ?`@??{A??O???_??O???{??C ?  ?`@??  ??{A??O???_?   ?? ?   ?   ?  ?B  ?$??R??r?2   ?` ??{A??O???_? ??R??r?_??{??? ??2   ?  ? @?  ?  ? ?A ?  ??{???_??_??O???{??C ?  ?`@??  ??{A??O???_?   ?? ?   ?   ?  ?B  ?   ?` ??{A??O???_??i?R???r?_?  ? @?@  ??_??O???{??C ?  ?s ?  ?!  ???   ?`@??{A??O???_??O???{??C ?  ?`@??  ??{A??O???_?   ?? ?   ?   ?  ?B  ?   ?` ??{A??O???_?`??R`y?r?_?  ? @?@  ??_??O???{??C ?  ?s ?  ?!  ???   ?`@??{A??O???_??O???{??C ?  ?`@??  ??{A??O???_?   ?? ?   ?   ?  ?B  ?do?R???r??R   ?` ??{A??O???_?  ? @?@  ??_??O???{??C ?  ?s ?  ?!  ???   ?`@??{A??O???_?`o?R???r?_??{??? ??2   ?  ? @?  ?  ? ?A ?  ??{???_?? 2 9?_?? 2  9?_??O???{??C ?  ?`@??  ??{A??O???_?   ?? ?   ?   ?  ?B  ???R?;?r?2   ?` ??{A??O???_?  ? @?@  ??_??O???{??C ?  ?s ?  ?!  ???   ?`@??{A??O???_???R?;?r?_??{??? ??2   ?  ? @?  ?  ? ?A ?  ??{???_?? 2?9?_?? 2?9?_?? 28 9?_?4@9 24 9?_?? 20 9?_??O???{??C ?  ?`@??  ??{A??O???_?   ?? ?   ?   ?  ?B  ?$?RD??r?2   ?` ??{A??O???_?  ? @?@  ??_??O???{??C ?  ?s ?  ?!  ???   ?`@??{A??O???_?