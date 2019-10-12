#pragma once
#include <string>

bool isExpressionValid(const std::string& expression);
struct node
{
    int value;
    node *left;
    node *right;
    node *level;
};

void linkLevelNodes(node* root);
