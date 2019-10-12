#include "Homework.h"
#include <stack>
#include <queue>
#include <map>
#include <cmath>

int getNodeLevel (node* nodeToObserve, node* nodeTofind, int level)
{
    if(nodeToObserve == nullptr)
    {
        return 0;
    }
    if(nodeToObserve == nodeTofind)
    {
        return  level;
    }

    int downLevel = getNodeLevel(nodeToObserve->left, nodeTofind, level + 1);
    if(downLevel != 0)
    {
        return downLevel;
    }

    downLevel = getNodeLevel(nodeToObserve->right, nodeTofind, level + 1);
    return downLevel;

}

void linkLevelNodes(node* root)
{
    if (nullptr == root) {
       return;
     }
     std::queue<node*> ptrNode;
     ptrNode.push(root);
     size_t NextLevelNodes {0};
     size_t expectedNodes {2};
     bool isPointToNext = true;
     node* previusNodePtr = nullptr;
     while (!ptrNode.empty()) {
       node& currentNode = *(ptrNode.front());
       if (isPointToNext) {
         currentNode.level = previusNodePtr;
       }
       isPointToNext = true;
       if (currentNode.right != nullptr) {
         ptrNode.push(currentNode.right);
         ++NextLevelNodes;
       } else {
         --expectedNodes;
       }
       if (currentNode.left != nullptr) {
       ptrNode.push(currentNode.left);
         ++NextLevelNodes;
       } else {
         --expectedNodes;
       }
       if (expectedNodes == NextLevelNodes) {
         expectedNodes = pow(2, expectedNodes);
         NextLevelNodes = 0;
         isPointToNext = false;
       }
       previusNodePtr = &currentNode;
       ptrNode.pop();
     }
}

inline char OpositBracket(const char BRACKET) {
  std::map<char, char> bracketsMap {{'(',')'},{'[',']'},{'{','}'}};
  return bracketsMap.at(BRACKET);
}

bool isExpressionValid(const std::string &expression)
{
    std::stack<char> bracketsStack;
      for (char bracket : expression) {
        if (bracket == '(' ||
            bracket == '[' ||
            bracket == '{') {
          bracketsStack.push(bracket);
        } else {
          if (bracketsStack.empty()) {return false;}
          if (bracket != OpositBracket(bracketsStack.top())) {
            return false;
          }
          bracketsStack.pop();
        }
      }
      return bracketsStack.empty();
}

