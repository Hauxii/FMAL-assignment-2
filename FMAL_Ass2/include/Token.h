#ifndef TOKEN_H_INCLUDED
#define TOKEN_H_INCLUDED
#include <iostream>

using namespace std;

enum TokenCode { ID, ASSIGN, SEMICOL, INT, ADD, SUB,
MULT, LPAREN, RPAREN, PRINT, END, ERROR };

class Token {
    public:
        Token(){};
        string lexeme;
        TokenCode tCode;
};


#endif // TOKEN_H_INCLUDED
