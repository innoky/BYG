#pragma once
#include <vector>
#include <string>
#include "ExprToken.hpp"

class Lexer {
public: 
    explicit Lexer(const std::string& content);

    std::vector<ExprToken> tokenize();
    void printTokens();

private:
    std::string content_;
    size_t pos_;

    char peek() const;
    char get();
    void skipSpaces();

    ExprToken nextToken();

    ExprToken readNumber();
    ExprToken readIndentifierOrFunction();

   
};