#include "Homework.h"
#include <stack>
#include <queue>
#include <map>

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
    if(root == nullptr)
    {
        return;
    }

    std::queue<node*> discoveredNodes;
    discoveredNodes.push(root);

    while(!discoveredNodes.empty())
    {
        node* current_node = discoveredNodes.front();
        discoveredNodes.pop();
        node* next_node = nullptr;
        if(!discoveredNodes.empty())
        {
            next_node = discoveredNodes.front();

            int nodeLevelDifference = getNodeLevel(root, current_node, 0) - getNodeLevel(root, next_node, 0);

            if(nodeLevelDifference == 0)
            {
                current_node->level = next_node;
            }
        }

        if (current_node->left != nullptr)
        {
            discoveredNodes.push(current_node->left);
        }

        if (current_node->right != nullptr)
        {
            discoveredNodes.push(current_node->right);
        }
        }
}

bool isExpressionValid(const std::string &expression)
{
    std::stack<char> receivedMessage;
    std::map<char, char> openBracketsMap {{'(', ')'}, {'[', ']'}, {'{', '}'}};
    std::map<char, char> closedBracketsMap {{')', '('}, {']', '['}, {'}', '{'}};

    for(const auto& element : expression)
    {
        if(openBracketsMap.find(element) != openBracketsMap.end())
        {
            receivedMessage.push(element);
        }
        else
        {
            if (!receivedMessage.empty() && closedBracketsMap.find(element)->second == receivedMessage.top())
            {
                receivedMessage.pop();
            }
            else
            {
                return false;
            }
        }
    }

    return receivedMessage.empty();
}

