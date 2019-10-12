#include "Homework.h"
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
struct caseInsensitiveComparator {
    bool operator()(const std::string& lhs, const std::string& rhs) const {
            if (lhs.size() != rhs.size()) {
                return true;
            }

            for (size_t i = 0; i < rhs.size(); ++i) {
                if (std::toupper(lhs[i]) != std::toupper(rhs[i])) {
                    return true;
                }
            }

            return false;
    }
};

std::vector<std::string> getUniqueWords (const std::string& text)
{
    std::set<std::string, caseInsensitiveComparator> uniqueWords;

    std::string modifiedText {text};
    modifiedText.erase(std::remove_if(modifiedText.begin(), modifiedText.end(), ispunct), modifiedText.end());

    std::stringstream stream(modifiedText);
    std::string word;

    while(std::getline(stream, word, ' '))
        {
            uniqueWords.insert(word);
        }

    std::vector<std::string> wordsVector;
    wordsVector.reserve(uniqueWords.size());

    for(const auto& element : uniqueWords)
    {
        wordsVector.push_back(std::move(element));
    }

    return  wordsVector;
}

std::vector<std::pair<std::string, size_t>> wordCounter (const std::string& text)
{
    std::map<std::string, size_t, caseInsensitiveComparator> uniqueWordsCounter;

    std::string modifiedText {text};
    modifiedText.erase(std::remove_if(modifiedText.begin(), modifiedText.end(), ispunct), modifiedText.end());

    std::stringstream stream(modifiedText);
    std::string word;

    while(std::getline(stream, word, ' '))
        {
            auto insertionCheck = uniqueWordsCounter.insert({word,1});

            if(insertionCheck.second == false)
            {
                insertionCheck.first->second += 1;
            }
        }

    std::vector<std::pair<std::string, size_t>> wordsVector;
    wordsVector.reserve(uniqueWordsCounter.size());

    for(const auto& element : uniqueWordsCounter)
    {
        wordsVector.push_back(std::move(element));
    }

    return  wordsVector;
}
