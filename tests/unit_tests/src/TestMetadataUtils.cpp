#include "TestMetadataUtils.h"
#include "Utils.h"
#include <forward_list>

TEST_F(listReverseTest, TrueReverse) {
  std::forward_list<int> inputList {1, 2, 3, 4};
  std::forward_list<int> expectResult {4, 3, 2, 1};
  reverse(inputList);

  EXPECT_EQ(inputList, expectResult);

}

TEST_F(listReverseTest, FalseReverse) {
  std::forward_list<int> inputList {1, 2, 3, 4};
  std::forward_list<int> expectResult {4, 3, 2, 1, 1, 2, 3 , 4};
  reverse(inputList);

  EXPECT_FALSE(inputList == expectResult);
}

TEST_F(listReverseTest, NoChanges) {
  std::forward_list<int> inputList {1, 2, 3, 4};
  reverse(inputList);
  std::forward_list<int> expectResult {1, 2, 3, 4};

  EXPECT_FALSE(inputList == expectResult);
}

TEST_F(listReverseTest, FunctionSizeBug) {
  std::forward_list<int> inputList {1, 2, 3, 4};
  reverse(inputList);
  std::forward_list<int> expectResult {4, 4, 3, 2, 1};

  EXPECT_FALSE(inputList.max_size() != expectResult.max_size());
}

TEST_F(listReverseTest, CleaningAfterCallingFunction) {
  std::forward_list<int> inputList {1, 2, 3, 4};
  reverse(inputList);

  EXPECT_TRUE(!(inputList.empty()));
}


TEST_P(MagicNumberTest, TrueCalculationResultTests) {
  const size_t number = std::get<0>(GetParam());
  const size_t degree = std::get<1>(GetParam());
  const size_t expectReluslt = std::get<2>(GetParam());
  size_t result = magicNumber(number, degree);

  EXPECT_EQ(result, expectReluslt);
}


INSTANTIATE_TEST_CASE_P(DifferentValuesTest,
                        MagicNumberTest,
                        ::testing::Values(
                                            std::make_tuple(19, 4, 19316911),
                                            std::make_tuple(10, 5, 1010101010),
                                            std::make_tuple(1, 5, 1111111111),
                                            std::make_tuple(1, 0, 0),
                                            std::make_tuple(322, 2, 3214)));


TEST_F(UnionTest, ConcatVectorTrue) {

  std::vector<int> vector1 = {1, 2, 3, 4, 5};
  std::vector<int> vector2 = {6, 7, 8, 9, 10};
  std::vector<int> result = combineVectors(vector1.begin(), vector1.end(), vector2.begin(), vector2.end());
  std::vector<int> expected_vector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  EXPECT_EQ(expected_vector, result);
}

TEST_F(UnionTest, VectorIsNotEmpty) {

  std::vector<int> vector1 {1, 2, 3, 4, 5};
  std::vector<int> vector2 {6, 7, 8, 9, 10};
  std::vector<int> result = combineVectors(vector1.begin(), vector1.end(), vector2.begin(), vector2.end());

  EXPECT_FALSE(result.empty());

}

TEST_F (UnionTest, EmptyVectors) {

  std::vector<int> vector1 {};
  std::vector<int> vector2 {};
  std::vector<int> result = combineVectors(vector1.begin(), vector1.end(), vector2.begin(), vector2.end());

  EXPECT_EQ(result.size(), 0);
}

TEST_F(UnionTest, ConcatVectorFalse) {

  std::vector<int> vector1 = {1, 2, 3, 4, 5};
  std::vector<int> vector2 = {6, 7, 8, 9, 10};
  std::vector<int> result = combineVectors(vector1.begin(), vector1.end(), vector2.begin(), vector2.end());
  std::vector<int> expected_vector = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

  EXPECT_FALSE(expected_vector == result);
}

TEST_F(UnionTest, EqualVectorsSize) {
  std::vector<int> vector1 = {1, 2, 3, 4, 5};
  std::vector<int> vector2 = {157};
  std::vector<int> result = combineVectors(vector1.begin(), vector1.end(), vector2.begin(), vector2.end());

  EXPECT_EQ((vector1.size() + vector2.size()) , result.size());
}

TEST(testCase, testSet)
{
    std::vector<int> firstVector, secondVector, resultVector;
    EXPECT_TRUE(resultVector == combineVectors(firstVector.begin(), firstVector.end(),
                                               secondVector.begin(), secondVector.end()));
}

TEST(testCase_2, testSet)
{
    std::vector<int> firstVector, secondVector, resultVector;
    secondVector = {13, 333, 4, INT32_MAX, INT32_MIN, 0};
    resultVector = secondVector;
    EXPECT_TRUE(resultVector == combineVectors(firstVector.begin(), firstVector.end(),
                                               secondVector.begin(), secondVector.end()));
}

TEST(testCase_3, testSet)
{
    std::vector<int> firstVector, secondVector, resultVector;
    firstVector = {INT32_MAX, INT32_MAX, INT32_MAX, INT32_MAX, INT32_MIN};
    secondVector = {INT32_MIN, 0, INT32_MIN, INT32_MIN, INT32_MIN, INT32_MIN, INT32_MIN};
    resultVector = {INT32_MAX, INT32_MAX, INT32_MAX, INT32_MAX, INT32_MIN, INT32_MIN, 0, INT32_MIN, INT32_MIN, INT32_MIN, INT32_MIN, INT32_MIN};
    EXPECT_TRUE(resultVector == combineVectors(firstVector.begin(), firstVector.end(),
                                               secondVector.begin(), secondVector.end()));
}

TEST(testCase_4, testSet)
{
    std::vector<int> firstVector, secondVector, resultVector;
    firstVector = {0};
    resultVector = {0};
    EXPECT_TRUE(resultVector == combineVectors(firstVector.begin(), firstVector.end(),
                                               secondVector.begin(), secondVector.end()));
}

TEST(testCase_5, testSet)
{
    std::vector<int> firstVector, secondVector, resultVector;
    firstVector = {1, 2, 3, 4, 5};
    secondVector = {6, 7, 8, 9, 0};
    resultVector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    EXPECT_TRUE(resultVector == combineVectors(firstVector.begin(), firstVector.end(),
                                               secondVector.begin(), secondVector.end()));
}

TEST(testCase_6, testSet)
{
    EXPECT_EQ(magicNumber(35, 7), 15152535456585);
}

TEST(testCase_7, testSet)
{
    EXPECT_EQ(magicNumber(1, 1), 11);
}

TEST(testCase_8, testSet)
{
    size_t result; // == 22448816326418265214
    result = 22448816326;
    result *= 1000000000;
    result += 418265214;
    EXPECT_EQ(magicNumber(2, 10), result);
}

TEST(testCase_9, testSet)
{
    EXPECT_EQ(magicNumber(0, 13), 0);
}

TEST(testCase_10, testSet)
{
    EXPECT_EQ(magicNumber(11, 6), 111111111111);
}

TEST(testCase_11, testSet)
{
    std::forward_list<int> inputList, outputList;
    reverse(inputList);
    EXPECT_EQ(inputList, outputList);
}

TEST(testCase_12, testSet)
{
    std::forward_list<int> inputList = {1, 2, 3, 4, 5}, outputList = {5, 4, 3, 2, 1};
    reverse(inputList);
    EXPECT_EQ(inputList, outputList);
}

TEST(testCase_13, testSet)
{
    std::forward_list<int> inputList = {3, 14, 15, 9, 2, 6, 5, 35, 89, 79}, outputList = {79, 89, 35, 5, 6, 2, 9, 15, 14, 3};
    reverse(inputList);
    EXPECT_EQ(inputList, outputList);
}

TEST(testCase_14, testSet)
{
    std::forward_list<int> inputList(14), outputList(14);
    reverse(inputList);
    EXPECT_EQ(inputList, outputList);
}

TEST(testCase_15, testSet)
{
    std::forward_list<int> inputList = {1}, outputList = {1};
    reverse(inputList);
    EXPECT_EQ(inputList, outputList);
}


TEST_P(reverseTest,)
{
    std::forward_list<int> list = std::get<0> (GetParam());
    reverse(list);
    std::forward_list<int> expected = std::get<1> (GetParam());
    EXPECT_EQ(list, expected);
}

INSTANTIATE_TEST_CASE_P(,reverseTest, ::testing::Values
                        (
                            std::make_tuple (std::forward_list<int> { 1 , 2 , 3 , 4 },
                                             std::forward_list<int> { 4 , 3 , 2 , 1 }),

                            std::make_tuple (std::forward_list<int> { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 },
                                             std::forward_list<int> { 8 , 7 , 6 , 5 , 4 , 3 , 2 , 1 }),

                            std::make_tuple (std::forward_list<int> { 1 , 1 , 1 , 1 , 9 },
                                             std::forward_list<int> { 9 , 1 , 1 , 1 , 1 }),

                            std::make_tuple (std::forward_list<int> { 1 , 2 , 3 , 4 },
                                             std::forward_list<int> { 4 , 3 , 2 , 1 }),

                            std::make_tuple (std::forward_list<int> { 1 , 2 , 3 , 4 },
                                             std::forward_list<int> { 4 , 3 , 2 , 1 })),

                        );

TEST_P(magic_number,)
{
    size_t N = std::get<0>(GetParam());
    size_t X = std::get<1>(GetParam());
    size_t expected = std::get<2>(GetParam());
    size_t result = magicNumber(N , X);
    EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_CASE_P(,magic_number,::testing::Values
                        (
                            std::make_tuple ( 19 , 4 , 19316911 ),
                            std::make_tuple ( 10 , 5 , 1010101010 ),
                            std::make_tuple ( 4 , 2 , 4416 ),
                            std::make_tuple ( 6 , 3 , 663626 ),
                            std::make_tuple ( 10 , 2 , 1010 ))
                        );

TEST_P(concat,)
{
    std::vector<int> vec_1 = std::get<0> (GetParam());
    std::vector<int> vec_2 = std::get<1> (GetParam());
    std::vector<int> expected = std::get<2> (GetParam());
    std::vector<int> result = combineVectors(vec_1.begin(), vec_1.end(), vec_2.begin(), vec_2.end());
    EXPECT_EQ(result, expected);
};

INSTANTIATE_TEST_CASE_P(,concat,::testing::Values
                        (
                            std::make_tuple(std::vector<int> { 1 , 2 , 3 , 4 , 5 },
                                            std::vector<int> { 6 , 7 , 8  , 9 , 10 },
                                            std::vector<int> { 1 , 2 ,  3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 }),

                            std::make_tuple(std::vector<int> { 1 , 2 , 3 },
                                            std::vector<int> { 4 , 5 , 6 },
                                            std::vector<int> { 1 , 2 ,  3 , 4 , 5 , 6 }),

                            std::make_tuple(std::vector<int> { 4 , 5 , 6 },
                                            std::vector<int> { 7 , 8 },
                                            std::vector<int> { 4 , 5 , 6 , 7 , 8 }),

                            std::make_tuple(std::vector<int> { 1, 2 , 7 , 8 , 9 , 10 },
                                            std::vector<int> {},
                                            std::vector<int> {1 , 2 , 7 , 8 , 9 , 10 }),

                            std::make_tuple(std::vector<int> {},
                                            std::vector<int> {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10},
                                            std::vector<int> {1 , 2 ,  3 , 4 , 5 , 6 , 7 , 8 , 9 , 10})
                            )
                        );


INSTANTIATE_TEST_CASE_P(Values,
                        combineVectors,
                        ::testing::Values(std::make_pair(std::vector<int>{1,2,3},        std::vector<int>{4,5,6}),
                                          std::make_pair(std::vector<int>{1,2,3,4,5,6},  std::vector<int>{}),
                                          std::make_pair(std::vector<int>{},             std::vector<int>{1,2,3,4,5,6}),
                                          std::make_pair(std::vector<int>{1},            std::vector<int>{2,3,4,5,6}),
                                          std::make_pair(std::vector<int>{1,2,3,4,5},    std::vector<int>{6})
                                          ));

TEST_P(combineVectors, combineVectors)
{
std::vector<int> firstVec = std::get<0>(GetParam());
std::vector<int> secondVec = std::get<1>(GetParam());
const std::vector<int> result {combineVectors(firstVec.begin(), firstVec.end(),
                                                                       secondVec.begin(), secondVec.end())};
EXPECT_EQ(result, (std::vector<int>{1, 2, 3, 4, 5, 6}));
}

const size_t checkResultMagicNumber[]{19316911, 1010101010, 525156535, 24, 0, 3719, 7493321171983, 0, 1};
size_t numbersMagicNumberTest {0};

INSTANTIATE_TEST_CASE_P(Values,
                        MagicNumber,
                        ::testing::Values(std::make_pair(size_t {19}, size_t{4}),
                                          std::make_pair(size_t {10}, size_t{5}),
                                          std::make_pair(size_t {5},  size_t{5}),
                                          std::make_pair(size_t {2},  size_t{2}),
                                          std::make_pair(size_t {0},  size_t{0}),
                                          std::make_pair(size_t {37}, size_t{2}),
                                          std::make_pair(size_t {7},  size_t{7}),
                                          std::make_pair(size_t {10}, size_t{0}),
                                          std::make_pair(size_t {1},  size_t{1})
                                          ));

TEST_P(MagicNumber, MagicNumber)
{
    const size_t number = std::get<0>(GetParam());
    const size_t degree = std::get<1>(GetParam());
    const size_t result {magicNumber(number, degree)};
    EXPECT_EQ(result, (checkResultMagicNumber[numbersMagicNumberTest]));
    numbersMagicNumberTest++;
}


std::vector<std::forward_list<int>>checkResultForwardListReverce{{5, 4, 3, 2, 1},
                                                                 {100, 200, 300, 400, 500},
                                                                 {},
                                                                 {1},
                                                                 {50, 50}
                                                                };
size_t numbersForwardListTest {0};

INSTANTIATE_TEST_CASE_P(ReverseForList,
                        ReverceForwardList,
                        ::testing::Values(std::forward_list<int>{1, 2, 3, 4, 5},
                                          std::forward_list<int>{500, 400, 300, 200, 100},
                                          std::forward_list<int>{},
                                          std::forward_list<int>{1},
                                          std::forward_list<int>{50,50}
                                          ));

TEST_P(ReverceForwardList, IsReversing)
{
    std::forward_list<int>forwardListToReverse{GetParam()};
    reverse(forwardListToReverse);
    EXPECT_EQ(forwardListToReverse, checkResultForwardListReverce[numbersForwardListTest]);
    numbersForwardListTest++;

}