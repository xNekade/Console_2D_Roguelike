#include "menu.h"

void Menu::display_menu()
{
    select[0] = SELECT_SYMBOL;

    for (std::size_t i = 0; i < select.size(); ++i)
    {
        std::cout << select[i] << SPACE
                  << options[i] << NEWLINE;
    }
}

void Menu::update_display(std::size_t index)
{
    // this line cause a bug with the index... need to fix
    // maybe with if-statement, like if(input == 'w') etc...
    select[index - 1] = DEFAULT_SELECT_SYMBOL;
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
        update_display(index);
    }
    if (input == 's' && index < MAX_OPTIONS - 1)
    {
        ++index;
        update_display(index);
    }

    return input;
}


void execute()
{
    // Add do-while loop for function select_option();,
    // so that after a option is selected with 'y'
    // the loop stops

    Menu menu;
    std::size_t index = 0; // maybe change name

    do
    {
        if (index < 1)
        {
            // this line causes a double display
            // with void Menu::update_display(std::size_t index)
            // but I fixed it with the if-statement
            menu.display_menu();    
        }

    } while (menu.select_option(index) != 'y');
}