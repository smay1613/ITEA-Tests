#pragma once
#include "gtest/gtest.h"
#include <forward_list>

class listReverseTest : public ::testing::Test {

};

class MagicNumberTest : public ::testing::TestWithParam<std::tuple<size_t,
                                                                   size_t,
                                                                   size_t>>
{
};

class UnionTest : public ::testing::Test {

};

class testSet : public ::testing::Test {

};

class magic_number : public ::testing::TestWithParam<std::tuple<size_t, size_t, size_t>>
{
};


class concat : public ::testing::TestWithParam<std::tuple<const std::vector<int>, const std::vector<int>, const std::vector<int>>>
{
};

class reverseTest : public ::testing::TestWithParam<std::tuple<std::forward_list<int>, std::forward_list<int>>>
{
};

class ReverceForwardList : public ::testing::TestWithParam<std::forward_list<int>>
{
};

class unionVectors : public ::testing::TestWithParam<std::pair<std::vector<int>, std::vector<int>>>
{
};

class MagicNumber : public ::testing::TestWithParam<std::pair<int , int>>
{
};
