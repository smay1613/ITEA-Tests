#pragma once
#include <string>
#include <vector>
#include <forward_list>

std::vector<int> combineVectors(const std::vector<int>::iterator firstVectorBeginIterator, const std::vector<int>::iterator firstVectorEndIterator,
                                const std::vector<int>::iterator secondVectorBeginIterator, const std::vector<int>::iterator secondVectorEndIterator);

size_t magicNumber(const size_t number, const size_t degree);

void reverse(std::forward_list<int>& listToReverse);