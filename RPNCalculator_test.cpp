#include "RPNCalculator.h"

#include "~tool~catch.hpp"

#include <iostream>
using namespace std;

TEST_CASE( "Operations are properly recognized", "[RPNCalculator]" )
{
    // All supported operators are recognized
    REQUIRE( RPNCalculator::isOperation("+") );
    REQUIRE( RPNCalculator::isOperation("-") );
    REQUIRE( RPNCalculator::isOperation("*") );
    REQUIRE( RPNCalculator::isOperation("/") );

    // While all other symbols are not
    String testValue(" ");
    for (unsigned i = 0; i < 256; ++i) {
        testValue[0] = static_cast<char>(i);
        if (testValue[0] != '+' && testValue[0] != '-' && testValue[0] != '*' && testValue[0] != '/')
            REQUIRE ( !RPNCalculator::isOperation(testValue) );
    }
}

TEST_CASE( "Values are properly parsed", "[RPNCalculator]" )
{
    REQUIRE( RPNCalculator::parseValue("0") == 0);
    REQUIRE( RPNCalculator::parseValue("0.000") == 0);
    REQUIRE( RPNCalculator::parseValue("1.000") == 1);
    REQUIRE( RPNCalculator::parseValue(".100") == 0.1);
    REQUIRE( RPNCalculator::parseValue("0.123e2") == 12.3);
    REQUIRE( RPNCalculator::parseValue("-12") == -12);
}

TEST_CASE( "Operations are calculated correctly", "[RPNCalculator]" )
{
    REQUIRE( RPNCalculator::calculate(2, 3, "+") == 5);
    REQUIRE( RPNCalculator::calculate(3, 2, "+") == 5);
    REQUIRE( RPNCalculator::calculate(5, 3, "-") == 2);
    REQUIRE( RPNCalculator::calculate(3, 5, "-") == -2);
    REQUIRE( RPNCalculator::calculate(3, 2.5, "*") == 7.5);
    REQUIRE( RPNCalculator::calculate(2.5, 3, "*") == 7.5);
    REQUIRE( RPNCalculator::calculate(10, 2, "/") == 5);
    REQUIRE( RPNCalculator::calculate(2, 10, "/") == 0.2);
}

TEST_CASE( "RPN expressions are calculated correctly", "[RPNCalculator]" )
{
    REQUIRE( RPNCalculator::rpnCalc("2 3 +") == 5 );
    REQUIRE( RPNCalculator::rpnCalc("3 2 -") == 1 );
    REQUIRE( RPNCalculator::rpnCalc("2 3 *") == 6 );
    REQUIRE( RPNCalculator::rpnCalc("3 2 /") == 1.5 );
    REQUIRE( RPNCalculator::rpnCalc("4 9 + 14 - 19 * 20 /") == -0.95);
    REQUIRE( RPNCalculator::rpnCalc("2.7 12.3 + 2 - 2.1 * 2 /") == 13.65);
}
