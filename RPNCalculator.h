#pragma once

/**
 * @file TODO - какви класове и функции дефинира този файл
 */

#include "String.h"

/*
    To see how this class is used see the RPNCalculator_test.cpp
    To run only RPNCalculator tests:
        build/rpn-tests "[RPNCalculator]"
    To see a list of all test checks:
        build/rpn-tests "[RPNCalculator]" --reporter=compact --succes
 */
class RPNCalculator {
public:
    // True if token is one of "+", "*", "-", "/""
    static bool isOperation(const String& token);

    // Reads the string in token as a double value. Expects valid input
    static double parseValue(const String& token);

    // Calculates the operation represented by token with v1 and v2
    // E.g. calculate(2.0, 3.4, "-") will return -1.4
    static double calculate(double v1, double v2, const String& token);

    // Calculates the value of an expression in Reverse Polish Notation
    // E.g. rpnCalc("2 3 + 5 - 8 * 13 /") would calculate the value of
    // ((((2 + 3) - 5) * 8) / 13) = 0
    static double rpnCalc(const String& expression);
};
