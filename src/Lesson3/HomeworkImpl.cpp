#include "Homework.h"
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

std::vector<std::string> getUniqueWords(const std::string & text) {
    std::vector<std::string> words_vector;
        std::set<std::string> words_set;
        std::string word;
        std::stringstream str_stream;

        str_stream << text;
        while (!str_stream.eof())
        {
            str_stream >> word;
            words_set.insert(word);
        }

        for (const auto& element : words_set)
        {
            words_vector.push_back(element);
        }

        return words_vector;
}

std::vector<std::pair<std::string, size_t>> wordCounter(const std::string & text) {
    std::vector<std::pair<std::string, size_t>> words_vector;
        std::map<std::string, size_t> words_map;
        std::string word;
        std::stringstream str_stream;

        str_stream << text;
        while (!str_stream.eof())
        {
            str_stream >> word;
            if (words_map.empty())
            {
                words_map.insert(std::make_pair(word, 1));
                word.clear();
            }
            else
            {
                std::map<std::string, size_t>::iterator element = words_map.find(word);

                if (element != words_map.end())
                {
                    element->second++;
                    word.clear();
                }
                else {
                    words_map.insert(std::make_pair(word, 1));
                    word.clear();
                }
            }
        }

        for (const auto & element : words_map)
        {
            words_vector.push_back(element);
        }

        return words_vector;
}
