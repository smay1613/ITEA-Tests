#pragma once
#include "gtest/gtest.h"

class FileNameExtractionTest : public ::testing::TestWithParam<std::string>
{
};

class EmptyFileNameExtractionTest : public ::testing::TestWithParam<std::string>
{
};

class EmptyFolderNameExtractionTest : public ::testing::TestWithParam<std::string>
{
};

class FolderNameExtractionTest : public ::testing::TestWithParam<std::string>
{
};

class NegativeDurationTest : public ::testing::TestWithParam<int>
{
};

class PositiveDurationTest : public ::testing::TestWithParam<int>
{
};