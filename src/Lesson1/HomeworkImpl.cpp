#include "Homework.h"
#include <vector>
#include <cmath>
#include <list>

void reverse(std::forward_list<int>& listToReverse)
{
    std::forward_list<int> tmp_forward_list {};

    for(const auto &i : listToReverse)
    {
        tmp_forward_list.push_front(i);
    }

    listToReverse.clear();
    listToReverse.swap(tmp_forward_list);
}

size_t magicNumber(const size_t N, const size_t X)
{
    std::list<size_t> tmp_list {};

       size_t number {1};
       size_t first_number {0};
       size_t last_number {0};

       for(size_t i = 0; i < X; ++i)
       {
           number *= N;
           first_number = number;
           last_number = number % 10;

           while(first_number >= 10)
           {
               first_number /= 10;
           }
           tmp_list.push_back(first_number);
           tmp_list.push_back(last_number);
       }

       size_t result {};

       for (const auto &i : tmp_list)
       {
           result = result * 10 + i;
       }

       return result;
}

std::vector<int> combineVectors(const std::vector<int>::iterator firstVectorBeginIterator,
                                const std::vector<int>::iterator firstVectorEndIterator,
                                const std::vector<int>::iterator secondVectorBeginIterator,
                                const std::vector<int>::iterator secondVectorEndIterator)
{
    std::vector<int> tmp_vec{};
    tmp_vec.insert(tmp_vec.end(), firstVectorBeginIterator, firstVectorEndIterator);
    tmp_vec.insert(tmp_vec.end(), secondVectorBeginIterator, secondVectorEndIterator);

    return tmp_vec;
}
