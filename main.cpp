#include "RPNCalculator.h"
#include "String.h"

#include <iostream>

String readLine(std::istream& in) {
    String s;
    in >> s;
    return s;
}

int main()
{
    String expression = readLine(std::cin);

    // TODO - call RPNCalculator::rpnCalc and print the result
    double result = RPNCalculator::rpnCalc(expression);

    std::cout << result << std::endl;

    return 0;
}