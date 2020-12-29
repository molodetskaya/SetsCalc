#include <Expression.hpp>

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iterator>


void Set::PrintResult() const {
    for(auto obj : result)
    {
        std::cout << obj.first << " - " << obj.second<< std::endl;
    }
}

const std::map<int, int> & Set::GetResult() const {
    return result;
}


bool File::ReadFile () {

    if (!std::filesystem::exists(filePath))
    {
        std::cout << "File \"" << filePath << "\" doesn't exist! Skip this set." << std::endl;
        return false;
    }
    std::ifstream ifs(filePath, std::ios::in | std::ifstream::binary);
    if (!ifs.is_open())
    {
        std::cout<<"Couldn't open file " << filePath << std::endl;
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

Expression::Expression(): operation(), N(0) {

}

bool Expression::SetOperationType(const std::string & operationType) {

    return operation.SetOperationType(operationType);
}

bool Expression::SetN(int n) {

    if (n <= 0) {
        return false;
    }
    N = n;
    return true;
}

void Expression::AddSet(std::shared_ptr<Set> set) {
    sets.push_back(set);
}

bool Expression::CalculateResult() {
    
    bool calcResult = true;
    for (auto set: sets)
    {
        calcResult &= set->CalculateResult();
        MergeResult(set->GetResult());
    }

    const auto count = std::erase_if(result, [&](const auto& item) {
        return !operation.Execute(item.second, N);
    });

    return calcResult;
}

void Expression::MergeResult(const std::map<int, int> & partialResult) {

    for (auto obj: partialResult) {
        auto res = result.emplace(obj.first, 1);
        if (!res.second) {
            res.first->second++;
        }
    }
}