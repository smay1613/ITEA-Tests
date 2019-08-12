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

}

bool isExpressionValid(const std::string &expression)
{
    std::stack <char> bracecStack{};

    for(const auto &brace : expression)
    {
        if(brace == '(' || brace == '{' || brace == '[')
        {
            bracecStack.push(brace);
        }

        if(bracecStack.empty())
        {
            return false;
        }

        if(!bracecStack.empty())
        {
            if((brace == ')' && bracecStack.top() == '(')
               || (brace == '}' && bracecStack.top() == '{')
               || (brace == ']' && bracecStack.top() == '['))
            {
                bracecStack.pop();
            }
        }
    }
    return bracecStack.empty();
}

