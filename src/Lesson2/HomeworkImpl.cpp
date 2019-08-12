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

void linkLevelNodes(node* element)
{
    if (element==nullptr)
    {
        return;
    }
    std::queue<node*> nodes_queue;
    node* element_level_1 = nullptr;
    node* element_level_2 = element->left;

    nodes_queue.push(element);

    while (!nodes_queue.empty())
    {
        if (nodes_queue.front()->left!=nullptr)
        {
            nodes_queue.push(nodes_queue.front()->left);
        }
        if (nodes_queue.front()->right!=nullptr)
        {
            nodes_queue.push(nodes_queue.front()->right);
        }

        if (element_level_1 == nullptr)
        {
            element_level_1 = nodes_queue.front();
        }
        else
        {
            if (nodes_queue.front() == element_level_2)
            {
                element_level_1 = nodes_queue.front();
                element_level_2 = nodes_queue.front()->left;
            }
            else
            {
                element_level_1->level = nodes_queue.front();
                element_level_1 = nodes_queue.front();
            }
        }
        nodes_queue.pop();
    }
}

struct comporator
{
    bool operator()(const node &lhs, const node &rhs)
    {
        if (lhs.n == rhs.n && lhs.left==rhs.left && lhs.right==rhs.right && lhs.level==rhs.level)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

struct bracket
{
    bracket(size_t _type) : type(_type)
    {}
    size_t type;
    size_t number = 1;
};

bool isExpressionValid(const std::string &str)
{
    std::stack<bracket> data_stack;
    if (str.empty())
    {
        return false;
    }
    else
    {
        for (const char& c : str)
        {
            switch (c)
            {
                case '(':
                    if (!data_stack.empty())
                    {
                        if (data_stack.top().type == 0)
                        {
                            data_stack.top().number++;
                        }
                        else
                        {
                            data_stack.emplace(bracket{0});
                        }
                    }
                    else
                    {
                        data_stack.emplace(bracket{0});
                    }
                break;
                case ')':
                    if (!data_stack.empty())
                    {
                        if (data_stack.top().type == 0)
                        {
                            data_stack.top().number--;
                            if (data_stack.top().number == 0)
                            {
                                data_stack.pop();
                            }
                        }
                        else
                        {
                            data_stack.emplace(bracket{0});
                        }
                    }
                    else
                    {
                        return false;
                    }
                break;
                case '[':
                    if (!data_stack.empty())
                    {
                        if (data_stack.top().type == 1)
                        {
                            data_stack.top().number++;
                        }
                        else
                        {
                            data_stack.emplace(bracket{1});
                        }
                    }
                    else
                    {
                        data_stack.emplace(bracket{1});
                    }
                break;
                case ']':
                    if (!data_stack.empty())
                    {
                        if (data_stack.top().type == 1)
                        {
                            data_stack.top().number--;
                            if (data_stack.top().number == 0)
                            {
                                data_stack.pop();
                            }
                        }
                        else
                        {
                            data_stack.emplace(bracket{1});
                        }
                    }
                    else
                    {
                        return false;
                    }
                break;
                case '{':
                    if (!data_stack.empty())
                    {
                        if (data_stack.top().type == 2)
                        {
                            data_stack.top().number++;
                        }
                        else
                        {
                            data_stack.emplace(bracket{2});
                        }
                    }
                    else
                    {
                        data_stack.emplace(bracket{2});
                    }
                break;
                case '}':
                    if (!data_stack.empty())
                    {
                        if (data_stack.top().type == 2)
                        {
                            data_stack.top().number--;
                            if (data_stack.top().number == 0)
                            {
                                data_stack.pop();
                            }
                        }
                        else
                        {
                            data_stack.emplace(bracket{2});
                        }
                    }
                    else
                    {
                        return false;
                    }
                break;
            }
        }

        if (!data_stack.empty())
        {
            return false;
        }

        else
        {
            return true;
        }
    }
}