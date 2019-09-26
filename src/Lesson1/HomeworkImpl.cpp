#include "Homework.h"
#include <list>
#include <cstdint>
#include <cmath>

std::vector<int> combineVectors (const std::vector<int>::iterator& begin1, const std::vector<int>::iterator& end1, const std::vector<int>::iterator& begin2, const std::vector<int>::iterator& end2)
{
    std::vector<int> resultVector;
    resultVector.reserve((std::distance(begin1,end1)+std::distance(begin2,end2)));
    resultVector.insert(resultVector.end(), begin1, end1);
    resultVector.insert(resultVector.end(), begin2, end2);
    return resultVector;
};

size_t magicNumber(const size_t number, const size_t degree)
{
    std::vector<size_t> VectorOfDig;
        size_t resultDigit = 0;
        std::list<size_t> resultList;
        VectorOfDig.reserve(degree);
        for(size_t i = 0; i < degree; i++)
        {
            if(i == 0)
            {
                VectorOfDig.push_back(degree);
            }
            else
            {   size_t element = (*(VectorOfDig.end()-1))*degree;
                VectorOfDig.push_back(element);
            }
        }
        for(auto number : VectorOfDig)
        {
            std::list<size_t> ListOfDig;
            while (number > 0)
            {
                size_t digit = number%10;
                ListOfDig.push_back(digit);
                number /= 10;
            }
            resultList.push_back(ListOfDig.back());
            resultList.push_back(ListOfDig.front());

        }
        size_t count{1};
        for( std::list<size_t>::reverse_iterator it = resultList.rbegin(); it!= resultList.rend(); it++)
        {
           resultDigit += (*it)*count;
           count *= 10;
        }
       return resultDigit;
};

void reverse(std::forward_list<int>& listToReverse)
{
    std::forward_list<int> reverseList{};
    for(auto& element : listToReverse)
    {
        reverseList.push_front(element);
    }
    listToReverse.swap(reverseList);
};
