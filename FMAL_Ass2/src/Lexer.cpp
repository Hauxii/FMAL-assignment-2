#include "Lexer.h"

Lexer::Lexer()
{

}

Lexer::~Lexer()
{
    //dtor
}

Token Lexer::nextToken()
{
    Token token = *new Token();

    char nextChar;
    string lex = "";
    while(nextChar != ' '){
        cin >> nextChar;
        lex += nextChar;
    }
    token.lexeme = lex;

    if(isdigit(lex[0])){
        token.tCode = INT;
    }
    else if(lex == "(") {
        token.tCode = LPAREN;
    }
    else if(lex == ")") {
        token.tCode = RPAREN;
    }
    else if(lex == ";") {
        token.tCode = SEMICOL;
    }
    else if(lex == "+") {
        token.tCode = ADD;
    }
    else if(lex == "-") {
        token.tCode = SUB;
    }
    else if(lex == "*") {
        token.tCode = MULT;
    }
    else if(lex == "=") {
        token.tCode = ASSIGN;
    }
    else if(lex == "print") {
        token.tCode = PRINT;
    }
    else if(lex == "end"){
        token.tCode = END;
    }
    else {
        if(containsDigit(lex)){
            token.tCode = ERROR;
        }
        else{
            token.tCode = ID;
        }
    }


    return token;
}

bool Lexer::containsDigit(string l){
    for(unsigned int i = 0; i < l.length(); i++){
        if(isdigit(l[i])){
            return true;
        }
    }
    return false;
}
