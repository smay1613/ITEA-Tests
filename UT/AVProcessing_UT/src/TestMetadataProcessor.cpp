#include "TestMetadataProcessor.h"
#include "gmock/gmock.h"
#include "Utils.h"

using namespace avprocessing;

MATCHER(MetadataIsEmpty, "")
{
    return arg.artist == ""
           && arg.album == ""
           && arg.genre == ""
           && arg.title == ""
           && arg.indexInAlbum == 0u
           && arg.length == std::chrono::milliseconds {0};
}

MATCHER(InternalMetadataIsEmpty, "")
{
    return arg.codec == ""
            && arg.bitrate == 0u;
}

MATCHER(ImageDataIsEmpty, "")
{
    return arg.albumArtImageBuffer.empty();
}

INSTANTIATE_TEST_CASE_P(IncorrectFilePath,
                        InvalidFileTest,
                        ::testing::Values("", "nonexistent", TESTDATA_PATH + std::string {"empty.ogg"}));

TEST_F(EmptyFilePathStatusTest, MetadataStatus)
{
    avtypes::MetadataDiscoverStatus status {processor->process(internalMetadata)};
    EXPECT_EQ(status, avtypes::MetadataDiscoverStatus::INVALID_URI);
}

TEST_F(EmptyFilePathStatusTest, ImageStatus)
{
    avtypes::MetadataDiscoverStatus status {processor->process(image)};
    EXPECT_EQ(status, avtypes::MetadataDiscoverStatus::INVALID_URI);
}

TEST_F(EmptyFilePathStatusTest, InternalMetadataStatus)
{
    avtypes::MetadataDiscoverStatus status {processor->process(internalMetadata)};
    EXPECT_EQ(status, avtypes::MetadataDiscoverStatus::INVALID_URI);
}

TEST_F(NonexistentFilePathStatusTest, NonexistentFilePathMetadataStatus)
{
    avtypes::MetadataDiscoverStatus status {processor->process(internalMetadata)};
    EXPECT_EQ(status, avtypes::MetadataDiscoverStatus::ERROR_FAIL);
}

TEST_F(NonexistentFilePathStatusTest, NonexistentFilePathImageStatus)
{
    avtypes::MetadataDiscoverStatus status {processor->process(image)};
    EXPECT_EQ(status, avtypes::MetadataDiscoverStatus::ERROR_FAIL);
}

TEST_F(NonexistentFilePathStatusTest, NonexistentFilePathInternalMetadataStatus)
{
    avtypes::MetadataDiscoverStatus status {processor->process(internalMetadata)};
    EXPECT_EQ(status, avtypes::MetadataDiscoverStatus::ERROR_FAIL);
}

TEST_P(InvalidFileTest, EmptyMetadata)
{
    SetUp(GetParam());
    processor->process(metadata);
    EXPECT_THAT(metadata, MetadataIsEmpty());
}

TEST_P(InvalidFileTest, EmptyInternalMetadata)
{
    SetUp(GetParam());
    processor->process(internalMetadata);
    EXPECT_THAT(internalMetadata, InternalMetadataIsEmpty());
}

TEST_P(InvalidFileTest, EmptyImage)
{
    SetUp(GetParam());
    processor->process(image);
    EXPECT_THAT(image, ImageDataIsEmpty());
}

TEST_F(PlainMetadataTest, FileWithoutTitle)
{
    SetUp(TESTDATA_PATH + std::string {"without_title.mp3"});
    processor->process(metadata);

    EXPECT_EQ(metadata.title, "without_title");
}

TEST_F(PlainMetadataTest, FileWithoutAlbumMetadata)
{
    SetUp(TESTDATA_PATH + std::string {"without_album.mp3"});
    processor->process(metadata);
    EXPECT_EQ(metadata.album, "testdata");
}

TEST_F(PlainMetadataTest, FileWithFullMetadata)
{
    SetUp (TESTDATA_PATH + std::string {"full_metadata.mp3"});

    processor->process(metadata);

    EXPECT_EQ(metadata.title, "Sweet Victory");
    EXPECT_EQ(metadata.artist, "SpongeBob SquarePants");
    EXPECT_EQ(metadata.album, "Vietnam flashbacks");
    EXPECT_EQ(metadata.genre, "Heavy Metal");
    EXPECT_EQ(metadata.indexInAlbum, 2u);
    EXPECT_EQ(metadata.length, std::chrono::milliseconds {31u * 1000u});
}

static const std::string codecsTest {TESTDATA_PATH + std::string {"/testcodecs/"}};

INSTANTIATE_TEST_CASE_P(CodecNameExtraction,
                        CodecNameTest,
                        ::testing::Values("APE.ape", "Mod.mod", "MPEG.mp3", "Ogg::Vorbis.ogg", "S3M.s3m", "XM.xm", "ASF AAC.ASF",
                                          "FLAC.FLAC", "MP4 AAC.m4a", "Ogg::Opus.opus", "RIFF::AIFF.aif", "TrueAudio.tta", "MP4 ALAC.m4a",
                                          "IT.it", "MPC.mpc", "Ogg::Speex.spx", "RIFF::WAV Unknown.wav", "WavPack.wv", ".xx"));

TEST_P(CodecNameTest, CodecNameData)
{
    SetUp(codecsTest + GetParam());
    processor->process(internalMetadata);
    EXPECT_EQ(internalMetadata.codec, utilities::getFileName(GetParam()));
}

TEST_F(BitrateTest, Bitrate)
{
    SetUp(TESTDATA_PATH + std::string {"full_metadata.mp3"});
    processor->process(internalMetadata);
    EXPECT_EQ(internalMetadata.bitrate, 32u);
}

TEST_F(CoverArtImageTest, WithCoverartData)
{
    SetUp(TESTDATA_PATH + std::string {"with_image.mp3"});
    processor->process(image);
    EXPECT_TRUE(image.albumArtImageBuffer.size() > 0);
}

TEST_F(CoverArtImageTest, WithoutCoverartData)
{
    SetUp(TESTDATA_PATH + std::string {"without_image.mp3"});
    processor->process(image);
    EXPECT_EQ(image.albumArtImageBuffer.size(), 0);
}

TEST_F(CoverArtImageTest, WithCoverartStatus)
{
    SetUp(TESTDATA_PATH + std::string {"with_image.mp3"});
    avtypes::MetadataDiscoverStatus status = processor->process(image);
    EXPECT_EQ(status, avtypes::MetadataDiscoverStatus::SUCCESS);
}

TEST_F(CoverArtImageTest, WithoutCoverartStatus)
{
    SetUp(TESTDATA_PATH + std::string {"without_image.mp3"});
    avtypes::MetadataDiscoverStatus status = processor->process(image);
    EXPECT_EQ(status, avtypes::MetadataDiscoverStatus::ERROR_FAIL);
}

static const std::string coverArtTest {TESTDATA_PATH + std::string {"/testcoverart/"}};

// TODO: Add WAV when taglib will be updated.
INSTANTIATE_TEST_CASE_P(NotEmptyImageExtraction,
                        FormatsCoverArtImageTest,
                        ::testing::Values("ASF_TwoPics.ASF", "FLAC_Vorbis.flac",
                                          "MP4_AAC_CoverFront.m4a", "MP4_ALAC_CoverBack.m4a",
                                          "MPEG_APETag.mp3", "MPEG_ID3v2Tag.mp3", "RIFF::WAV_ID3v2.wav"));

TEST_P(FormatsCoverArtImageTest, NotEmptyCoverArt)
{
    SetUp(coverArtTest + GetParam());
    processor->process(image);
    EXPECT_FALSE(image.albumArtImageBuffer.empty());
}

INSTANTIATE_TEST_CASE_P(NotEmptyImageExtraction,
                        FormatsEmptyCoverArtImageTest,
                        ::testing::Values("MPEG_APETag_NotFront.mp3",
                                          "ASF_CorruptedImage.ASF"));

TEST_P(FormatsEmptyCoverArtImageTest, NotEmptyCoverArt)
{
    SetUp(coverArtTest + GetParam());
    processor->process(image);
    EXPECT_THAT(image, ImageDataIsEmpty());
}