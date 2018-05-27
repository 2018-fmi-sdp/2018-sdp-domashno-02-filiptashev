#include "ListStack.h"

#include "~tool~catch.hpp"

TEST_CASE( "Newly constructed stacks are empty", "[ListStack]" ) {
    ListStack<int> s1;
    REQUIRE( s1.isEmpty() );
    REQUIRE( s1.size() == 0);
    REQUIRE( s1.isConsistent() );

    ListStack<char> s2;
    REQUIRE( s2.isEmpty() );
    REQUIRE( s2.size() == 0);
    REQUIRE( s2.isConsistent() );
}

TEST_CASE( "Big 4 methods are implemented correctly", "[ListStack]") {

    // GIVEN
    ListStack<int> s1;
    s1.push(10);
    s1.push(20);
    // cout << s1 << endl; // Uncomment this to have a look at what s1 looks like
    REQUIRE( s1.size() == 2 );
    REQUIRE( s1.isConsistent() );

    // WHEN we use copy c-tor
    ListStack<int> s2 = s1;

    // THEN
    REQUIRE( s2 == s1 );
    REQUIRE( s2.isConsistent() );

    // WHEN we change s1
    s1.push(30);
    REQUIRE( s1.size() == 3 );
    REQUIRE( s1.isConsistent() );

    // THEN
    REQUIRE( s2 != s1 );

    // WHEN we use assignment operator
    s1 = s2;

    // THEN
    REQUIRE( s2 == s1 );
    REQUIRE( s1.size() == 2 );
    REQUIRE( s1.isConsistent() );

    // WHEN we use assignment operator on the same object
    s1 = s1;

    // THEN it did not change
    REQUIRE( s2 == s1 );
    REQUIRE( s1.size() == 2 );
    REQUIRE( s1.isConsistent() );
}

TEST_CASE( "The stack contract is implemented correctly", "[ListStack]") {

    // GIVEN
    ListStack<char> s;
    const unsigned DATA_SIZE = 4;
    char testData[DATA_SIZE] = {'a', 'b', 'c', 'd'};
    char reversedTestData[DATA_SIZE] = {'d', 'c', 'b', 'a'};

    // WHEN
    for (unsigned i=0; i < DATA_SIZE; ++i) {
        s.push(testData[i]);
        REQUIRE( s.size() == i+1 );
        REQUIRE( s.top() == testData[i] );
        REQUIRE( s.isConsistent() );
    }

    // THEN
    for (unsigned i=0; i < DATA_SIZE; ++i) {
        REQUIRE( s.top() == reversedTestData[i] );
        REQUIRE( s.size() == DATA_SIZE-i );
        REQUIRE( s.pop() );  // s.pop() should return true
        REQUIRE( s.isConsistent() );
    }
    REQUIRE( s.isEmpty() );
    REQUIRE( s.size() == 0 );
    REQUIRE( !s.pop() );  // Cannot pop anymore
}
