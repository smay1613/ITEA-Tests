#pragma once
#include <string>
#include <chrono>

namespace avprocessing
{
namespace utilities
{
    std::string getFileName(const std::string& path);
    std::string getFolderName(const std::string& path);
    std::chrono::milliseconds durationToMilliseconds(int duration);
}
}
