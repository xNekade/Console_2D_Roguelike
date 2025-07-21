/*

-Add game start loading screen at beginning
-Add Main menu to choose "start game" "setting's" "exit" etc...
-Add after start game singleplayer or coop selection
-Add random obstacles that can't be overrun by Player/Enemy
-Add Player at random location after obstacles
-Add Enemy's at random locations after obstacles

*/

#include "game.h"

Grid initialize_playground()
{
    Grid grid(MAX_Y, std::vector<char16_t>(MAX_X, EMPTY_SPACE)); // change vector size 3 with variable
    char16_t field_numbers = U'0' - 48;

    for (std::size_t y = 0; y < grid.size(); ++y)
    {
        for (std::size_t x = 0; x < grid.size(); ++x)
        {
            grid.at(y).at(x) = field_numbers;
            field_numbers = field_numbers + 1;
        }   
    }
    return grid;
}

void display_playground(const Grid &grid)
{
    for (std::size_t y = 0; y < grid.size(); ++y)
    {
        for (std::size_t x = 0; x < grid.size(); ++x)
        {
            std::cout << grid.at(y).at(x) << '|';
        }
        std::cout << COLUMN;
    }
}

void game()
{
    Grid grid = initialize_playground();
    display_playground(grid);
}