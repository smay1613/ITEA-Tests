#include "Homework.h"
#include <list>
#include <cstdint>
#include <cmath>

std::vector<int> combineVectors (const std::vector<int>::iterator& begin1, const std::vector<int>::iterator& end1, const std::vector<int>::iterator& begin2, const std::vector<int>::iterator& end2)
{
    std::vector<int> vector_result {};
    vector_result.insert(vector_result.end(), std::make_move_iterator(begin1), std::make_move_iterator(end1));
    vector_result.insert(vector_result.end(), std::make_move_iterator(begin2), std::make_move_iterator(end2));
    return vector_result;
};

size_t magicNumber(const size_t number, const size_t degree)
{
    std::list<int> list {};

    for (size_t i = 1; i <= degree; ++i) {
        list.push_back(static_cast<int>(std::pow(number,i)));
    }
    ulong num = 0;
    for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it) {
        uint32_t temp_for_num = *it % 10;
        while (*it != 0) {
            *it /= 10;
            if (*it >= 1 && *it <= 9) {
                num = (num * 10) + *it % 10;
                num = (num * 10) + temp_for_num;
            }
        }
    }
    return num;
};

void reverse(std::forward_list<int>& listToReverse)
{
    std::forward_list<int> modifiedListToReverse {};

    for (std::forward_list<int>::iterator it = listToReverse.begin(); it != listToReverse.end(); ++it) {
        modifiedListToReverse.insert_after(modifiedListToReverse.before_begin(), *it);
    }
};
