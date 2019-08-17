#include "Homework.h"
#include <set>
#include <map>
#include <algorithm>
#include <sstream>


void toLower(std::string &stringToLower) {
    for (char & entry: stringToLower) {
        entry = entry <= 'Z' && entry >= 'A'? entry - 'A' + 'a' : entry;
    }
}

std::vector<std::string> getUniqueWords(const std::string & text) {
    size_t indexOfBegin, indexOfEnd, currentPosition{0};
    std::string word, punctuation(" ");
    std::set<std::string> usedWords;
    std::vector<std::string> result;

    while (currentPosition != text.npos) {
        indexOfBegin = text.find_first_not_of(punctuation, currentPosition);
        if (indexOfBegin < text.length()) {
            indexOfEnd = text.find_first_of(punctuation, indexOfBegin);
            if (indexOfEnd < text.length()) {
                word = text.substr(indexOfBegin, indexOfEnd - indexOfBegin);
            }
            else {
                word = text.substr(indexOfBegin, text.length() - indexOfBegin);
            }
            toLower(word);
            if (usedWords.insert(word).second)
                result.push_back(word);
            currentPosition = indexOfEnd;
        }
        else currentPosition = indexOfBegin;
    }

    return result;
}

std::vector<std::pair<std::string, size_t>> wordCounter(const std::string & text) {
    size_t indexOfBegin, indexOfEnd, currentPosition{0};
    std::string word, punctuation(" ");
    std::map<std::string, int> usedWords;
    std::vector<std::pair<std::string, size_t>> result;

    while (currentPosition != text.npos) {
        indexOfBegin = text.find_first_not_of(punctuation, currentPosition);
        if (indexOfBegin < text.length()) {
            indexOfEnd = text.find_first_of(punctuation, indexOfBegin);
            if (indexOfEnd < text.length()) {
                word = text.substr(indexOfBegin, indexOfEnd - indexOfBegin);
            }
            else {
                word = text.substr(indexOfBegin, text.length() - indexOfBegin);
            }
            toLower(word);
            usedWords[word]++;
            currentPosition = indexOfEnd;
        }
        else currentPosition = indexOfBegin;
    }

    for (const auto & entry: usedWords) {
        result.push_back(entry);
    }

    return result;
}
