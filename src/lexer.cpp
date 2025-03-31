#include "lexer.hpp"

char Lexer::peek() const 
{
    if (pos_ >= content_.size())
    {
        return '\0';
    }
    else {
        return content_[pos_];
    }
}

char Lexer::get() 
{
    if (pos_ >= content_.size())
    {
        return '\0';
    }
    else {
        return content_[pos_++];
    }
}

void Lexer::skipSpaces() 
{
    while (pos_ < content_.size() && content_[pos_] == ' ')
    {pos_++;}
}

ExprToken Lexer::nextToken() 
{
    skipSpaces();

    char current = peek();

    if (current == '\0') {
        return ExprToken{"", TokenType::END};
    }
}

ExprToken Lexer::readNumber() 
{
    std::string numberStr;

    bool hasDot = false;

    while (pos_ < content_.size())
    {
        char c = peek();
        if (isdigit(c)) 
        {
            numberStr += get();
        }
        else if (c == '.')
        {
            numberStr += get();
            hasDot = true;
        }
        else
        {
            break;
        }
    }
    return ExprToken{numberStr, TokenType::NUMBER};
}