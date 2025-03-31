#pragma once
#include <string>

enum class TokenType : short
{
    NUMBER,
    VARIABLE,
    FUNCTION,
    OPERATOR,
    LPAREN,
    RPAREN,
    END
};

struct ExprToken {
    std::string text;
    TokenType type;
};