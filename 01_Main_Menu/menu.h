#pragma once

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <cstdint>
#include <vector>

namespace
{
    constexpr std::size_t MIN_OPTIONS = 0;
    constexpr std::size_t MAX_OPTIONS = 3;
    constexpr char NEWLINE = '\n';
    constexpr char SPACE = ' ';
    constexpr char SELECT_SYMBOL = '>';
    constexpr char DEFAULT_SELECT_SYMBOL = '-';
}

class Menu
{
public:

    // Default constructor
    Menu() : select(MAX_OPTIONS, DEFAULT_SELECT_SYMBOL),
             options{ "Start", "Settings", "Exit" } {}

    /*****  General constructor. *****/
    // That should later replace '-' with '>',
    // so needs to be updated...
    // Menu(char &selected, std::int32_t index) : select() {}

    void clearScreen();
    void display_menu();
    void update_display(std::size_t index, char input);
    char select_option(std::size_t &index);
    void option_choosen(std::size_t &index);

private:

    std::vector<char> select;
    std::vector<std::string> options;

};

void execute();

#endif