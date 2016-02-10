#ifndef PARSER_H
#define PARSER_H
#include "Lexer.h"
#include <stack>


class Parser
{
    public:
        Parser();
        Parser(Lexer myLexer);
        virtual ~Parser();
        void parse();

    protected:

    private:
        Token thisToken;
        Lexer thisLexer;
        stack<string> lex;
        stack<TokenCode> ops;
        void statements();
        void statement();
        void expr();
        void term();
        void factor();
};

#endif // PARSER_H
