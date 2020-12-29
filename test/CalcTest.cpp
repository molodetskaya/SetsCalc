#include <Parser.hpp>
#include <Expression.hpp>

#include <gtest/gtest.h>


struct ParseAndCalcParam {

    ParseAndCalcParam(std::vector<std::string> _args, std::map<int, int> _expRes)
        : args(_args)
        , expRes(_expRes) {

    }

    std::vector<std::string> args;
    std::map<int, int> expRes;
};

class ParseAndCalcParamTest: public ::testing::TestWithParam<ParseAndCalcParam> {

};


TEST_P(ParseAndCalcParamTest, SimpleExpression) {

    const auto param = GetParam();

    Parser parser;
    Expression expression;
    ASSERT_TRUE(parser.Parse(param.args, expression));
    ASSERT_TRUE(expression.CalculateResult());
    auto actRes = expression.GetResult();

    ASSERT_TRUE(std::equal(std::begin(param.expRes), std::end(param.expRes), std::begin(actRes)));
}


INSTANTIATE_TEST_CASE_P(
  ParseAndCalcParamTest, ParseAndCalcParamTest, ::testing::Values(

    ParseAndCalcParam(
        std::vector<std::string>{
            "[",
            "EQ",
            "3",
            "test_data/file1.txt",
            "test_data/file2.txt",
            "test_data/file3.txt",
            "]"
        },
        std::map<int, int> {
            {1, 3},
            {7, 3},
            {9, 3},
        }
    ),

    ParseAndCalcParam(
        std::vector<std::string> {
            "[",
            "EQ",
            "2",
            "test_data/file1.txt",
            "test_data/file2.txt",
            "test_data/file3.txt",
            "]"
        },
        std::map<int, int> {
            {3, 2},
            {5, 2},
            {12, 2},
            {15, 2},
            {17, 2},
        }
    ),
    
    ParseAndCalcParam(
        std::vector<std::string> {
            "[",
            "GR",
            "1",
            "test_data/file1.txt",
            "test_data/file2.txt",
            "[",
            "EQ",
            "3",
            "test_data/file1.txt",
            "test_data/file2.txt",
            "test_data/file3.txt",
            "]",
            "]"
        },
        std::map<int, int> {
            {1, 3},
            {3, 2},
            {7, 3},
            {9, 3},
            {15, 2},
        }
    ),
        
    ParseAndCalcParam(
        std::vector<std::string>{
            "[",
            "EQ",
            "3",
            "test_data/file1.txt",
            "[",
            "LE",
            "2",
            "test_data/file2.txt",
            "]",
            "[",
            "EQ",
            "1",
            "test_data/file3.txt",
            "]",
            "]"
        },
        std::map<int, int> {
            {1, 3},
            {7, 3},
            {9, 3},
        }
    )
  )
);