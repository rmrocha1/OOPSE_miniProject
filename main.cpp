// Main file for McDonald's ordering kiosk program

#include "kiosk.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

// Global variables
int current_menu_idx = 1;
string user_input = "";
int input_idx = 0;
vector<Menu::MenuItem> menuVector = {
    Menu::MenuItem (1, "hamburger", 4),
    Menu::MenuItem (2, "cheeseburger", 5),
    Menu::MenuItem (3, "big mac", 6),
    Menu::MenuItem (4, "small fries", 2),
    Menu::MenuItem (5, "medium fries", 3),
    Menu::MenuItem (6, "large fries", 4),
    Menu::MenuItem (7, "coca-cola", 2),
    Menu::MenuItem (8, "fanta", 2),
    Menu::MenuItem (9, "sprite", 2),
    Menu::MenuItem (10, "apple pie", 2),
    Menu::MenuItem (11, "ice cream", 2),
    Menu::MenuItem (12, "milkshake", 2)
    };
Kitchen kitchen;
Menu menu;
OrderComposer order_composer(menu,kitchen);

// Global functions
void invalidInput() {
    cout << "Error: invalid input, press any key to return to previous menu" << endl;
    cin;
}

int main() {

while(1) {

    switch(current_menu_idx) {

        case 1:

        // Start menu
        cout << "==================================================" << endl;
        cout << "||                                              ||" << endl;
        cout << "||            Welcome to McDonald's!            ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "||     Enter the characters in brackets []      ||" << endl;
        cout << "||     to select an option                      ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "|| [1] - Dine in                                ||" << endl;
        cout << "|| [2] - Take out                               ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "==================================================" << endl;
        cin >> user_input;
        try { input_idx = stoi(user_input); }
        catch(invalid_argument) { cout << "Invalid argument" << endl; }

        // Input handler
        switch(input_idx) {
            case 1:
            // Set order to dine in and move to main menu (index 2)
            order_composer.receiveOrderPartDineIn(1);
            current_menu_idx = 2;
            break;
            case 2:
            // Set order to take out and move to main menu (index 2)
            order_composer.receiveOrderPartDineIn(0);
            current_menu_idx = 2;
            break;
            default:
            invalidInput();
            break;
        }

        system("cls");
        break;

        case 2:

        // Main menu
        cout << "==================================================" << endl;
        cout << "||                                              ||" << endl;
        cout << "||      Select an item category to expand       ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "|| [1] - Burgers                                ||" << endl;
        cout << "|| [2] - Side items                             ||" << endl;
        cout << "|| [3] - Beverages                              ||" << endl;
        cout << "|| [4] - Desserts                               ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "|| [5] - Restart order                          ||" << endl;
        cout << "|| [6] - Go to checkout                         ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "==================================================" << endl;
        cin >> user_input; 
        try { input_idx = stoi(user_input); }
        catch(invalid_argument) { cout << "Invalid argument" << endl; }

        // Input handler
        switch(input_idx) {
            case 1:
            // Go to burgers menu (index 3)
            current_menu_idx = 3;
            break;
            case 2:
            // Go to side items menu (index 4)
            current_menu_idx = 4;
            break;
            case 3:
            // Go to beverages menu (index 5)
            current_menu_idx = 5;
            break;
            case 4:
            // Go to desserts menu (index 6)
            current_menu_idx = 6;
            break;
            case 5:
            // Restart program and empty cart
            current_menu_idx = 1;
            order_composer.clearOrder();
            break;
            case 6:
            // Go to checkout menu (index 7)
            current_menu_idx = 7;
            break;
            default:
            invalidInput();
            break;
        }

        system("cls");
        break;

        case 3:

        // Burgers submenu
        cout << "==================================================" << endl;
        cout << "||     Select a burger to add to your cart      ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "|| [1] - Hamburger                              ||" << endl;
        cout << "|| [2] - Cheeseburger                           ||" << endl;
        cout << "|| [3] - BigMac                                 ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "|| [4] - Back                                   ||" << endl;
        cout << "|| [5] - Go to checkout                         ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "==================================================" << endl;
        cin >> user_input;
        try { input_idx = stoi(user_input); }
        catch(invalid_argument) { cout << "Invalid argument" << endl; }

        // Input handler
        switch(input_idx) {
            case 1:
            // Add hamburger to order (index 1)
            order_composer.receiveOrderPartID(1);
            break;
            case 2:
            // Add cheeseburger to order (index 2)
            order_composer.receiveOrderPartID(2);
            break;
            case 3:
            // Add BigMac to order (index 3)
            order_composer.receiveOrderPartID(3);
            break;
            case 4:
            // Go to main menu (index 2)
            current_menu_idx = 2;
            break;
            case 5:
            // Go to checkout menu (index 7)
            current_menu_idx = 7;
            default:
            invalidInput();
            break;
        }

        system("cls");
        break;

        case 4:

        // Side items submenu
        cout << "==================================================" << endl;
        cout << "||    Select a side item to add to your cart    ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "|| [1] - Small fries                            ||" << endl;
        cout << "|| [2] - Medium fries                           ||" << endl;
        cout << "|| [3] - Large fries                            ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "|| [4] - Back                                   ||" << endl;
        cout << "|| [5] - Go to checkout                         ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "==================================================" << endl;
        cin >> user_input;
        try { input_idx = stoi(user_input); }
        catch(invalid_argument) { cout << "Invalid argument" << endl; }

        // Input handler
        switch(input_idx) {
            case 1:
            // Add small fries to order (index 4)
            order_composer.receiveOrderPartID(4);
            break;
            case 2:
            // Add medium fries to order (index 5)
            order_composer.receiveOrderPartID(5);
            break;
            case 3:
            // Add large fries to order (index 6)
            order_composer.receiveOrderPartID(6);
            break;
            case 4:
            // Go to main menu (index 2)
            current_menu_idx = 2;
            break;
            case 5:
            // Go to checkout menu (index 7)
            current_menu_idx = 7;
            default:
            invalidInput();
            break;
        }

        system("cls");
        break;

        case 5:

        // Beverages submenu
        cout << "==================================================" << endl;
        cout << "||    Select a beverage to add to your cart     ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "|| [1] - Cola                                   ||" << endl;
        cout << "|| [2] - Fanta                                  ||" << endl;
        cout << "|| [3] - Sprite                                 ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "|| [4] - Back                                   ||" << endl;
        cout << "|| [5] - Go to checkout                         ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "==================================================" << endl;
        cin >> user_input;
        try { input_idx = stoi(user_input); }
        catch(invalid_argument) { cout << "Invalid argument" << endl; }

        // Input handler
        switch(input_idx) {
            case 1:
            // Add cola to order (index 7)
            order_composer.receiveOrderPartID(7);
            break;
            case 2:
            // Add fanta to order (index 8)
            order_composer.receiveOrderPartID(8);
            break;
            case 3:
            // Add sprite to order (index 9)
            order_composer.receiveOrderPartID(9);
            break;
            case 4:
            // Go to main menu (index 2)
            current_menu_idx = 2;
            break;
            case 5:
            // Go to checkout menu (index 7)
            current_menu_idx = 7;
            default:
            invalidInput();
            break;
        }

        system("cls");
        break;

        case 6:

        // Desserts submenu
        cout << "==================================================" << endl;
        cout << "||     Select a dessert to add to your cart     ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "|| [1] - Apple pie                              ||" << endl;
        cout << "|| [2] - Ice cream                              ||" << endl;
        cout << "|| [3] - Milkshake                              ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "|| [4] - Back                                   ||" << endl;
        cout << "|| [5] - Go to checkout                         ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "==================================================" << endl;
        cin >> user_input;
        try { input_idx = stoi(user_input); }
        catch(invalid_argument) { cout << "Invalid argument" << endl; }

        // Input handler
        switch(input_idx) {
            case 1:
            // Add apple pie to order (index 10)
            order_composer.receiveOrderPartID(10);
            break;
            case 2:
            // Add ice cream to order (index 11)
            order_composer.receiveOrderPartID(11);
            break;
            case 3:
            // Add milkshake to order (index 12)
            order_composer.receiveOrderPartID(12);
            break;
            case 4:
            // Go to main menu (index 2)
            current_menu_idx = 2;
            break;
            case 5:
            // Go to checkout menu (index 7)
            current_menu_idx = 7;
            default:
            invalidInput();
            break;
        }

        system("cls");
        break;

        case 7:

        // Checkout menu
        cout << "==================================================" << endl;
        cout << "||                                              ||" << endl;
        cout << "||                    CHECKOUT                  ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "|| Total: " << order_composer.returnCashTotal() << "                               ||" << endl;
        cout << "|| [1] - Pay                                    ||" << endl;
        cout << "|| [2] - Cancel order                           ||" << endl;
        cout << "|| [3] - Return to menu                         ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "==================================================" << endl;
        cin >> user_input;
        try { input_idx = stoi(user_input); }
        catch(invalid_argument) { cout << "Invalid argument" << endl; }

        // Input handler
        switch(input_idx) {
            case 1:
            // Finish order
            order_composer.finishOrder();
            break;
            case 2:
            // Clear order and return to start menu (index 1)
            order_composer.clearOrder();
            current_menu_idx = 1;
            break;
            case 3:
            // Go to main menu (index 2)
            current_menu_idx = 2;
            break;
            default:
            invalidInput();
            break;
        }

        system("cls");
        break;

        default:
        break;
    }
}
return 0;
}