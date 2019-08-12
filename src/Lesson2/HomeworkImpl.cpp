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

}

bool isExpressionValid(const std::string &expression)
{
    std::vector<char> brackets {};
    for (auto &value : expression) {
        brackets.push_back(value);
    }

    bool closedBracketsCheck = false;

    if (brackets.size() != 0) {
        std::stack<char, std::vector<char>> bracketsStack {};
        int counter {};

        if (*brackets.begin() == ')' || *brackets.begin() == '}' || *brackets.begin() == ']') {
            return false;
        } else if (brackets.back() == '(' || brackets.back() == '{' || brackets.back() == '[') {
            return false;
        } else {
            for (auto &value : brackets) {
                bracketsStack.push(value);
                if (bracketsStack.top() == '(') {
                    ++counter;
                } else if (bracketsStack.top() == '{') {
                    counter += 2;
                } else if (bracketsStack.top() == '[') {
                    counter += 3;
                } else if (bracketsStack.top() == ')') {
                    --counter;
                } else if (bracketsStack.top() == '}') {
                    counter -= 2;
                } else if (bracketsStack.top() == ']') {
                    counter -= 3;
                }
            }
        }
        if (counter == 0) {
            closedBracketsCheck = true;
        } else {
            closedBracketsCheck = false;
        }
    } else {
    }
    return closedBracketsCheck;
}

