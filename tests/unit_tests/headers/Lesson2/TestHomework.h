#pragma once
#include "gtest/gtest.h"

class is_expression_valid_test : public ::testing::Test
{
public:
    std::string is_expression_valid_str_1 = "[]";
    bool is_expression_valid_result_1 = true;

    std::string is_expression_valid_str_2 = "[)";
    bool is_expression_valid_result_2 = false;

    std::string is_expression_valid_str_3 = "sefmweokfmowefowfm";
    bool is_expression_valid_result_3 = true;

    std::string is_expression_valid_str_4 = "()[]{}({[]})";
    bool is_expression_valid_result_4 = true;

    std::string is_expression_valid_str_5 = "";
    bool is_expression_valid_result_5 = true;
};

class isExpressionValidTrue : public ::testing::TestWithParam<std::string>
{
};
class isExpressionValidFalse : public ::testing::TestWithParam<std::string>
{
};

class isExpressionValidTest : public ::testing::TestWithParam<std::pair<std::string, bool>>
{
};

class AllBracketsClosed : public ::testing::TestWithParam <std::tuple<std::string, bool>> {

};