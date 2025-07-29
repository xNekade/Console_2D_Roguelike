/*
    --> Add later that '>' this hops from MAX_OPTIONS to 0 and else
*/

#include "menu.h"

void Menu::clearScreen() {
    std::cout << "\033[2J\033[H"; // Clear screen and move cursor to top-left
}


void Menu::display_menu()
{
    select[0] = SELECT_SYMBOL;

    for (std::size_t i = 0; i < select.size(); ++i)
    {
        std::cout << select[i] << SPACE
                  << options[i] << NEWLINE;
    }
}

void Menu::update_display(std::size_t index, char input)
{
    // this line cause a bug with the index... need to fix
    // maybe with if-statement, like if(input == 's') etc...

    clearScreen();

    if (input == 's')
    {
        select[index - 1] = DEFAULT_SELECT_SYMBOL;
    }
    else
    {
        select[index + 1] = DEFAULT_SELECT_SYMBOL;
    }
    select[index] = SELECT_SYMBOL;
    
    for (std::size_t i = 0; i < select.size(); ++i)
    {
        std::cout << select[i] << SPACE
                  << options[i] << NEWLINE;
    }
}

char Menu::select_option(std::size_t &index)
{
    char input;
    std::cin >> input;

    if (input == 'w' && index > MIN_OPTIONS)
    {
        --index;
        update_display(index, input);
    }
    if (input == 's' && index < MAX_OPTIONS - 1)
    {
        ++index;
        update_display(index, input);
    }

    return input;
}

void Menu::option_choosen(std::size_t &index)
{
    clearScreen();

    switch (index)
    {
        case 0:

            std::cout << "Started..." << NEWLINE;
            break;

        case 1:

            std::cout << "Settings..." << NEWLINE;
            break;

        case 2:

            std::cout << "Exited..." << NEWLINE;
            break;

        default:
            break;
    }
}

void execute()
{
    Menu menu;
    char chosen;
    std::size_t index = 0; // maybe change name

    menu.display_menu();

    do
    {
        chosen = menu.select_option(index);

    } while (chosen != 'y');

    menu.option_choosen(index);
}