#pragma once
#include "gtest/gtest.h"

class getUniqueWordsData : public ::testing::TestWithParam<std::string>
{
public:
   std::vector<std::set<std::string>> correctResult {{{"Container"},{"adapters"},{"are"}, {"a"}, {"special"}, {"type"}, {"of"}, {"class."}},
                                                     {{"AaA"}},
                                                     {{"AAA"}, {"sss"}, {"www"}, {"xxx"}},
                                                     {{""}},
                                                     {{"123,"}, {"321,"}, {"A,"}}
                                                     };
};

class wordCounterData : public ::testing::TestWithParam<std::string>
{
public:
      std::vector<std::vector<std::pair<std::string, size_t>>> correctResult {{{"Container", 2},{"adapters", 1},{"are", 1}, {"a", 1}, {"special", 1}, {"type", 1}, {"of", 1}, {"class.", 1}},
                                                                              {{"AaA", 4}},
                                                                              {{"AAA", 2}, {"sss", 2}, {"www", 1}, {"xxx", 1}},
                                                                              {{}},
                                                                              {{"123,", 1}, {"321,", 1}, {"A,", 2}}};
};

class getUniqueWordsT: public ::testing::TestWithParam<std::pair<std::string, std::vector<std::string>>>
{
};

class wordCounterT : public ::testing::Test
{
};

class get_unique_words_test : public ::testing::Test
{
public:
    std::string str_1 = "The European hare is one of the";
    std::string str_2 = "Native to Europe and parts of Asia";
    std::string str_3 = "a b c d";
    std::string str_4 = "";
    std::string str_5 = "test a a a a a a a a";

    std::set<std::string> result_1 {{"the"},{"european"},{"hare"}, {"is"}, {"one"}, {"of"}};
    std::set<std::string> result_2 {{"native"},{"to"},{"europe"}, {"and"}, {"parts"}, {"of"}, {"asia"}};
    std::set<std::string> result_3 {{"a"},{"b"},{"c"}, {"d"}};
    std::set<std::string> result_4 {};
    std::set<std::string> result_5 {{"test"},{"a"}};
};
