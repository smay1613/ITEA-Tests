#pragma once

#include <vector>
#include <forward_list>

std::vector<int> combineVectors(const std::vector<int>::iterator& begin1,
                                const std::vector<int>::iterator& end1,
                                const std::vector<int>::iterator& begin2,
                                const std::vector<int>::iterator& end2);

size_t magicNumber(const size_t number, const size_t degree);

void reverse(std::forward_list<int>& listToReverse);
