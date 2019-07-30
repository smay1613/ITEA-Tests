#include "Utils.h"
#include <vector>

namespace avprocessing
{
    namespace utilities
    {
        std::string getFileName(const std::string& path)
        {
            const size_t fileNamePosition = path.find_last_of('/') + 1;
            if (fileNamePosition > path.size() || fileNamePosition == std::string::npos)
            {
                return {};
            }
            const std::string baseFilename {path.substr(fileNamePosition)};
            const size_t extensionPosition {baseFilename.find_last_of('.')};
            const std::string fileName {baseFilename.substr(0, extensionPosition)};
            return fileName;
        }

        std::string getFolderName(const std::string& path)
        {
            const size_t folderPositionEnd = path.find_last_of('/');
            const std::string baseDirectory {path.substr(0, folderPositionEnd)};
            const size_t folderPositionStart {baseDirectory.find_last_of('/') + 1};
            if (folderPositionStart > baseDirectory.size() || folderPositionEnd == std::string::npos)
            {
                return {};
            }
            std::string folderName {baseDirectory.substr(folderPositionStart, folderPositionEnd - folderPositionStart)};
            return folderName;
        }

        std::chrono::milliseconds durationToMilliseconds(int duration)
        {
            std::chrono::milliseconds result {0};

            if (duration > 0)
            {
                const std::chrono::seconds seconds {duration};
                result = std::chrono::duration_cast<std::chrono::milliseconds>(seconds);
            }
            return result;
        }
    }
}