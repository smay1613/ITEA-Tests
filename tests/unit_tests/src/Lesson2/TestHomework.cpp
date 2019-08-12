#include "TestHomework.h"
#include "Homework.h"
#include <forward_list>

TEST_F(is_expression_valid_test, 1)
{
    bool result = isExpressionValid(is_expression_valid_str_1);
    EXPECT_EQ(result, is_expression_valid_result_1);
}

TEST_F(is_expression_valid_test, 2)
{
    bool result = isExpressionValid(is_expression_valid_str_2);
    EXPECT_FALSE(result != is_expression_valid_result_2);
}

TEST_F(is_expression_valid_test, 3)
{
    bool result = isExpressionValid(is_expression_valid_str_3);
    EXPECT_EQ(result, is_expression_valid_result_3);
}

TEST_F(is_expression_valid_test, 4)
{
    bool result = isExpressionValid(is_expression_valid_str_4);
    EXPECT_EQ(result, is_expression_valid_result_4);
}

TEST_F(is_expression_valid_test, 5)
{
    bool result = isExpressionValid(is_expression_valid_str_5);
    EXPECT_EQ(result, is_expression_valid_result_5);
}

INSTANTIATE_TEST_CASE_P(TrueBrackets,
                        isExpressionValidTrue,
                        ::testing::Values("()()([][]{})", "[][]", "{}{}{()()(){}[()()]}()()", "{}()[]", ""
                                          ));

TEST_P(isExpressionValidTrue, IsTrue)
{

    bool result = isExpressionValid(GetParam());
    EXPECT_EQ(result, true);
}


INSTANTIATE_TEST_CASE_P(FalseBrackets,
                        isExpressionValidFalse,
                        ::testing::Values("{}{}{}{", "()(()([][]{})" , ")(}{[]", "][", "{}}{"
                                          ));

TEST_P(isExpressionValidFalse, IsFalse)
{

    bool result = isExpressionValid(GetParam());
    EXPECT_EQ(result, false);
}

TEST_P(isExpressionValidTest, testCase)
{
    std::string string = std::get<0> (GetParam());
    bool expected = std::get<1> (GetParam());
    bool result = isExpressionValid(string);
    EXPECT_EQ(result, expected);
};

INSTANTIATE_TEST_CASE_P(chekingExpression, isExpressionValidTest,::testing::Values
                        (
                            std::make_pair(std::string { "()" },                bool {true}),
                            std::make_pair(std::string { ")(" },                bool {false}),
                            std::make_pair(std::string { "((()()())()())" },    bool {true}),
                            std::make_pair(std::string { "())(" },              bool {false}),
                            std::make_pair(std::string { "[)" },                bool {false}),
                            std::make_pair(std::string { "([])" },              bool {true}),
                            std::make_pair(std::string { "[()]{}{[()()]()}" },  bool {true})
                            )
                        );

TEST_P(AllBracketsClosed, DifferentIncome) {
  std::string inputString = std::get<0>(GetParam());
  bool expectedResult = std::get<1>(GetParam());
  EXPECT_EQ(isExpressionValid(inputString), expectedResult);
}

INSTANTIATE_TEST_CASE_P(AllClosed,
                        AllBracketsClosed,
                        ::testing::Values (std::make_tuple("()", true),
                                           std::make_tuple("())(", false),
                                           std::make_tuple("(){}[]", true),
                                           std::make_tuple("({[)}]", true),
                                           std::make_tuple("{{((()))}[]]", false)
                                           ));