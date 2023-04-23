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
    std::string name = "circle(1 5, 4)";
    const int expected = 0;
    int res = 1;
    ErCheck(name, 1, &res);
    ASSERT_EQUAL(expected, res);
}

CTEST(check_x_int_true, test3)
{
    std::string name = "circle(1 5, 4)";
    const int expected = 1;
    int res = 1;
    ErCheck(name, 1, &res);
    ASSERT_EQUAL(expected, res);
}

CTEST(check_x_float_true, test4)
{
    std::string name = "circle(1.1 5, 4)";
    const int expected = 1;
    int res = 1;
    ErCheck(name, 1, &res);
    ASSERT_EQUAL(expected, res);
}

CTEST(check_y_int_true, test5)
{
    std::string name = "circle(1 5, 4)";
    const int expected = 1;
    int res = 1;
    ErCheck(name, 1, &res);
    ASSERT_EQUAL(expected, res);
}

CTEST(check_y_float_true, test6)
{
    std::string name = "circle(1.1 5.1, 4)";
    const int expected = 1;
    int res = 1;
    ErCheck(name, 1, &res);
    ASSERT_EQUAL(expected, res);
}

CTEST(check_x_int_false, test7)
{
    std::string name = "circle(1.1 5, 4)";
    const int expected = 0;
    int res = 1;
    ErCheck(name, 1, &res);
    ASSERT_EQUAL(expected, res);
}

CTEST(check_x_float_false, test8)
{
    std::string name = "circle(1 5, 4)";
    const int expected = 0;
    int res = 1;
    ErCheck(name, 1, &res);
    ASSERT_EQUAL(expected, res);
}

CTEST(check_y_int_false, test9)
{
    std::string name = "circle(1 5.1, 4)";
    const int expected = 0;
    int res = 1;
    ErCheck(name, 1, &res);
    ASSERT_EQUAL(expected, res);
}

CTEST(check_y_float_false, test10)
{
    std::string name = "circle(1.1 5, 4)";
    const int expected = 0;
    int res = 1;
    ErCheck(name, 1, &res);
    ASSERT_EQUAL(expected, res);
}

CTEST(check_r_int_true, test11)
{
    std::string name = "circle(1.1 5, 4)";
    const int expected = 1;
    int res = 1;
    ErCheck(name, 1, &res);
    ASSERT_EQUAL(expected, res);
}

CTEST(check_r_float_true, test12)
{
    std::string name = "circle(1.1 5, 4.1)";
    const int expected = 1;
    int res = 1;
    ErCheck(name, 1, &res);
    ASSERT_EQUAL(expected, res);
}

CTEST(check_r_int_false, test13)
{
    std::string name = "circle(1.1 5, 4.1)";
    const int expected = 0;
    int res = 1;
    ErCheck(name, 1, &res);
    ASSERT_EQUAL(expected, res);
}

CTEST(check_r_float_false, test14)
{
    std::string name = "circle(1.1 5, 4)";
    const int expected = 0;
    int res = 1;
    ErCheck(name, 1, &res);
    ASSERT_EQUAL(expected, res);
}

CTEST(check_no_excess_token_true, test15)
{
    std::string name = "circle(1.1 5, 4)";
    const int expected = 1;
    int res = 1;
    ErCheck(name, 1, &res);
    ASSERT_EQUAL(expected, res);
}

CTEST(check_no_excess_token_false, test16)
{
    std::string name = "circle(1.1 x5, 4)";
    const int expected = 0;
    int res = 1;
    ErCheck(name, 1, &res);
    ASSERT_EQUAL(expected, res);
}