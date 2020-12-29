#include <File.hpp>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>

File::File(std::string path)
    : filePath(std::move(path)) {

}


bool File::ReadFile () {

    if (!std::filesystem::exists(filePath))
    {
        std::cerr << "File \"" << filePath << "\" doesn't exist! Skip this set." << std::endl;
        return false;
    }
    std::ifstream ifs(filePath, std::ios::in | std::ifstream::binary);
    if (!ifs.is_open())
    {
        std::cerr<<"Couldn't open file " << filePath << std::endl;
        return false;
    }
    std::istream_iterator<int> iter{ifs};
    std::istream_iterator<int> end{};

    std::transform(iter, end, std::inserter(result, result.end()),
        [](const int &s) { 
            return std::make_pair(s, 1);
        });

    ifs.close();
    return true;
}

bool File::CalculateResult() {
    return ReadFile();
}
