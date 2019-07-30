#include "TestMetadataUtils.h"
#include "Utils.h"

INSTANTIATE_TEST_CASE_P(WithoutFileNameInPath,
                        EmptyFileNameExtractionTest,
                        ::testing::Values(".", "", ".mp3", "/", "//////////", "/../../../../../../../../.././"));

TEST_P(EmptyFileNameExtractionTest, DoesNotContainFileName)
{
    const std::string result {avprocessing::utilities::getFileName(GetParam())};
    EXPECT_EQ(result, "");
}

INSTANTIATE_TEST_CASE_P(WithFileNameInPath,
                        FileNameExtractionTest,
                        ::testing::Values("testing.mp3", "/just/to/be/sure/testing.mp3", "/testing", "/testing.mp3",
                                          "/../../../../../../../../.././testing.mp4",
                                          "/data/../../../../some data/foo/testing.mp4"));

TEST_P(FileNameExtractionTest, ContainsFileName)
{
    const std::string result {avprocessing::utilities::getFileName(GetParam())};
    EXPECT_EQ(result, "testing");
}

INSTANTIATE_TEST_CASE_P(WithFolderInPath,
                        FolderNameExtractionTest,
                        ::testing::Values("/test/", "/just/test/testing.mp3", "test/",
                                          "/b/test/", "/t/test/file", "a   /test/b"));

TEST_P(FolderNameExtractionTest, ContainsFolderName)
{
    const std::string result {avprocessing::utilities::getFolderName(GetParam())};
    EXPECT_EQ(result, "test");
}

INSTANTIATE_TEST_CASE_P(WithoutFolderInPath,
                        EmptyFolderNameExtractionTest,
                        ::testing::Values("/test", "//", "///",
                                          "/b///test", ""));

TEST_P(EmptyFolderNameExtractionTest, ContainsFolderName)
{
    const std::string result {avprocessing::utilities::getFolderName(GetParam())};
    EXPECT_EQ(result, "");
}

INSTANTIATE_TEST_CASE_P(NegativeSecondsValues,
                        NegativeDurationTest,
                        ::testing::Range(-5, -1));

TEST_P(NegativeDurationTest, NegativeSecondsDuration)
{
    const std::chrono::milliseconds result {avprocessing::utilities::durationToMilliseconds(GetParam())};
    EXPECT_EQ(result, std::chrono::milliseconds {0});
}

INSTANTIATE_TEST_CASE_P(PositiveSecondsValues,
                        PositiveDurationTest,
                        ::testing::Range(0, 5));

TEST_P(PositiveDurationTest, PositiveSecondsDuration)
{
    const std::chrono::milliseconds result {avprocessing::utilities::durationToMilliseconds(GetParam())};
    EXPECT_EQ(result.count(), GetParam() * 1000);
}