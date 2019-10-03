#include "TestHomework.h"
#include "Homework.h"
#include <forward_list>
#include <gmock/gmock-matchers.h>

 using namespace testing;

 bool isEqual(const node *node1, const node *node2)
{
    if ((node1 == nullptr) && (node2 == nullptr))
        return true;
    if ((node1 == nullptr) || (node2 == nullptr))
        return false;
    if (node1->value != node2->value)
        return false;
    return isEqual(node1->left, node2->left) && isEqual(node1->right, node2->right) && isEqual(node1->level, node2->level);
}

 TEST(testCase, testSet)
{
    //empty tree
    node *root = nullptr;
    node *resultRoot = nullptr;
    linkLevelNodes(root);
    EXPECT_TRUE(isEqual(root, resultRoot));
}

 TEST(testCase2, testSet)
{
    //tree with one node
    node *root = new node;
    root->left = root->right = root->level = nullptr;
    root->value = 0;
    node *resultRoot = new node;
    resultRoot->left = resultRoot->right = resultRoot->level = nullptr;
    resultRoot->value = 0;
    linkLevelNodes(root);
    EXPECT_TRUE(isEqual(root, resultRoot));
}

 TEST(testCase3, testSet)
{
    //binary tree                                                           1
    node *root = new node;                  //                 2                         3
    root->value = 1;                        //          4           5               6         NULL
    root->left = new node;                  //      NULL NULL   NULL NULL       NULL NULL
    root->left->value = 2;
    root->left->left = new node;
    root->left->left->value = 4;
    root->left->left->left = nullptr;
    root->left->left->right = nullptr;
    root->left->right = new node;
    root->left->right->value = 5;
    root->left->right->left = nullptr;
    root->left->right->right = nullptr;
    root->right = new node();
    root->right->value = 3;
    root->right->left = new node;
    root->right->left->value = 6;
    root->right->left->left = nullptr;
    root->right->left->right = nullptr;
    root->right->right = nullptr;

     root->level = nullptr;
    root->left->level = nullptr;
    root->right->level = nullptr;
    root->left->left->level = nullptr;
    root->left->right->level = nullptr;
    root->right->left->level = nullptr;

     node *resultRoot = new node;
    resultRoot->value = 1;
    resultRoot->left = new node;
    resultRoot->left->value = 2;
    resultRoot->left->left = new node;
    resultRoot->left->left->value = 4;
    resultRoot->left->left->left = nullptr;
    resultRoot->left->left->right = nullptr;
    resultRoot->left->right = new node;
    resultRoot->left->right->value = 5;
    resultRoot->left->right->left = nullptr;
    resultRoot->left->right->right = nullptr;
    resultRoot->right = new node();
    resultRoot->right->value = 3;
    resultRoot->right->left = new node;
    resultRoot->right->left->value = 6;
    resultRoot->right->left->left = nullptr;
    resultRoot->right->left->right = nullptr;
    resultRoot->right->right = nullptr;

     resultRoot->level = nullptr;
    resultRoot->left->level = resultRoot->right;
    resultRoot->right->level = nullptr;
    resultRoot->left->left->level = resultRoot->left->right;
    resultRoot->left->right->level = resultRoot->right->left;
    resultRoot->right->left->level = nullptr;

     linkLevelNodes(root);
    EXPECT_TRUE(isEqual(root, resultRoot));
}

 TEST(testCase4, testSet)
{
    //custom tree                                                           1
    node *root = new node;                  //                 2                         3
    root->value = 1;                        //          4          NULL           NULL          7
    root->left = new node;                  //      NULL NULL                               NULL NULL
    root->left->value = 2;
    root->left->left = new node;
    root->left->left->value = 4;
    root->left->left->left = nullptr;
    root->left->left->right = nullptr;
    root->left->right = nullptr;
    root->right = new node();
    root->right->value = 3;
    root->right->left = nullptr;
    root->right->right = new node;
    root->right->right->value = 7;
    root->right->right->left = nullptr;
    root->right->right->right = nullptr;

     root->level = nullptr;
    root->left->level = nullptr;
    root->right->level = nullptr;
    root->left->left->level = nullptr;
    root->right->right->level = nullptr;

     node *resultRoot = new node;
    resultRoot->value = 1;
    resultRoot->left = new node;
    resultRoot->left->value = 2;
    resultRoot->left->left = new node;
    resultRoot->left->left->value = 4;
    resultRoot->left->left->left = nullptr;
    resultRoot->left->left->right = nullptr;
    resultRoot->left->right = nullptr;
    resultRoot->right = new node();
    resultRoot->right->value = 3;
    resultRoot->right->left = nullptr;
    resultRoot->right->right = new node;
    resultRoot->right->right->value = 7;
    resultRoot->right->right->left = nullptr;
    resultRoot->right->right->right = nullptr;

     resultRoot->level = nullptr;
    resultRoot->left->level = resultRoot->right;
    resultRoot->right->level = nullptr;
    resultRoot->left->left->level = resultRoot->right->right;
    resultRoot->right->right->level = nullptr;

     linkLevelNodes(root);
    EXPECT_TRUE(isEqual(root, resultRoot));
}

 TEST(testCase5, testSet)
{
    node *root = new node;
    root->value = 1;
    root->left = nullptr;
    root->right = new node;
    root->right->value = 0;
    root->right->left = nullptr;
    root->right->right = nullptr;
    root->level = nullptr;

     node *resultRoot = new node;
    resultRoot->value = 1;
    resultRoot->left = nullptr;
    resultRoot->right = new node;
    resultRoot->right->value = 0;
    resultRoot->right->left = nullptr;
    resultRoot->right->right = nullptr;
    resultRoot->level = nullptr;

     linkLevelNodes(root);
    EXPECT_TRUE(isEqual(root, resultRoot));
}
 TEST(IsExpressionValid, Test1)
 {
     std::string InpStr = "[][]({})";
     EXPECT_EQ(true, isExpressionValid(InpStr));
 }

 TEST(IsExpressionValid, Test2)
 {
     std::string InpStr = "[][]({}]";
     EXPECT_EQ(false, isExpressionValid(InpStr));
 }

 TEST(IsExpressionValid, Test3)
 {
     std::string InpStr = "[()]{}{[()()]()}";
     EXPECT_EQ(true, isExpressionValid(InpStr));
 }

 TEST(IsExpressionValid, Test4)
 {
     std::string InpStr = "[)";
     EXPECT_EQ(false, isExpressionValid(InpStr));
 }

 TEST(IsExpressionValid, Test5)
 {
     std::string InpStr = "";
     EXPECT_EQ(true, isExpressionValid(InpStr));
 }


 TEST(isExpressionValidTest1, isExpressionValid) {
   EXPECT_EQ(isExpressionValid(""),true);
 }

 TEST(isExpressionValidTest2, isExpressionValid) {
   EXPECT_EQ(isExpressionValid(")([{}])("),false);
 }

 TEST(isExpressionValidTest3, isExpressionValid) {
   EXPECT_EQ(isExpressionValid("({[]}))("),false);
 }

 TEST(isExpressionValidTest4, isExpressionValid) {
   EXPECT_EQ(isExpressionValid("[]({[]})({})"),true);
 }

 TEST(isExpressionValidTest5, isExpressionValid) {
   EXPECT_EQ(isExpressionValid("(((({{{{[[[["),false);
 }


 TEST(linkLevelNodesTest1, linkLevelNodes) {
   node node7 {7, nullptr,nullptr,nullptr};
   node node6 {6, nullptr,nullptr,nullptr};
   node node5 {5, &node6 ,&node7 ,nullptr};
   node node4 {4, nullptr,nullptr,nullptr};
   node node3 {3, &node5 ,nullptr,nullptr};
   node node2 {2, &node3 , &node4,nullptr};
   node node1 {1, &node2 ,nullptr, nullptr};
   linkLevelNodes(&node1);
   EXPECT_EQ(node1.level, nullptr);
   EXPECT_EQ(node2.level, nullptr);
   EXPECT_EQ(node3.level, &node4);
   EXPECT_EQ(node4.level, nullptr);
   EXPECT_EQ(node5.level, nullptr);
   EXPECT_EQ(node6.level, &node7);
   EXPECT_EQ(node7.level, nullptr);
 }

 TEST(linkLevelNodesTest2, linkLevelNodes) {
   node node9 {9, nullptr,nullptr,nullptr};
   node node8 {8, nullptr,nullptr,nullptr};
   node node7 {7, nullptr,nullptr,nullptr};
   node node6 {6, nullptr,nullptr,nullptr};
   node node5 {5, &node8 ,&node9 ,nullptr};
   node node4 {4, &node6 ,&node7,nullptr};
   node node3 {3, &node5 ,nullptr,nullptr};
   node node2 {2, nullptr,&node4,nullptr};
   node node1 {1, &node2 ,&node3, nullptr};
   linkLevelNodes(&node1);
   EXPECT_EQ(node2.level, &node3);
   EXPECT_EQ(node4.level, &node5);
   EXPECT_EQ(node6.level, &node7);
   EXPECT_EQ(node7.level, &node8);
   EXPECT_EQ(node8.level, &node9);
   EXPECT_EQ(node2.level, &node3);
   EXPECT_EQ(node5.level, nullptr);
 }

 TEST(linkLevelNodesTest3, linkLevelNodes) {
   linkLevelNodes(nullptr);
 }

 TEST(linkLevelNodesTest4, linkLevelNodes) {
   node node5 {5, nullptr,nullptr,nullptr};
   node node4 {4, nullptr,&node5,nullptr};
   node node3 {3, nullptr,&node4,nullptr};
   node node2 {2, nullptr,&node3,nullptr};
   node node1 {1, nullptr,&node2,nullptr};
   linkLevelNodes(&node1);
   EXPECT_EQ(node1.level, nullptr);
   EXPECT_EQ(node2.level, nullptr);
   EXPECT_EQ(node3.level, nullptr);
   EXPECT_EQ(node4.level, nullptr);
   EXPECT_EQ(node5.level, nullptr);
 }

 TEST(linkLevelNodesTest5, linkLevelNodes) {
   node node6 {6, nullptr,nullptr,nullptr};
   node node5 {5, nullptr,nullptr,nullptr};
   node node4 {4, &node5,&node6,nullptr};
   node node3 {3, nullptr,&node4,nullptr};
   node node2 {2, nullptr,&node3,nullptr};
   node node1 {1, nullptr,&node2,nullptr};
   linkLevelNodes(&node1);
   EXPECT_EQ(node1.level, nullptr);
   EXPECT_EQ(node2.level, nullptr);
   EXPECT_EQ(node3.level, nullptr);
   EXPECT_EQ(node4.level, nullptr);
   EXPECT_EQ(node5.level, &node6);
   EXPECT_EQ(node6.level, nullptr);
 }

 TEST(Parentheses_Test, Test_1)
 {
     std::string input {"{{}[[()]()]{}}"};
     bool answer = isExpressionValid(input);

     EXPECT_EQ(answer, true);
 }

 TEST(Parentheses_Test, Test_2)
 {
     std::string input {""};
     bool answer = isExpressionValid(input);

     EXPECT_EQ(answer, true);
 }

 TEST(Parentheses_Test, Test_3)
 {
     std::string input {"{{}[[(]()]{}}"};
     bool answer = isExpressionValid(input);

     EXPECT_EQ(answer, false);
 }
 TEST(Parentheses_Test, Test_4)
 {
     std::string input {"{{}[[]()]{}}({])"};
     bool answer = isExpressionValid(input);

     EXPECT_EQ(answer, false);
 }
 TEST(Parentheses_Test, Test_5)
 {
     std::string input {"{{{}[[()]()]}{}}"};
     bool answer = isExpressionValid(input);

     EXPECT_EQ(answer, true);
 }

 TEST(Tree_Test, Test_1)
 {
     node a, b, c, d, e, f, g;
     a = {1, &b, &c, nullptr};
     b = {2, &d, &e, nullptr};
     c = {3, nullptr, &f, nullptr};
     d = {4, &g, nullptr, nullptr};
     e = {5, nullptr, nullptr, nullptr};
     f = {6, nullptr, nullptr, nullptr};
     g = {7, nullptr, nullptr, nullptr};
     node* tree_root = &a;
     linkLevelNodes(tree_root);

     EXPECT_EQ(a.level, nullptr);
     EXPECT_EQ(b.level, &c);
     EXPECT_EQ(c.level, nullptr);
     EXPECT_EQ(d.level, &e);
     EXPECT_EQ(e.level, &f);
     EXPECT_EQ(f.level, nullptr);
     EXPECT_EQ(g.level, nullptr);
 }