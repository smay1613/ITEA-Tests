#include "Homework.h"
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

std::vector<std::string> getUniqueWords(const std::string & text) {
    std::string word {};
    std::stringstream SString {text};
    std::set<std::string> resultSet;

    while (!SString.eof())
    {
        SString >> word;
        resultSet.insert(word);
    }

    std::vector<std::string> resultVector {resultSet.begin(), resultSet.end()};
    return resultVector;
}

std::vector<std::pair<std::string, size_t>> wordCounter(const std::string & text) {
    std::string word {};
    std::stringstream SString {text};
    std::map<std::string, size_t> resultMap;

    while (!SString.eof())
    {
        SString >> word;
        ++resultMap[word] ;
    }

    std::vector<std::pair<std::string, size_t>> resultVector {resultMap.begin(), resultMap.end()};
    return resultVector;
}
