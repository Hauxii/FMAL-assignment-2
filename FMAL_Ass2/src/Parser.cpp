#include "Parser.h"


Parser::Parser()
{
    //dtor
}

Parser::~Parser()
{
    //dtor
}

Parser::Parser(Lexer myLexer)
{
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
