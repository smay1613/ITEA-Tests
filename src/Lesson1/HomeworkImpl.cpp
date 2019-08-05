#include "Homework.h"
#include <vector>
#include <cmath>
#include <list>

void reverse(std::forward_list<int>& listToReverse)
{
    std::forward_list<int> temporaryForwardList;
    for (const auto& entry : listToReverse) {
        temporaryForwardList.push_front(entry);
    }
    listToReverse.clear();
    listToReverse.splice_after(listToReverse.before_begin(), temporaryForwardList);
}

size_t getFirstNumber(size_t number) {
    while (number / 10 > 0) {
        number /= 10;
    }
    return number;
}

size_t getLastNumber(size_t number) {
    return number % 10;
}

size_t magicNumber(const size_t number, const size_t degree)
{
    std::list<size_t> listOfNumbers;
    size_t value = 1, result = 0;
    for (size_t i = 0; i < degree; i++) {
        value *= number;
        listOfNumbers.push_back(getFirstNumber(value));
        listOfNumbers.push_back(getLastNumber(value));
    }

    for (const auto& entry : listOfNumbers) {
        result = result * 10 + entry;
    }
    return result;
}

std::vector<int> combineVectors(const std::vector<int>::iterator firstVectorBeginIterator,
                                const std::vector<int>::iterator firstVectorEndIterator,
                                const std::vector<int>::iterator secondVectorBeginIterator,
                                const std::vector<int>::iterator secondVectorEndIterator)
{
    std::vector<int> resultVector(static_cast<unsigned int>(firstVectorEndIterator - firstVectorBeginIterator + secondVectorEndIterator - secondVectorBeginIterator));
    std::copy(firstVectorBeginIterator, firstVectorEndIterator, resultVector.begin());
    std::copy(secondVectorBeginIterator, secondVectorEndIterator, resultVector.begin() + (firstVectorEndIterator - firstVectorBeginIterator));
    return resultVector;
}
