#include "Homework.h"
#include <list>

std::vector<int> combineVectors (const std::vector<int>::iterator& begin1, const std::vector<int>::iterator& end1, const std::vector<int>::iterator& begin2, const std::vector<int>::iterator& end2)
{
    size_t size = std::distance(begin1, end1) + std::distance(begin2, end2);
    std::vector<int> tmp;
    tmp.reserve(size);
    tmp.insert(tmp.begin(), begin1, end1);
    tmp.insert(tmp.end(),begin2, end2);

    return tmp;
};

size_t magicNumber(const size_t number, const size_t degree)
{
    size_t wantedNumber = 0;
    size_t raisedToPowerNumber = 1;
    std::list<size_t> numbers;

        for (size_t i = 0; i < degree; i++)
        {
            raisedToPowerNumber *= number;
            size_t lastNumber;
            size_t currentNumber = raisedToPowerNumber;

            while(currentNumber != 0)
            {
                lastNumber = currentNumber % 10;
                currentNumber = currentNumber / 10;

                numbers.push_front(lastNumber);
            }

            wantedNumber = wantedNumber * 100 + numbers.front() * 10 + numbers.back();
            numbers.clear();
        }

    return wantedNumber;
};

void reverse(std::forward_list<int>& listToReverse)
{
    std::forward_list<int> list;
    auto it = listToReverse.begin();

    while (it != listToReverse.end())
    {
        list.push_front(*it);
        it++;
    }

    list.swap(listToReverse);
};
