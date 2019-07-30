#pragma once
#include "gtest/gtest.h"
#include "MetadataProcessor.h"
#include "AVTypes.h"
#include <memory>

class MetadataProcessorTest : public ::testing::Test
{
protected:
    std::unique_ptr<avprocessing::MetadataProcessor> processor;

    avprocessing::avtypes::Metadata metadata {};
    avprocessing::avtypes::InternalMetadata internalMetadata {};
    avprocessing::avtypes::AlbumArtImageData image {};

    virtual void SetUp(const std::string& path)
    {
        processor.reset(new avprocessing::MetadataProcessor {path});
    }
};

class InvalidFileTest : public MetadataProcessorTest, public ::testing::WithParamInterface<std::string>
{
};

class InvalidFileStatusTest : public MetadataProcessorTest
{
};

class EmptyFilePathStatusTest : public InvalidFileStatusTest
{
    void SetUp() override
    {
        MetadataProcessorTest::SetUp("");
    }
};

class NonexistentFilePathStatusTest : public InvalidFileStatusTest
{
    void SetUp() override
    {
        MetadataProcessorTest::SetUp("nonexistent");
    }
};

class FunctionalMetadataTest : public MetadataProcessorTest
{
};

class PlainMetadataTest : public FunctionalMetadataTest
{
};

class InternalMetadataTest : public FunctionalMetadataTest
{
};

class CodecNameTest : public InternalMetadataTest, public ::testing::WithParamInterface<std::string>
{
};

class BitrateTest : public InternalMetadataTest
{
};

class CoverArtImageTest : public InternalMetadataTest
{
};

class FormatsCoverArtImageTest : public FunctionalMetadataTest, public ::testing::WithParamInterface<std::string>
{
};

class FormatsEmptyCoverArtImageTest : public FormatsCoverArtImageTest
{
};
