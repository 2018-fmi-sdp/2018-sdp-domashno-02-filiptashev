#pragma once

/**
 * @file TODO - какви класове и функции дефинира този файл
 */

#include "String.h"

#include <cassert>

/*  Wraps a String and splits it into tokens (separated by spaces)
    To see how it is used see the Tokenizer_test.cpp
    To run only tokenizer tests:
        build/rpn-tests "[Tokenizer]"
    To see a list of all test checks:
        build/rpn-tests "[Tokenizer]" --reporter=compact --success
*/
class Tokenizer {
public:

    Tokenizer(const String& str) : _str(str), _nextToken(nullptr) {
        if(_str.len() > 0)
            _nextToken = _str.data();

        // TODO - skip all the spaces
    }

    bool hasMore() const { return _nextToken && *_nextToken != '\0'; }

    String nextToken() {
        assert(hasMore());

        const char* nextSpace = std::strchr(_nextToken, ' ');

        // nextSpace is null if ' ' was not found, which means that
        // the result token is from _nextToken till the end of the string
        unsigned tokenSize = nextSpace ? (nextSpace - _nextToken) : strlen(_nextToken);

        String result(tokenSize);
        strncpy(result.data(), _nextToken, tokenSize);

        // Move the next token pointer to the position of the space
        _nextToken += tokenSize;

        skipSpaces();

        return result;
    }

private:
    void skipSpaces() {
        while(_nextToken /* && TODO _nextToken has not reached a ' '*/ && *_nextToken != '\0')
            ++_nextToken;
    }

    String _str;
    const char* _nextToken;
};
