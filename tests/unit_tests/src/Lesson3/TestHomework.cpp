#include "TestHomework.h"
#include "Homework.h"
#include <gmock/gmock-matchers.h>

using namespace testing;
bool comparator ( std::vector<std::string> lhs, std::set<std::string> rhs )
{
    if(lhs.size() != rhs.size())
        return false;
    for (auto & value_lhs: lhs){
        std::string tmp_lhs{value_lhs};
        bool stringQqual{false};
        std :: transform( tmp_lhs.begin(), tmp_lhs.end(),
                          tmp_lhs.begin(), ::tolower );
        for(auto & value_rhs: rhs){
            std::string tmp_rhs{value_rhs};
            std :: transform( tmp_rhs.begin(), tmp_rhs.end(),
                              tmp_rhs.begin(), ::tolower );
            if(tmp_lhs == tmp_rhs){
                stringQqual = true;
                break;
            }
        }
        if(stringQqual == false)
            return false;
    }
    return true;
}

bool comparatorForMap(std::vector<std::pair<std::string, size_t>>lhs, std::vector<std::pair<std::string, size_t>>rhs ){
    std::string sd{};
    if(lhs[0].first == sd && rhs[0].first == sd && lhs[0].second == rhs[0].second){
        return true;
    }
    if(lhs.size() != rhs.size())
        return false;
    for (auto & value_lhs: lhs){
        std::string tmp_lhs{value_lhs.first};
        bool stringQqual{false};
        std :: transform( tmp_lhs.begin(), tmp_lhs.end(),
                          tmp_lhs.begin(), ::tolower );
        for(auto & value_rhs: rhs){
            std::string tmp_rhs{value_rhs.first};
            std :: transform( tmp_rhs.begin(), tmp_rhs.end(),
                              tmp_rhs.begin(), ::tolower );
            if(tmp_lhs == tmp_rhs){
                if(value_lhs.second == value_rhs.second){
                    stringQqual = true;
                    break;
                }
                else
                    return false;
            }
        }
        if(stringQqual == false)
            return false;
    }
    return true;
}



INSTANTIATE_TEST_CASE_P(getUniqueWords,
                        getUniqueWordsData,
                        ::testing::Values( "Container adapters are a special type of container class.",
                                           "AAA aaa AaA aAa",
                                           "AAA sss WWW xxx aaa SSS",
                                           "",
                                           "123, 321, A, a,"
                                           ));

int numberTestResult {0};

TEST_P(getUniqueWordsData, needTrue)
{
    std::vector<std::string> result_vector = getUniqueWords(GetParam());
    EXPECT_EQ(true, comparator(result_vector, correctResult[numberTestResult++]));
}


INSTANTIATE_TEST_CASE_P(wordCounter,
                        wordCounterData,
                        ::testing::Values( "Container adapters are a special type of container class.",
                                           "AAA aaa AaA aAa",
                                           "AAA sss WWW xxx aaa SSS",
                                           "",
                                           "123, 321, A, a,"
                                           ));

int numberTestResultMap {0};

TEST_P(wordCounterData, needTrue)
{
    std::vector<std::pair<std::string, size_t>>result_vector = wordCounter(GetParam());
    EXPECT_EQ(true, comparatorForMap(result_vector, correctResult[numberTestResultMap++]));
}

TEST_P(getUniqueWordsT, testCase)
{
    std::string string = std::get<0> (GetParam());
    std::vector<std::string> result = getUniqueWords(string);
    std::vector<std::string> expected = std::get<1> (GetParam());
    EXPECT_EQ(result, expected);
};

INSTANTIATE_TEST_CASE_P(chekingText, getUniqueWordsT,::testing::Values
                        (
                            std::make_pair(std::string { "some text here some text here" },
                                           std::vector<std::string> { "here" , "some" , "text" }),

                            std::make_pair(std::string { "1 2 3" },
                                           std::vector<std::string> { "1" , "2" , "3" }),

                            std::make_pair(std::string { "" },
                                           std::vector<std::string> { "" }),

                            std::make_pair(std::string { "a b c d e e f g g" },
                                           std::vector<std::string> { "a" , "b" , "c" , "d" , "e" , "f" , "g"}),

                            std::make_pair(std::string { "run ok run ok" },
                                           std::vector<std::string> { "ok" , "run" })
                            )
                        );


TEST_F(wordCounterT, testCase_1)
{
    std::string string { "some text here some text here" };
    std::vector<std::pair<std::string, size_t>> result = wordCounter(string);
    std::vector<std::pair<std::string, size_t>> expected {{ "here", 2},{"some", 2}, {"text", 2}};
    EXPECT_EQ(result, expected);
};

TEST_F(wordCounterT, testCase_2)
{
    std::string string_2 { "1 2 3 2 2 3 1" };
    std::vector<std::pair<std::string, size_t>> result_2 = wordCounter(string_2);
    std::vector<std::pair<std::string, size_t>> expected_2 {{ "1", 2},{"2", 3}, {"3", 2}};
    EXPECT_EQ(result_2, expected_2);
};
TEST_F(wordCounterT, testCase_3)
{
    std::string string_2 { "run ok run ok" };
    std::vector<std::pair<std::string, size_t>> result_2 = wordCounter(string_2);
    std::vector<std::pair<std::string, size_t>> expected_2 {{ "ok", 2},{ "run", 2}};
    EXPECT_EQ(result_2, expected_2);
};
TEST_F(wordCounterT, testCase_4)
{
    std::string string_2 { "a b c c" };
    std::vector<std::pair<std::string, size_t>> result_2 = wordCounter(string_2);
    std::vector<std::pair<std::string, size_t>> expected_2 {{ "a", 1},{"b", 1}, {"c", 2}};
    EXPECT_EQ(result_2, expected_2);
};
TEST_F(wordCounterT, testCase_5)
{
    std::string string_2 { "test case 5 5 wordCounter" };
    std::vector<std::pair<std::string, size_t>> result_2 = wordCounter(string_2);
    std::vector<std::pair<std::string, size_t>> expected_2 {{ "5", 2},{"case", 1}, {"test", 1}, {"wordCounter", 1}};
    EXPECT_EQ(result_2, expected_2);
};

TEST_F(get_unique_words_test, 1)
{
    std::vector<std::string> result_vector = getUniqueWords(str_1);
    std::set<std::string> result_set;
    for (const auto& element : result_vector)
    {
        result_set.insert(element);
    }
    EXPECT_EQ(result_set, result_1);
}

TEST_F(get_unique_words_test, 2)
{
    std::vector<std::string> result_vector = getUniqueWords(str_2);
    std::set<std::string> result_set;
    for (const auto& element : result_vector)
    {
        result_set.insert(element);
    }
    EXPECT_EQ(result_set, result_2);
}

TEST_F(get_unique_words_test, 3)
{
    std::vector<std::string> result_vector = getUniqueWords(str_3);
    std::set<std::string> result_set;
    for (const auto& element : result_vector)
    {
        result_set.insert(element);
    }
    EXPECT_EQ(result_set, result_3);
}

TEST_F(get_unique_words_test, 4)
{
    std::vector<std::string> result_vector = getUniqueWords(str_4);
    std::set<std::string> result_set;
    for (const auto& element : result_vector)
    {
        result_set.insert(element);
    }
    EXPECT_EQ(result_set, result_4);
}

TEST_F(get_unique_words_test, 5)
{
    std::vector<std::string> result_vector = getUniqueWords(str_5);
    std::set<std::string> result_set;
    for (const auto& element : result_vector)
    {
        result_set.insert(element);
    }
    EXPECT_EQ(result_set, result_5);
}

class word_counter_test : public ::testing::Test
{
public:
    std::string str_1 = "a a a a a a a a";
    std::string str_2 = "A A A a a.";
    std::string str_3 = "d c b a";
    std::string str_4 = "";
    std::string str_5 = "test  a a a a a a a a";

    std::vector<std::pair<std::string, size_t>> result_1 {{"a", 8}};
    std::vector<std::pair<std::string, size_t>> result_2 {{"a", 5}};
    std::vector<std::pair<std::string, size_t>> result_3 {{"a", 1}, {"b", 1}, {"c", 1}, {"d", 1}};
    std::vector<std::pair<std::string, size_t>> result_4 {};
    std::vector<std::pair<std::string, size_t>> result_5 {{"a", 8}, {"test", 1}};
};

TEST_F(word_counter_test, 1)
{
    std::vector<std::pair<std::string, size_t>> result_vector = wordCounter(str_1);
    EXPECT_EQ(result_vector.size(), result_1.size());
    for (int i=0; i < result_vector.size(); i++)
    {
//        EXPECT_EQ(result_vector[i].first, result_1[i].first);
//        EXPECT_EQ(result_vector[i].second, result_1[i].second);
    }
}

TEST_F(word_counter_test, 2)
{
    std::vector<std::pair<std::string, size_t>> result_vector = wordCounter(str_2);
    EXPECT_EQ(result_vector.size(), result_2.size());
    for (int i=0; i < result_vector.size(); i++)
    {
//        EXPECT_EQ(result_vector[i].first, result_2[i].first);
//        EXPECT_EQ(result_vector[i].second, result_2[i].second);
    }
}

TEST_F(word_counter_test, 3)
{
    std::vector<std::pair<std::string, size_t>> result_vector = wordCounter(str_3);
    EXPECT_EQ(result_vector.size(), result_3.size());
    for (int i=0; i < result_vector.size(); i++)
    {
//        EXPECT_EQ(result_vector[i].first, result_3[i].first);
//        EXPECT_EQ(result_vector[i].second, result_3[i].second);
    }
}

TEST_F(word_counter_test, 4)
{
    std::vector<std::pair<std::string, size_t>> result_vector = wordCounter(str_4);
    EXPECT_EQ(result_vector.size(), result_4.size());
    for (int i=0; i < result_vector.size(); i++)
    {
//        EXPECT_EQ(result_vector[i].first, result_4[i].first);
//        EXPECT_EQ(result_vector[i].second, result_4[i].second);
    }
}

TEST_F(word_counter_test, 5)
{
    std::vector<std::pair<std::string, size_t>> result_vector = wordCounter(str_5);
    EXPECT_EQ(result_vector.size(), result_5.size());
    for (int i=0; i < result_vector.size(); i++)
    {
//        EXPECT_EQ(result_vector[i].first, result_5[i].first);
//        EXPECT_EQ(result_vector[i].second, result_5[i].second);
    }
}
