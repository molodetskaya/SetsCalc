#include <Operation.hpp>

#include <gtest/gtest.h>

struct OperationParam {
    OperationParam(std::string _type, int _count, int _N, bool _setRes, bool _result)
        : operationType(_type)
        , counter(_count)
        , N(_N)
        , setRes(_setRes)
        , result(_result) {

    }

    std::string operationType;
    int counter;
    int N;
    bool setRes;
    bool result;
};

class OperationParamTest: public ::testing::TestWithParam<OperationParam> {

};

TEST_P(OperationParamTest, CheckSetOperation) {
    Operation op;
    const auto param = GetParam();
    EXPECT_EQ(op.SetOperationType(param.operationType), param.setRes);
    auto actualResult = op.Execute(param.counter, param.N);
    EXPECT_EQ(actualResult, param.result);
}

INSTANTIATE_TEST_CASE_P(
  OperationParamTest, OperationParamTest, ::testing::Values(
      OperationParam("EQ", 3, 3, true, true),
      OperationParam("EQ", 4, 3, true, false),
      OperationParam("EQ", 2, 3, true, false),
      OperationParam("GR", 4, 3, true, true),
      OperationParam("GR", 3, 3, true, false),
      OperationParam("GR", 2, 3, true, false),
      OperationParam("LE", 2, 3, true, true),
      OperationParam("LE", 3, 3, true, false),
      OperationParam("LE", 4, 3, true, false),
      OperationParam("", 4, 3, false, false),
      OperationParam("GE", 4, 3, false, false),
      OperationParam("ANY", 4, 3, false, false)
  )
);