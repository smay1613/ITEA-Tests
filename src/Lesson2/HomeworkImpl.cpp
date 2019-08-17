#include "Homework.h"
#include <queue>
#include <stack>



void linkLevelNodes(node* root)
{
    std::queue<node *> level;
        level.push(root);
        while (!level.empty()) {
            std::queue<node *> nextLevel;
            node* nodePointer = level.front();
            level.pop();
            if (nodePointer->left != nullptr) {
                nextLevel.push(nodePointer->left);
            }
            if (nodePointer->right != nullptr) {
                nextLevel.push(nodePointer->right);
            }

             while (!level.empty()) {
                nodePointer->level = level.front();
                nodePointer = nodePointer->level;
                if (nodePointer->left != nullptr) {
                    nextLevel.push(nodePointer->left);
                }
                if (nodePointer->right != nullptr) {
                    nextLevel.push(nodePointer->right);
                }
                level.pop();
            }
            nodePointer->level = nullptr;

             while (!nextLevel.empty()) {
                level.push(nextLevel.front());
                nextLevel.pop();
            }
        }
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

