#pragma once

#include <vector>
#include <iostream>
#include <cstdint>

using Grid = std::vector<std::vector<char16_t>>;

constexpr int16_t MAX_X = 16;
constexpr int16_t MAX_Y = 16;
constexpr const char *COLUMN = "\n";
constexpr char16_t EMPTY_SPACE = ' ';

Grid initialize_playground();
void display_playground(const Grid &grid);
void game();