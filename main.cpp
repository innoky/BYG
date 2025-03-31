#include <iostream>
#include "lexer.hpp"


int main()
{
    Lexer lexer = Lexer("(3.121+2-1) * 2 / 42 \0");

    lexer.tokenize();
    lexer.printTokens();
}