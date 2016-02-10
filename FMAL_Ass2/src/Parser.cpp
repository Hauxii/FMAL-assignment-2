#include "Parser.h"

Parser::~Parser()
{
    //dtor
}

Parser::Parser(Lexer myLexer)
{
    lex = *new stack<string>;
    ops = *new stack<TokenCode>;
    thisLexer = myLexer;
    thisToken = myLexer.nextToken();
}

void Parser::parse()
{
    while (thisToken.tCode != END){


    }
}

void Parser::statements()
{

}

void Parser::statement()
{
    if(thisToken.tCode == ID){
        lex.push(thisToken.lexeme);
        thisToken = thisLexer.nextToken();
        if(thisToken.tCode != ASSIGN){
            error();
            return;
        }
        else {
            ops.push(thisToken.tCode);
            thisToken = thisLexer.nextToken();
            expr();
        }
    }
    else if(thisToken.tCode == PRINT){
        ops.push(thisToken.tCode);
        thisToken = thisLexer.nextToken();
        if(thisToken.tCode != ID){
            error();
        }
        else {
            lex.push(thisToken.lexeme);
            thisToken = thisLexer.nextToken();
            cout << "PUSH " << lex.top() << endl << ops.top();
            lex.pop();
            ops.pop();
        }
    }
    else {
        error();
    }

}

void Parser::expr()
{
    term();
    if(thisToken.tCode == ADD ||thisToken.tCode == SUB){
        ops.push(thisToken.tCode);
        thisToken = thisLexer.nextToken();
        expr();
    }
}

void Parser::term()
{
    factor();
    if(thisToken.tCode == MULT){
        ops.push(thisToken.tCode);
        thisToken = thisLexer.nextToken();
        term();
    }
}

void Parser::factor()
{
    if(thisToken.tCode == INT || thisToken.tCode == ID){
        lex.push(thisToken.lexeme);
        thisToken = thisLexer.nextToken();
    }
    else if(thisToken.tCode == LPAREN){
        lex.push(thisToken.lexeme);
        thisToken = thisLexer.nextToken();
        expr();
        if(thisToken.tCode != RPAREN){
            error();
            return;
        }
        else{
            lex.push(thisToken.lexeme);
            thisToken = thisLexer.nextToken();
        }
    }
}

void Parser::error()
{
    cout << "Syntax error!";
}

void printAll()
{

}
