#include "Homework.h"
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

 struct cmp
{
    bool operator() (std::string lhs, std::string rhs)
    {
        std::string tmp_lhs {lhs};
        std::string tmp_rhs {rhs};
        std :: transform( tmp_lhs.begin(), tmp_lhs.end(), tmp_lhs.begin(), ::tolower );
        std :: transform( tmp_rhs.begin(), tmp_rhs.end(), tmp_rhs.begin(), ::tolower );
        if(tmp_lhs < tmp_rhs)
            return true;
        return  false;
    }
};

 std::vector<std::string> getUniqueWords (const std::string& text){
    std::set<std::string, cmp>textCheck;
    std::stringstream textStream;
    std::string tmp;
    textStream << text;
    while(!textStream.eof())
    {
        textStream >> tmp;
        textCheck.insert(tmp);
    }
    std::vector<std::string>result{textCheck.begin(), textCheck.end()};
    return result;
}


 std::vector<std::pair<std::string, size_t>> wordCounter (const std::string& text){
    std::map<std::string, size_t, cmp>result;
    std::vector<std::pair<std::string, size_t>> resultReturn{};
    std::string tmp{};
    if(text == tmp){
        result.emplace("",0);
        resultReturn.push_back(*result.begin());
        return resultReturn;
    }
    std::stringstream textStream;
    textStream << text;
    while(!textStream.eof())
    {
        textStream >> tmp;
        if(result.empty()){
            result.emplace(tmp, 1);
            tmp.clear();
        }
        else{
            if(result.find(tmp) != result.end()){
                auto it = result.find(tmp);
                it->second ++;
                tmp.clear();
            }
            else {
                result.emplace(tmp, 1);
                tmp.clear();
            }
        }
    }
    for(const auto &value: result){
        resultReturn.push_back(value);
    }
    return resultReturn;
}
