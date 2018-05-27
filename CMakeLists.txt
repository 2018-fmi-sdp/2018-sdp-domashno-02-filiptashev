cmake_minimum_required (VERSION 2.6)
project (CalcRpn)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

add_executable(calc-rpn
    main.cpp
    RPNCalculator.cpp
    String.cpp)

add_executable(rpn-tests
    test-main.cpp
    ListStack_test.cpp
    Tokenizer_test.cpp
    RPNCalculator_test.cpp
    RPNCalculator.cpp
    String.cpp)

enable_testing()
add_test(rpn-tests rpn-tests)