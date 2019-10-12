#include "Homework.h"
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <sstream>
#include <vector>
#include <functional>


std::string stingTolower(std::string s) {
  std::transform(s.begin(), s.end(), s.begin(),
                 [](unsigned char c){ return std::tolower(c);});
  return s;
}

std::vector<std::string> getUniqueWords (const std::string& text) {
  std::set<std::string> uniqueWords;
  std::stringstream full_string{text};
  std::string word;
  while(full_string >> word) {
    word.erase(std::remove_if(word.begin(), word.end(), std::function<bool(char)>(ispunct)),
              word.end());
    if (word.empty()) {
        continue;
    }
    uniqueWords.insert(stingTolower(word));
  }
  std::vector<std::string> OutWords {uniqueWords.begin(),
                                     uniqueWords.end()};
  return OutWords;
}

std::vector<std::pair<std::string, size_t>> wordCounter(const std::string & text) {
  std::map<std::string, size_t> uniqueWordsMap;
  std::stringstream full_string{text};
  std::string word;
  while(full_string >> word) {
    word.erase(std::remove_if(word.begin(), word.end(), std::function<bool(char)>(ispunct)),
              word.end());
    if (word.empty()) {
      continue;
    }
    std::map<std::string, size_t>::iterator it {uniqueWordsMap.find(stingTolower(word))};
    if (it == uniqueWordsMap.end()) {
      uniqueWordsMap.emplace(stingTolower(word), 1);
    } else {
      ++(it->second);
    }
  }
  std::vector<std::pair<std::string, size_t>> OutWords{uniqueWordsMap.begin(),
                                                       uniqueWordsMap.end()};
  return OutWords;
}
