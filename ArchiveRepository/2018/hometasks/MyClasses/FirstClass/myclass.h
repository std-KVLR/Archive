ackground.js fails content verification.
    std::string modified_contents;
    base::ReadFileToString(unzipped_path.Append(base::FilePath(kResource)),
                           &modified_contents);
    modified_contents.append("console.log('modified');");
    EXPECT_EQ(ContentVerifyJob::HASH_MISMATCH,
              RunContentVerifyJob(*extension.get(), existent_resource_path,
                                  modified_contents));
  }
}

// Tests that extension resources that are originally 0 byte behave correctly
// with content verification.
TEST_F(ContentVerifyJobUnittest, LegitimateZeroByteFile) {
  base::FilePath unzipped_path;
  base::FilePath test_dir_base =
      GetTestPath(base::FilePath(FILE_PATH_LITERAL("zero_byte_file")));
  // |extension| has a 0 byte background.js file in it.
  scoped_refptr<Extension> extension = UnzipToTempDirAndLoad(
      test_dir_base.AppendASCII("source.zip"), &unzipped_path);
  ASSERT_TRUE(extension.get());
  // Make sure there is a verified_contents.json file there as this test cannot
  // fetch it.
  EXPECT_TRUE(
      base::PathExists(file_util::GetVerifiedContentsPath(extension->path())));

  const base::FilePath::CharType kResource[] =
      FILE_PATH_LITERAL("background.js");
  base::FilePath resource_path(kResource);
  {
    // Make sure 0 byte background.js passes content verification.
    std::string contents;
    base::ReadFileToString(unzipped_path.Append(base::FilePath(kResource)),
                           &contents);
    EXPECT_EQ(ContentVerifyJ