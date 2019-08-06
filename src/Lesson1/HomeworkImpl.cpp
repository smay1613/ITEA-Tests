#include "Homework.h"
#include <vector>
#include <cmath>
#include <list>

void reverse(std::forward_list<int>& listToReverse)
{
    std::forward_list<int>reverseForvardListData;
    for(const auto &value: listToReverse){
        reverseForvardListData.push_front(value);
    }
    const std::forward_list<int> returnlist{reverseForvardListData};
    reverseForvardListData.swap(listToReverse);
}

size_t magicNumber(const size_t number, const size_t degree)
{
    size_t _degree{degree};
    size_t _number{number};
    if (_number < 0)
        _number *= -1;
    std::list<size_t>resultList;
    size_t result{0};
    int numberDegree = 1;
    for (int i = 1; i<=_degree; i++){
        int tmpFirstNumber{};
        int tmpSecondNubmer{};
        numberDegree *= _number;
        if(numberDegree > 9){
            tmpFirstNumber = numberDegree;
            tmpSecondNubmer = numberDegree % 10;
            while (tmpFirstNumber > 9) {
                tmpFirstNumber /= 10;
            }
            resultList.push_back(tmpFirstNumber *10 + tmpSecondNubmer);
        }
        else{
            tmpFirstNumber = numberDegree;
            resultList.push_back(tmpFirstNumber);
        }
    }
    for(const auto &value: resultList){
        if(value<10){
            result*= 10;
        }
        else{
            result*= 100;
        }
        result += value;
    }
    return result;
}

std::vector<int> combineVectors(const std::vector<int>::iterator firstVectorBeginIterator,
                                const std::vector<int>::iterator firstVectorEndIterator,
                                const std::vector<int>::iterator secondVectorBeginIterator,
                                const std::vector<int>::iterator secondVectorEndIterator)
{
    std::vector<int>tmp {firstVectorBeginIterator,firstVectorEndIterator};
    tmp.insert(tmp.end(), secondVectorBeginIterator, secondVectorEndIterator);
    return tmp;
}
