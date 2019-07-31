#pragma once
#include <string>
#include <chrono>

namespace TagLib
{
namespace FLAC {class File;};
namespace APE {class Tag; class File;};
namespace ID3v2 {class Tag;};
namespace ASF {class File;};
namespace MP4 {class File;};
namespace MPEG {class File;};
namespace MPC {class File;};
namespace RIFF {namespace WAV {class File;}}
}

namespace avprocessing
{
namespace utilities
{
    std::string getFileName(const std::string& path);
    std::string getFolderName(const std::string& path);
    std::chrono::milliseconds durationToMilliseconds(int duration);
}
}
