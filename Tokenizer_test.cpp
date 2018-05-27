#include "Tokenizer.h"

#include "~tool~catch.hpp"

TEST_CASE( "Empty strings have no tokens", "[Tokenizer]" )
{
    Tokenizer t1(String(""));
    REQUIRE( !t1.hasMore() );

    Tokenizer t2(String("   "));
    REQUIRE( !t2.hasMore() );
}

TEST_CASE( "Multiple spaces are ignored", "[Tokenizer]" )
{
    Tokenizer t(String("   asd      123   "));
    REQUIRE( t.hasMore() );

    REQUIRE( t.nextToken() == "asd" );
    REQUIRE( t.hasMore() );

    REQUIRE( t.nextToken() == "123" );
    REQUIRE( !t.hasMore() );
}

TEST_CASE( "A strict rpn expression is properly tokanized", "[Tokenizer]" )
{
    Tokenizer t(String("2 3 + 28 - 4.5 *"));
    REQUIRE( t.hasMore() );

    REQUIRE( t.nextToken() == "2" );
    REQUIRE( t.hasMore() );

    REQUIRE( t.nextToken() == "3" );
    REQUIRE( t.hasMore() );

    REQUIRE( t.nextToken() == "+" );
    REQUIRE( t.hasMore() );

    REQUIRE( t.nextToken() == "28" );
    REQUIRE( t.hasMore() );

    REQUIRE( t.nextToken() == "-" );
    REQUIRE( t.hasMore() );

    REQUIRE( t.nextToken() == "4.5" );
    REQUIRE( t.hasMore() );

    REQUIRE( t.nextToken() == "*" );
    REQUIRE( !t.hasMore() );
}