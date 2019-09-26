#include "TestHomework.h"
#include "Homework.h"
#include <forward_list>

TEST(reverseTest1, reverse) {
  std::forward_list<int> test_list {1, 2, 3, 4, 5};
  std::forward_list<int> comp_list {1, 2, 3, 4, 5};
  reverse(test_list);
  comp_list.reverse();
  EXPECT_EQ(test_list,comp_list);
}

TEST(Vector_Tests, Size_Test)
{
    std::vector<int> a (2);
    std::vector<int> b (2);

    EXPECT_EQ(4, combineVectors(a.begin(), a.end(), b.begin(), b.end()).size());
}

TEST(Vector_Tests, Size_Test_Max)
{
    uint test_size = 100000000;
    std::vector<int> a (test_size);
    std::vector<int> b (test_size);

    EXPECT_EQ(2 * test_size, combineVectors(a.begin(), a.end(), b.begin(), b.end()).size());
}

TEST(Vector_Tests, Size_Test_Empty)
{
    uint test_size = 0;
    std::vector<int> a (test_size);
    std::vector<int> b (test_size);

    EXPECT_EQ(2 * test_size, combineVectors(a.begin(), a.end(), b.begin(), b.end()).size());
}

TEST(Vector_Tests, Size_Test_Half_Empty)
{
    uint test_size1 = 0;
    uint test_size2 = 25;
    std::vector<int> a (test_size1);
    std::vector<int> b (test_size2);

    EXPECT_EQ(test_size1 + test_size2, combineVectors(a.begin(), a.end(), b.begin(), b.end()).size());
}

TEST(Vector_Tests, Size_Test_Wrong)
{
    uint test_size = 35;
    std::vector<int> a (test_size);
    std::vector<int> b (test_size);

    EXPECT_EQ(2 * test_size, combineVectors(a.begin(), a.end(), b.begin(), b.end()).size());
}

TEST(MagicNumber_Tests, EQ_Test)
{
    EXPECT_EQ(19316911, magicNumber(19,4));
}

TEST(MagicNumber_Tests, Test_16_9)
{
    EXPECT_EQ(162646661616264666, magicNumber(16,9));
}

TEST(MagicNumber_Tests, Test_17_13)
{
    EXPECT_EQ(5201518695802786717, magicNumber(17,13));
}

TEST(MagicNumber_Tests, Test_Zero)
{
    EXPECT_EQ(0, magicNumber(0,13));
}

TEST(MagicNumber_Tests, Test_One)
{
    EXPECT_EQ(0, magicNumber(10,0));
}

TEST(List_Tests, Reverse_Test_1)
{
    std::forward_list<int> a {8, 4, 2};
    std::forward_list<int> b {a};
    b.reverse();
    reverse(a);
    EXPECT_EQ(b, a);
}

TEST(List_Tests, Reverse_Test_2)
{
    std::forward_list<int> a;
    for (int i = 0; i < 1000000; ++i){
        a.push_front(i);
    }
    std::forward_list<int> b {a};
    b.reverse();
    reverse(a);
    EXPECT_EQ(b, a);
}

TEST(List_Tests, Reverse_Test_Empty)
{
    std::forward_list<int> a {};
    std::forward_list<int> b {a};
    b.reverse();
    reverse(a);
    EXPECT_EQ(b, a);
}

TEST(List_Tests, Reverse_Test_One_Entry)
{
    std::forward_list<int> a {69};
    std::forward_list<int> b {a};
    b.reverse();
    reverse(a);
    EXPECT_EQ(b, a);
}

TEST(List_Tests, Reverse_Test_Ptr)
{
    /* INCORRECT TEST - Application crashed! */

//    int *p;
//    std::forward_list<int> a {*p, *(p + 1), *(p + 2)};
//    std::forward_list<int> b {a};
//    b.reverse();
//    reverse(a);
//    EXPECT_EQ(b, a);
}


TEST(combineVectors, Test1)
{
    std::vector<int> a = {};
    std::vector<int> b = {-384};
    std::vector<int> result = {-384};
    std::vector<int>::iterator b1 = a.begin();
    std::vector<int>::iterator e1 = a.end();
    std::vector<int>::iterator b2 = b.begin();
    std::vector<int>::iterator e2 = b.end();
    EXPECT_EQ(result, combineVectors(b1,e1,b2,e2));
}

TEST(combineVectors, Test2)
{
    std::vector<int> a = {};
    std::vector<int> b = {};
    std::vector<int> result = {};
    std::vector<int>::iterator b1 = a.begin();
    std::vector<int>::iterator e1 = a.end();
    std::vector<int>::iterator b2 = b.begin();
    std::vector<int>::iterator e2 = b.end();
    EXPECT_EQ(result, combineVectors(b1,e1,b2,e2));
}
TEST(combineVectors, Test3)
{
    std::vector<int> a = {4,3,6,3,656,-5};
    std::vector<int> b = {4,6,2,6};
    std::vector<int> result = {4,3,6,3,656,-5,4,6,2,6};
    std::vector<int>::iterator b1 = a.begin();
    std::vector<int>::iterator e1 = a.end();
    std::vector<int>::iterator b2 = b.begin();
    std::vector<int>::iterator e2 = b.end();
    EXPECT_EQ(result, combineVectors(b1,e1,b2,e2));
}

TEST(combineVectors, Test4)
{
    std::vector<int> a = {2,6,4};
    std::vector<int> b = {-384,574,685};
    std::vector<int> result = {2,6,4,-384,574,685};
    std::vector<int>::iterator b1 = a.begin();
    std::vector<int>::iterator e1 = a.end();
    std::vector<int>::iterator b2 = b.begin();
    std::vector<int>::iterator e2 = b.end();
    EXPECT_EQ(result, combineVectors(b1,e1,b2,e2));
}

TEST(combineVectors, Test5)
{
    std::vector<int> a = {5849,-3};
    std::vector<int> b = {};
    std::vector<int> result = {5849,-3};
    std::vector<int>::iterator b1 = a.begin();
    std::vector<int>::iterator e1 = a.end();
    std::vector<int>::iterator b2 = b.begin();
    std::vector<int>::iterator e2 = b.end();
    EXPECT_EQ(result, combineVectors(b1,e1,b2,e2));
}

TEST(magicNumber, Test1)
{
    size_t N = 10;
    size_t X = 5;
    size_t result = 1010101010;
    EXPECT_EQ(result, magicNumber(N,X));
}

TEST(magicNumber, Test2)
{
    size_t N = 19;
    size_t X = 4;
    size_t result = 19316911;
    EXPECT_EQ(result, magicNumber(N,X));
}

TEST(magicNumber, Test3)
{
    size_t N = 12;
    size_t X = 3;
    size_t result = 121418;
    EXPECT_EQ(result, magicNumber(N,X));
}

TEST(magicNumber, Test4)
{
    size_t N = 11;
    size_t X = 2;
    size_t result = 1111;
    EXPECT_EQ(result, magicNumber(N,X));
}

TEST(magicNumber, Test5)
{
    size_t N = 10;
    size_t X = 1;
    size_t result = 10;
    EXPECT_EQ(result, magicNumber(N,X));
}

TEST(reverse, Test1)
{
    std::forward_list<int> inpList = {1,2,3};
    reverse(inpList);
    std::forward_list <int> result = {3,2,1};
    EXPECT_EQ(result, inpList);
}

TEST(reverse, Test2)
{
    std::forward_list<int> inpList = {};
    reverse(inpList);
    std::forward_list <int> result = {};
    EXPECT_EQ(result, inpList);
}

TEST(reverse, Test3)
{
    std::forward_list<int> inpList = {12};
    reverse(inpList);
    std::forward_list <int> result = {12};
    EXPECT_EQ(result, inpList);
}

TEST(reverse, Test4)
{
    std::forward_list<int> inpList = {12,49,0,-6,5};
    reverse(inpList);
    std::forward_list <int> result = {5,-6,0,49,12};
    EXPECT_EQ(result, inpList);
}

TEST(reverse, Test5)
{
    std::forward_list<int> inpList = {1,0};
    reverse(inpList);
    std::forward_list <int> result = {0,1};
    EXPECT_EQ(result, inpList);
}


TEST(combineVectorsTest1, combineVectors) {
  std::vector<int> firstVect {1, 2, 3};
  std::vector<int> secondVect {1, 2, 3};
  std::vector<int> Output_for_compare {1, 2, 3, 1, 2, 3};
  std::vector<int> Output = combineVectors(firstVect.begin(),firstVect.end(),secondVect.begin(),secondVect.end());
  EXPECT_EQ(Output, Output_for_compare);
}

TEST(combineVectorsTest2, combineVectors) {
  std::vector<int> firstVect {};
  std::vector<int> secondVect {1, 2, 4};
  std::vector<int> Output_for_compare {1, 2, 4};
  std::vector<int> Output = combineVectors(firstVect.begin(),firstVect.end(),secondVect.begin(),secondVect.end());
  EXPECT_EQ(Output, Output_for_compare);
}

TEST(combineVectorsTest3, combineVectors) {
  std::vector<int> firstVect {1, 2, 4};
  std::vector<int> secondVect {};
  std::vector<int> Output_for_compare {1, 2, 4};
  std::vector<int> Output = combineVectors(firstVect.begin(),firstVect.end(),secondVect.begin(),secondVect.end());
  EXPECT_EQ(Output, Output_for_compare);
}

TEST(combineVectorsTest4, combineVectors) {
  std::vector<int> firstVect {};
  std::vector<int> secondVect {};
  std::vector<int> Output_for_compare {};
  std::vector<int> Output = combineVectors(firstVect.begin(),firstVect.end(),secondVect.begin(),secondVect.end());
  EXPECT_EQ(Output, Output_for_compare);
}

TEST(combineVectorsTest5, combineVectors) {
  std::vector<int> firstVect {};
  std::vector<int> secondVect {};
  for (int i = 0; i < 1000; ++i) {
    firstVect.push_back(i);
    secondVect.push_back(i);
  }
  std::vector<int> Output_for_compare {};
  for (uint8_t j = 0; j < 2; ++j) {
    for (int i = 0; i < 1000; ++i) {
      Output_for_compare.push_back(i);
    }
  }
  std::vector<int> Output = combineVectors(firstVect.begin(),firstVect.end(),secondVect.begin(),secondVect.end());
  EXPECT_EQ(Output, Output_for_compare);
}

TEST(magicNumberTest1, magicNumber) {
    EXPECT_EQ(magicNumber(10,5),1010101010);
}

TEST(magicNumberTest2, magicNumber) {
  EXPECT_EQ(magicNumber(19, 4), 19316911);
}

TEST(magicNumberTest3, magicNumber) {
  EXPECT_EQ(magicNumber(99, 4), 99919991);
}

TEST(magicNumberTest4, magicNumber) {
  EXPECT_EQ(magicNumber(999, 4), 99919991);
}

TEST(magicNumberTest5, magicNumber) {
  EXPECT_EQ(magicNumber(153, 2), 1329);
}
