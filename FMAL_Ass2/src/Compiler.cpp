#include <iostream>
#include "Lexer.h"

using namespace std;

int main()
{
    Lexer myLexer = new Lexer();
    Parser myParser = new Parser(myLexer);
    myParser.parse();

    return 0;
}

