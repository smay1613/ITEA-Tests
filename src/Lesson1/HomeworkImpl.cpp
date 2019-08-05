#include "Homework.h"
#include <vector>
#include <cmath>
#include <list>

void reverse(std::forward_list<int>& listToReverse)
{
    std::forward_list<int> tmpForwardList {};

      for(const auto &value: listToReverse) {
          tmpForwardList.push_front(value);
      }

      listToReverse.clear();
      listToReverse.splice_after(listToReverse.before_begin(),tmpForwardList);
}

size_t magicNumber(const size_t number, const size_t degree)
{
    std::list<size_t> resultList {};
      size_t calcResult = 0, lastDigit = 0, firstDigit = 0;

      for (size_t counter = 1; counter <= degree; ++counter) {
        calcResult = static_cast<size_t>(pow(number, counter)) ;
        lastDigit = calcResult % 10;
        while (calcResult) {
          firstDigit = calcResult % 10;
          calcResult /= 10;
        }
        resultList.push_back(firstDigit);
        resultList.push_back(lastDigit);
      }

      size_t result {};

      for (const size_t& elements : resultList) {
             result = result * 10 + elements;
         }

      return result;
}

std::vector<int> combineVectors(const std::vector<int>::iterator firstVectorBeginIterator,
                                const std::vector<int>::iterator firstVectorEndIterator,
                                const std::vector<int>::iterator secondVectorBeginIterator,
                                const std::vector<int>::iterator secondVectorEndIterator)
{
    std::vector<int> unitedVector {};

    unitedVector.insert(unitedVector.end(), firstVectorBeginIterator, firstVectorEndIterator);
    unitedVector.insert(unitedVector.end(), secondVectorBeginIterator, secondVectorEndIterator);
    return unitedVector;
}
