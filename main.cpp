#include <iostream>
#include "lexer.hpp"


int main()
{
    Lexer lexer = Lexer("x = log(u^2 + v^2) / (v - sin(u))");
    lexer.tokenize();
    lexer.printTokens();
}