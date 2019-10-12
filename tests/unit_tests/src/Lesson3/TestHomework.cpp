#include "TestHomework.h"
#include "Homework.h"
#include <gmock/gmock-matchers.h>

TEST(Set_Tests, Test_1)
{
    std::string text = "Hello world, hello cpp!";
    std::vector<std::string> a = getUniqueWords(text);
    std::vector<std::string> b {"cpp", "world", "Hello"};

    EXPECT_EQ(std::equal(a.begin(), a.end(), b.begin()), true);
}

TEST(Set_Tests, Test_2)
{
    std::string text = "or or!= do) dO ant !Ant";
    std::vector<std::string> a = getUniqueWords(text);
    std::vector<std::string> b {"ant", "do", "or"};

    EXPECT_EQ(a.size(), b.size());
}

TEST(Set_Tests, Test_3)
{
    std::string text = "and and and aNd";
    std::vector<std::string> a = getUniqueWords(text);
    std::vector<std::string> b {"and"};

    EXPECT_EQ(std::equal(a.begin(), a.end(), b.begin()), true);
}

TEST(Set_Tests, Test_4)
{
    std::string text = "hot hoW %to Tp To& trade? tRaDE+";
    std::vector<std::string> a = getUniqueWords(text);
    std::vector<std::string> b (5);

    EXPECT_EQ(a.size(), b.size());
}

TEST(Set_Tests, Test_5)
{
    std::string text = "inktober, InKtObEr! INKtoBer+)))) InktOBER+@ ^%InkTobeR";
    std::vector<std::string> a = getUniqueWords(text);
    std::vector<std::string> b {"inktober"};

    EXPECT_EQ(std::equal(a.begin(), a.end(), b.begin()), true);
}

TEST(Map_Tests, Test_1)
{
    std::string text = "Hello world, hello cpp!";
    std::vector<std::pair<std::string, size_t>> a = wordCounter(text);
    std::vector<std::pair<std::string, size_t>> b {{"cpp", 1}, {"world", 1}, {"Hello", 2}};

    EXPECT_EQ(std::equal(a.begin(), a.end(), b.begin()), true);
}

TEST(Map_Tests, Test_2)
{
    std::string text = "or or!= do) dO ant !Ant";
    std::vector<std::pair<std::string, size_t>> a = wordCounter(text);
    std::vector<std::pair<std::string, size_t>> b {{"ant", 2}, {"do", 2}, {"or", 2}};

    EXPECT_EQ(std::equal(a.begin(), a.end(), b.begin()), true);
}

TEST(Map_Tests, Test_3)
{
    std::string text = "and and and aNd";
    std::vector<std::pair<std::string, size_t>> a = wordCounter(text);
    std::vector<std::pair<std::string, size_t>> b {{"and", 4}};

    EXPECT_EQ(std::equal(a.begin(), a.end(), b.begin()), true);
}

TEST(Map_Tests, Test_4)
{
    std::string text = "hot hoW %to Tp To& trade? tRaDE+";
    std::vector<std::pair<std::string, size_t>> a = wordCounter(text);
    std::vector<std::pair<std::string, size_t>> b {{"trade", 2}, {"Tp", 1}, {"to", 2}, {"hoW", 1}, {"hot", 1}};

    EXPECT_EQ(std::equal(a.begin(), a.end(), b.begin()), true);
}

TEST(Map_Tests, Test_5)
{
    std::string text = "inktober, InKtObEr! INKtoBer+)))) InktOBER+@ ^%InkTobeR";
    std::vector<std::pair<std::string, size_t>> a = wordCounter(text);
    std::vector<std::pair<std::string, size_t>> b {{"inktober", 5}};

    EXPECT_EQ(std::equal(a.begin(), a.end(), b.begin()), true);
}

TEST(Test1, getUniqueWords) {
std::string test_string {"Hello world, Hello cpp!"};
std::vector<std::string> result{getUniqueWords(test_string)};
std::set<std::string> setOfWords {"hello","cpp","world"};
std::vector<std::string> for_compare {setOfWords.begin(),setOfWords.end()};
EXPECT_EQ(result, for_compare);
}

TEST(Test2, getUniqueWords) {
std::string test_string {"My. friend, ,IS! my FRIEND MY!"};
std::vector<std::string> result{getUniqueWords(test_string)};
std::set<std::string> setOfWords {"my","friend","is"};
std::vector<std::string> for_compare {setOfWords.begin(),setOfWords.end()};
EXPECT_EQ(result, for_compare);
}

TEST(Test3, getUniqueWords) {
std::string test_string {"Who is it??? It is joke."};
std::vector<std::string> result{getUniqueWords(test_string)};
std::set<std::string> setOfWords {"who","is","it","joke"};
std::vector<std::string> for_compare {setOfWords.begin(),setOfWords.end()};
EXPECT_EQ(result, for_compare);
}

TEST(Test4, getUniqueWords) {
std::string test_string {"Who is it? ...  It is joke. joke"};
std::vector<std::string> result{getUniqueWords(test_string)};
std::set<std::string> setOfWords {"who","is","it","joke"};
std::vector<std::string> for_compare {setOfWords.begin(),setOfWords.end()};
EXPECT_EQ(result, for_compare);
}

TEST(Test5, getUniqueWords) {
std::string test_string {"  some   WORDS for  SOME words  FOR  some JoKe"};
std::vector<std::string> result{getUniqueWords(test_string)};
std::set<std::string> setOfWords {"some","words","for","joke"};
std::vector<std::string> for_compare {setOfWords.begin(),setOfWords.end()};
EXPECT_EQ(result, for_compare);
}

TEST(Test1, wordCounter) {
std::string test_string {"Hello world, Hello cpp!"};
std::vector<std::pair<std::string, size_t>> result{wordCounter(test_string)};
std::map<std::string, size_t> setOfWords {{"hello", 2},
                                        {"world", 1},
                                        {"cpp", 1}};
std::vector<std::pair<std::string, size_t>> for_compare {setOfWords.begin(),setOfWords.end()};
EXPECT_EQ(result, for_compare);
}

TEST(Test2, wordCounter) {
std::string test_string {"My. friend, ,IS! my FRIEND MY!"};
std::vector<std::pair<std::string, size_t>> result{wordCounter(test_string)};
std::map<std::string, size_t> setOfWords {{"my", 3},
                                        {"friend", 2},
                                        {"is", 1}};
std::vector<std::pair<std::string, size_t>> for_compare {setOfWords.begin(),setOfWords.end()};
EXPECT_EQ(result, for_compare);
}

TEST(Test3, wordCounter) {
std::string test_string {"Who is it? It is joke."};
std::vector<std::pair<std::string, size_t>> result{wordCounter(test_string)};
std::map<std::string, size_t> setOfWords {{"who", 1},
                                        {"is", 2},
                                        {"it", 2},
                                        {"joke", 1}};
std::vector<std::pair<std::string, size_t>> for_compare {setOfWords.begin(),setOfWords.end()};
EXPECT_EQ(result, for_compare);
}

TEST(Test4, wordCounter) {
std::string test_string {"Who is it? ...  It is joke."};
std::vector<std::pair<std::string, size_t>> result{wordCounter(test_string)};
std::map<std::string, size_t> setOfWords {{"who", 1},
                                        {"is", 2},
                                        {"it", 2},
                                        {"joke", 1}};
std::vector<std::pair<std::string, size_t>> for_compare {setOfWords.begin(),setOfWords.end()};
EXPECT_EQ(result, for_compare);
}

TEST(Test5, wordCounter) {
std::string test_string {"  some   WORDS for  SOME words  FOR  some JoKe"};
std::vector<std::pair<std::string, size_t>> result{wordCounter(test_string)};
std::map<std::string, size_t> setOfWords {{"some", 3},
                                        {"words", 2},
                                        {"for", 2},
                                        {"joke", 1}};
std::vector<std::pair<std::string, size_t>> for_compare {setOfWords.begin(),setOfWords.end()};
EXPECT_EQ(result, for_compare);
}

TEST(getUniqueWords, Test1)
{
    std::string InpStr {"hi Hi   *h Lol"};
    std::vector<std::string> OutVector{"hi", "h", "lol"};
    std::vector<std::string> vectFromFunk = getUniqueWords(InpStr);
    EXPECT_EQ(OutVector, getUniqueWords(InpStr));
}

TEST(getUniqueWords, Test2)
{
    std::string InpStr {" "};
    std::vector<std::string> OutVector{};
    EXPECT_EQ(OutVector, getUniqueWords(InpStr));
}

TEST(getUniqueWords, Test3)
{
    std::string InpStr {"//////*0 i"};
    std::vector<std::string> OutVector{"0" , "i"};
    EXPECT_EQ(OutVector, getUniqueWords(InpStr));
}

TEST(getUniqueWords, Test4)
{
    std::string InpStr {"b B    * b"};
    std::vector<std::string> OutVector{"b"};
    EXPECT_EQ(OutVector, getUniqueWords(InpStr));
}

TEST(getUniqueWords, Test5)
{
    std::string InpStr {"*)(*^  /)"};
    std::vector<std::string> OutVector{};
    EXPECT_EQ(OutVector, getUniqueWords(InpStr));
}

TEST(wordCounter, Test1)
{
    std::string InpStr {"Goo"};
    std::vector<std::pair<std::string,size_t>> OutVector = {{"goo",1}};
    std::vector<std::pair<std::string,size_t>> vectfromFunk = wordCounter(InpStr);
    EXPECT_EQ(true,std::is_permutation(OutVector.begin(),OutVector.end(),vectfromFunk.begin()));
}

TEST(wordCounter, Test2)
{
    std::string InpStr {"Good go od  m nddd "};
    std::vector<std::pair<std::string,size_t>> OutVector = {{"good", 1},
                                                            {"go", 1},
                                                            {"od", 1},
                                                            {"m", 1},
                                                            {"nddd", 1}};
    std::vector<std::pair<std::string,size_t>> vectfromFunk = wordCounter(InpStr);
    EXPECT_EQ(true,std::is_permutation(OutVector.begin(),OutVector.end(),vectfromFunk.begin()));
}

TEST(wordCounter, Test3)
{
    std::string InpStr {"will  Will Be*)  "};
    std::vector<std::pair<std::string,size_t>> OutVector = {{"will", 2},
                                                            {"be", 1}};
    std::vector<std::pair<std::string,size_t>> vectfromFunk = wordCounter(InpStr);
    EXPECT_EQ(true,std::is_permutation(OutVector.begin(),OutVector.end(),vectfromFunk.begin()));
}

TEST(wordCounter, Test4)
{
    std::string InpStr {"will  Will  Be*) *Our,, Empl  will"};
    std::vector<std::pair<std::string,size_t>> OutVector = {{"will", 3},
                                                            {"be", 1},
                                                            {"our", 1},
                                                            {"empl", 1}};
    std::vector<std::pair<std::string,size_t>> vectfromFunk = wordCounter(InpStr);
    EXPECT_EQ(true,std::is_permutation(OutVector.begin(),OutVector.end(),vectfromFunk.begin()));
}

TEST(wordCounter, Test5)
{
    std::string InpStr {""};
    std::vector<std::pair<std::string,size_t>> OutVector = {};
    std::vector<std::pair<std::string,size_t>> vectfromFunk = wordCounter(InpStr);
    EXPECT_EQ(true,std::is_permutation(OutVector.begin(),OutVector.end(),vectfromFunk.begin()));
}

