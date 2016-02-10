#ifndef LEXER_H
#define LEXER_H
#include "Token.h"
#include <stdlib.h>
#include <string>


class Lexer
{
    public:
        Lexer();
        virtual ~Lexer();
        Token nextToken();

    protected:
        bool containsDigit(string l);

    private:
};

#endif // LEXER_H
