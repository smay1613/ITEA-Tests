#include "Homework.h"
#include <vector>
#include <cmath>
#include <list>

void reverse(std::forward_list<int>& listToReverse)
{
    std::forward_list<int> values_2;
        for (const auto& element : listToReverse)
        {
            values_2.push_front(element);
        }
        values_2.swap(listToReverse);
}

size_t magicNumber(const size_t number, const size_t degree)
{
//    std::list<int> number_l;
//    int numeric;
//    for (int i=1; i<=degree; i++)
//    {
//        numeric = pow(number, i);

//        int a = numeric;
//        while (a>9) {
//            a = a/10;
//        }
//        number_l.push_back(a);

//        if (numeric > 9)
//        {
//            number_l.push_back(numeric%10);
//        }
//    }
//    return number_l;
}

std::vector<int> combineVectors(const std::vector<int>::iterator firstVectorBeginIterator,
                                const std::vector<int>::iterator firstVectorEndIterator,
                                const std::vector<int>::iterator secondVectorBeginIterator,
                                const std::vector<int>::iterator secondVectorEndIterator)
{
    std::vector<int> vector;
    std::vector<int>::size_type size = firstVectorEndIterator.base() - firstVectorBeginIterator.base() + secondVectorEndIterator.base() - secondVectorBeginIterator.base();
    vector.reserve(size);

    for (std::vector<int>::iterator element = firstVectorBeginIterator; element.base() < firstVectorEndIterator.base(); element++)
    {
        vector.push_back(*element);
    }

    for (std::vector<int>::iterator element = secondVectorBeginIterator; element.base() < secondVectorEndIterator.base(); element++)
    {
        vector.push_back(*element);
    }
    return vector;
}
