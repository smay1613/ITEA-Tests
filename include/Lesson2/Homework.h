#pragma once
#include <string>

bool isExpressionValid(const std::string& expression);

struct node
{
    node() = default;
    node (int _n)
        : n(_n)
    {}
    node (int _n, node *_left, node *_right)
        : n(_n),
          left(_left),
          right(_right)
    {}
    int n = 0;
    int& value {n};
    struct node *left = nullptr;
    struct node *right = nullptr;
    struct node *level = nullptr;
};

void linkLevelNodes(node* root);
