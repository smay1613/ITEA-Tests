#include "Homework.h"
#include <queue>
#include <stack>

struct node
{
    node (int _n)
        : n(_n)
    {}
    node (int _n, node *_left, node *_right)
        : n(_n),
          left(_left),
          right(_right)
    {}
    int n = 0;
    struct node *left = nullptr;
    struct node *right = nullptr;
    struct node *level = nullptr;
};

void linkLevelNodes(node* root)
{
    std::queue<node *> firstLevel;
    firstLevel.push(root);
    while (!firstLevel.empty())
    {
        std::queue<node *> secondLevel;
        if (firstLevel.front()->left != nullptr)
        {
            secondLevel.push(firstLevel.front()->left);
        }
        if (firstLevel.front()->right != nullptr)
        {
            secondLevel.push(firstLevel.front()->right);
        }
        node* tmp = firstLevel.front();
        firstLevel.pop();
        while (!firstLevel.empty())
        {
            tmp->level = firstLevel.front();
            tmp = tmp->level;
            if (tmp->left != nullptr)
            {
                secondLevel.push(tmp->left);
            }
            if (tmp->right != nullptr)
            {
                secondLevel.push(tmp->right);
            }
            firstLevel.pop();
        }
        tmp->level = nullptr;
        firstLevel = secondLevel;
    }
}

char reverseRightToLeftBracketsFunction(const char m_rightBrackets){
    switch (m_rightBrackets)
    {
    case '}':
    {
        return '{';
    }
    case ')':
    {
        return '(';
    }
    case ']':
    {
        return '[';
    }
    default:
        return NULL;
    }
}

bool isExpressionValid(const std::string &expression)
{
    std::stack<char>stackOpenBrackets;
        for(const auto &value: expression){
            if(value == '{' || value == '(' || value == '[')
            {
                stackOpenBrackets.push(value);
            }
            else {
                if(stackOpenBrackets.empty()){
                    return false;
                }

                char reverseRightToLeftBrackets{reverseRightToLeftBracketsFunction(value)};

                if(stackOpenBrackets.top() != reverseRightToLeftBrackets )
                {
                    return false;
                }
                else
                {
                    stackOpenBrackets.pop();
                }
            }
        }
        if(stackOpenBrackets.empty()){
            return true;
        }
        return false;
}

