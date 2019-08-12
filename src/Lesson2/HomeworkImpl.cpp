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

void linkLevelnodes(node* root)
{
    if(!root){
        return;
    }

    std::queue<node*> binary_tree;
    binary_tree.push(root);
    binary_tree.push(nullptr);
    while(!binary_tree.empty())
    {
        node* tmp = binary_tree.front();
        binary_tree.pop();
        tmp->level = binary_tree.front();

        if(tmp->left)
        {
            binary_tree.push(tmp->left);
        }

        if(tmp->right)
        {
            binary_tree.push(tmp->right);
        }

        if(!binary_tree.front())
        {
            binary_tree.pop();

            if(!binary_tree.empty())
            {
                binary_tree.push(nullptr);
            }
        }
    }
}

bool isExpressionValid(const std::string &expression)
{
    std::stack<char> result {};
    for (size_t i = 0; i < expression.length(); ++i)
    {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
        {
            result.push(expression[i]);
        }
        else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}')
        {
            if
                    (
                     result.empty()
                     ||((expression[i] == ')') ^ (result.top() == '('))
                     ||((expression[i] == '}') ^ (result.top() == '{'))
                     ||((expression[i] == ']') ^ (result.top() == '['))
                     )
            {
                return false;
            }
            result.pop();
        }
    }
    return result.empty();
}

