#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "ExprToken.hpp"

std::string tokenTypeToString(TokenType type);
std::ostream &operator<<(std::ostream &os, TokenType type);

std::vector<char> readFile(const std::string &filename)
{
    std::ifstream file(filename, std::ios::ate | std::ios::binary);

    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    size_t fileSize = (size_t)file.tellg();
    std::vector<char> buffer(fileSize);

    file.seekg(0);
    file.read(buffer.data(), fileSize);

    file.close();
    return buffer;
}
