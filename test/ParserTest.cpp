#include <Parser.hpp>
#include <Expression.hpp>

#include <gtest/gtest.h>


class ParserParamTest: public ::testing::TestWithParam<std::vector<std::string>> {

};

TEST_P(ParserParamTest, WrongPunctuation) {

    Parser parser;
    Expression expression;

    ASSERT_FALSE(parser.Parse(GetParam(), expression));
}

INSTANTIATE_TEST_CASE_P(
  ParserParamTest, ParserParamTest, ::testing::Values(

    std::vector<std::string> {
        "[",
        "EQ",
        "2",
        "test_data/file1.txt",
        "test_data/file2.txt",
        "test_data/file3.txt",
    },

    std::vector<std::string> {
        "[",
        "GQ",
        "2",
        "test_data/file1.txt",
        "test_data/file2.txt",
        "test_data/file3.txt",
        "]",
    },

    std::vector<std::string> {
        "[",
        "GQ",
        "0",
        "test_data/file1.txt",
        "test_data/file2.txt",
        "test_data/file3.txt",
        "]",
    },

    std::vector<std::string> {
        "[",
        "EQ",
        "2",
        "test_data/file15.txt",
        "test_data/file2.txt",
        "test_data/file3.txt",
        "]"
    },

    std::vector<std::string> {
        "[",
        "EQ",
        "2",
        "]"
    }
  )
);
