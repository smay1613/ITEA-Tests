#pragma once
#include <string>
#include <vector>

std::vector<std::string> getUniqueWords (const std::string& text);
std::vector<std::pair<std::string, size_t>> wordCounter (const std::string& text);
