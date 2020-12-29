#include <Operation.hpp>

#include <gtest/gtest.h>

struct OperationParam {
    OperationParam(Operation::Type _type, int _count, int _N, bool _result)
        : operationType(_type)
        , counter(_count)
        , N(_N)
        , result(_result) {

    }

    Operation::Type operationType;
    int counter;
    int N;
    bool result;
};

class OperationParamTest: public ::testing::TestWithParam<OperationParam> {

};

TEST_P(OperationParamTest, CheckOperation) {
    const auto param = GetParam();
    Operation op(param.operationType);
    auto actualResult = op.Execute(param.counter, param.N);
    EXPECT_EQ(actualResult, param.result);
}

TEST_P(OperationParamTest, CheckSetOperation) {
    Operation op;
    const auto param = GetParam();
    op.SetOperationType(param.operationType);
    auto actualResult = op.Execute(param.counter, param.N);
    EXPECT_EQ(actualResult, param.result);
}

INSTANTIATE_TEST_CASE_P(
  OperationParamTest, OperationParamTest, ::testing::Values(
      OperationParam(Operation::Type::EQ, 3, 3, true),
      OperationParam(Operation::Type::EQ, 4, 3, false),
      OperationParam(Operation::Type::EQ, 2, 3, false),
      OperationParam(Operation::Type::GR, 4, 3, true),
      OperationParam(Operation::Type::GR, 3, 3, false),
      OperationParam(Operation::Type::GR, 2, 3, false),
      OperationParam(Operation::Type::LE, 2, 3, true),
      OperationParam(Operation::Type::LE, 3, 3, false),
      OperationParam(Operation::Type::LE, 4, 3, false)
  )
);