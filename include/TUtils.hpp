#pragma once

#include <iostream>
#include <string>
#include "ExprToken.hpp"

std::string tokenTypeToString(TokenType type);
std::ostream &operator<<(std::ostream &os, TokenType type);
