#include <Expression.hpp>

#include <algorithm>
#include <map>

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
    sets.push_back(std::move(set));
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