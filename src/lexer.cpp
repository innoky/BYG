#include "lexer.hpp"
#include <iostream>

Lexer::Lexer(const std::string& content)
{
    content_ = content;
    pos_ = 0;
}

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
    else if (isdigit(current) || current == '.')
    {
        return readNumber();
    }
    else if (current == '+'
    ||  current == '-'
    ||  current == '*'
    ||  current == '/'
    ||  current == '^'
    ||  current == '=' ) {
        get();
        return ExprToken{std::string(1, current), TokenType::OPERATOR};
    }
    else if (current == '(')
    {
        get();
        return ExprToken{"(", TokenType::LPAREN};
    }
    else if (current == ')')
    {
        get();
        return ExprToken{")", TokenType::RPAREN};
    }
    else
    {
        get();
        return ExprToken{std::string(1, current), TokenType::UNKNOWN};
    }
    
    return ExprToken{std::string(1, current), TokenType::END};
}

ExprToken Lexer::readNumber() 
{
    std::string numberStr = "";

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

std::vector<ExprToken> Lexer::tokenize()
{
    std::vector<ExprToken> tokens;
    while (pos_ < content_.size())
    {
        ExprToken token = nextToken();
        std::cout << token.text << " | " << static_cast<int>(token.type) << std::endl;
        tokens.push_back(token);
    }
    return tokens;
}

void Lexer::printTokens()
{   
    std::vector<ExprToken> outputTokens = tokenize();
    for (int id = 0; id < outputTokens.size(); id++)
    {
        std::cout << outputTokens[id].text << " | ";
        std::cout << static_cast<int>(outputTokens[id].type) << std::endl;
    }
}