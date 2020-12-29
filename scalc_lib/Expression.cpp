#include <Expression.hpp>
#include <File.hpp>

#include <map>
#include <iostream>

Expression::Expression(std::map<int, int> inputSet) {

    result = std::move(inputSet);
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

void Expression::AddSet(Expression set) {

    sets.push_back(std::move(set));
}

bool Expression::CalculateResult() {
    
    if (sets.empty()) {

        return true;
    }

    for (auto & set: sets)
    {
        if (!set.CalculateResult()) {

            return false;
        }

        MergeResult(set.GetResult());
    }
        
    const auto count = std::erase_if(result, [&](const auto& item) {

        return !operation.Execute(item.second, N);
    });

    return true;
}

void Expression::MergeResult(const std::map<int, int> & partialResult) {

    for (const auto & obj: partialResult) {

        auto res = result.emplace(obj.first, 1);
        if (!res.second) {

            res.first->second++;
        }
    }
}

void Expression::PrintResult() const {

    for(const auto & obj : result) {

        std::cout << obj.first << " " << std::endl;
    }
}

const std::map<int, int> & Expression::GetResult() const {

    return result;
}