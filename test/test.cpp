#include <ctest.h>

#include <libgeometry/lexer.cpp>
#include <string>

CTEST(check_fig_name_true, test1)
{
    std::string name = "circle(1 5, 4)";
    const int expected = 1;
    int res = 1;
    ErCheck(name, 1, &res);
    ASSERT_EQUAL(expected, res);
}

CTEST(check_fig_name_false, test2)
{
    std::string name = "cir6654cle(1 5, 4)";
    const int expected = 0;
    int res = 1;
    ErCheck(name, 1, &res);
    ASSERT_EQUAL(expected, res);
}

CTEST(check_no_excess_token_true, test3)
{
    std::string name = "circle(1.1 5, 4)";
    const int expected = 1;
    int res = 1;
    ErCheck(name, 1, &res);
    ASSERT_EQUAL(expected, res);
}

CTEST(check_no_excess_token_false, test4)
{
    std::string name = "circle(1.1 x5, 4)";
    const int expected = 0;
    int res = 1;
    ErCheck(name, 1, &res);
    ASSERT_EQUAL(expected, res);
}

CTEST(check_closing_parenthesis_true, test5)
{
    std::string name = "circle(1.1 5, 4)";
    const int expected = 1;
    int res = 1;
    ErCheck(name, 1, &res);
    ASSERT_EQUAL(expected, res);
}

CTEST(check_closing_parenthesis_false, test6)
{
    std::string name = "circle(1.1 5, 4  ";
    const int expected = 0;
    int res = 1;
    ErCheck(name, 1, &res);
    ASSERT_EQUAL(expected, res);
}