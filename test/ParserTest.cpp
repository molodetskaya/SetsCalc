#include <Parser.hpp>
#include <Expression.hpp>

#include <gtest/gtest.h>

struct ParserParam {

    ParserParam( bool _parseRes, bool _calcRes, std::vector<std::string> _args)
        : parseRes(_parseRes)
        , calcRes(_calcRes)
        , args(_args) {

    }

    bool parseRes;
    bool calcRes;
    std::vector<std::string> args;
};

class ParserParamTest: public ::testing::TestWithParam<ParserParam> {

};

TEST_P(ParserParamTest, WrongBraces) {

    auto param = GetParam();
    Parser parser;

    auto expression = parser.Parse(param.args);
    EXPECT_EQ(expression!=nullptr, param.parseRes);
    if (expression) {
        EXPECT_EQ(expression->CalculateResult(), param.calcRes);
    }
}

INSTANTIATE_TEST_CASE_P(
  ParserParamTest, ParserParamTest, ::testing::Values(

    ParserParam(false, false,
        std::vector<std::string> {
            "[",
            "EQ",
            "2",
            "test_data/file1.txt",
            "test_data/file2.txt",
            "test_data/file3.txt",
        }
    ),

    ParserParam(false, false,
        std::vector<std::string> {
            "[",
            "GQ",
            "2",
            "test_data/file1.txt",
            "test_data/file2.txt",
            "test_data/file3.txt",
        }
    ),

    ParserParam(true, false,
        std::vector<std::string> {
            "[",
            "EQ",
            "2",
            "test_data/file15.txt",
            "test_data/file2.txt",
            "test_data/file3.txt",
            "]"
        }
    )
  )
);
