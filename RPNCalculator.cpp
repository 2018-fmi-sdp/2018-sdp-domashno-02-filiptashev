#include "RPNCalculator.h"

#include "ListStack.h"
#include "Tokenizer.h"

#include <cstdlib>

bool RPNCalculator::isOperation(const String& token) {
    // TODO - return true only if token is one of +, -, *, /
    return false;
}

double RPNCalculator::calculate(double v1, double v2, const String& token) {
    switch (token[0]) {
        case '+' : return v1 + v2;
        // TODO - add proper cases for the other operations
    }

    return 0; // Should not happen
}

double RPNCalculator::parseValue(const String& token) {
    return std::strtod(token.data(), nullptr);
}

double RPNCalculator::rpnCalc(const String& expression)
{
    ListStack<double> values;
    Tokenizer t(expression);
    while(t.hasMore()) {
        String token = t.nextToken();
        // TODO - implement the algorithm
        // If the token is an operation
            // Pop two variables v2, v1 from the stack
            // Then push the result of calculate(v1, v2, token) to the stack
        // Else (we assume the token is a value)
            // Parse the token as double value
            // Then push the value on the stack
    }
    // TODO - uncomment this assert and return when the algorithm is implemented
    // assert(values.size() == 1);
    // return values.top();
    return 0;
}
