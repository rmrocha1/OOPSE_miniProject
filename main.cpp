// Main file for McDonald's ordering kiosk program

#include "kiosk.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

// Global variables
int current_menu_idx = 1;
string user_input = "";
int input_idx = 0;
string itemName;
int itemPrice;
time_t timestamp;
string timestamp_out;

Menu menu;
vector<Menu::MenuItem> menuVector = {
    Menu::MenuItem (1, "Hamburger", 4),
    Menu::MenuItem (2, "Cheeseburger", 5),
    Menu::MenuItem (3, "BigMac", 6),
    Menu::MenuItem (4, "Small Fries", 2),
    Menu::MenuItem (5, "Medium Fries", 3),
    Menu::MenuItem (6, "Large Fries", 4),
    Menu::MenuItem (7, "Coca-Cola", 2),
    Menu::MenuItem (8, "Fanta", 2),
    Menu::MenuItem (9, "Sprite", 2),
    Menu::MenuItem(10,"Apple Pie",2),
    Menu::MenuItem(11,"Ice Cream",2),
    Menu::MenuItem(12,"Milkshake",4)
    };
Kitchen kitchen;

OrderComposer order_composer(menu,kitchen);

// Global functions
void invalidInput() {
    system("cls");
    cout << "Error: invalid input" << endl;
}

int orderOfMagnitude(int a) {
    int order = 1;
    int order_comparator = 10;
    while(a >= order_comparator) {
        order_comparator = order_comparator * 10;
        order++;
    }
    return order;
}

void displayOrder() {

    int ID;
    string itemName;
    int itemPrice;
    int orderTotal = order_composer.returnCashTotal();

    if(order_composer.currentOrder.size() != 0) {
    for(int i = 0; i < order_composer.currentOrder.size(); i++) {
        ID = order_composer.currentOrder.at(i);
        itemName = order_composer.convertID2Name(ID);
        itemPrice = order_composer.convertID2Price(ID);
    cout << "|| " << i + 1 << ". " << itemName;
    for(int j = 0; j < (37 - itemName.size() - orderOfMagnitude(i + 1) - orderOfMagnitude(itemPrice)); j++)
    { cout << " "; } cout << "$ " << itemPrice << ".00 ||" << endl;
    }
    cout << "||- - - - - - - - - - - - - - - - - - - - - - - ||" << endl;
    cout << "|| Order total:";
    for(int i = 0; i < (27 - orderOfMagnitude(orderTotal)); i++)
    { cout << " "; } cout << "$ " << orderTotal << ".00 ||" << endl;
    } else {
    cout << "|| Your cart is empty...                        ||" << endl;
    }
}

int main() {
menu.menuVector = menuVector;
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
        cout << "|| [3] - Kitchen (protected)                    ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "==================================================" << endl;
        try { cin >> user_input; input_idx = stoi(user_input); }
        catch(...) { invalidInput(); }

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
            case 3:
            // Go to verification menu (index 9)
            current_menu_idx = 9;
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
        cout << "||==============================================||" << endl;
        cout << "||                                              ||" << endl;
        cout << "|| Your order:                                  ||" << endl;
        cout << "||                                              ||" << endl;
        displayOrder();
        cout << "||                                              ||" << endl;
        cout << "==================================================" << endl;
        try { cin >> user_input; input_idx = stoi(user_input); }
        catch(...) { invalidInput(); }

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
        cout << "|| [1] - Hamburger ..................... $ 4.00 ||" << endl;
        cout << "|| [2] - Cheeseburger .................. $ 5.00 ||" << endl;
        cout << "|| [3] - BigMac ........................ $ 6.00 ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "|| [4] - Back                                   ||" << endl;
        cout << "|| [5] - Go to checkout                         ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "||==============================================||" << endl;
        cout << "||                                              ||" << endl;
        cout << "|| Your order:                                  ||" << endl;
        cout << "||                                              ||" << endl;
        displayOrder();
        cout << "||                                              ||" << endl;
        cout << "==================================================" << endl;
        try { cin >> user_input; input_idx = stoi(user_input); }
        catch(...) { invalidInput(); }

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
            break;
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
        cout << "|| [1] - Small fries ................... $ 2.00 ||" << endl;
        cout << "|| [2] - Medium fries .................. $ 3.00 ||" << endl;
        cout << "|| [3] - Large fries ................... $ 4.00 ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "|| [4] - Back                                   ||" << endl;
        cout << "|| [5] - Go to checkout                         ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "||==============================================||" << endl;
        cout << "||                                              ||" << endl;
        cout << "|| Your order:                                  ||" << endl;
        cout << "||                                              ||" << endl;
        displayOrder();
        cout << "||                                              ||" << endl;
        cout << "==================================================" << endl;
        try { cin >> user_input; input_idx = stoi(user_input); }
        catch(...) { invalidInput(); }

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
            break;
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
        cout << "|| [1] - Coca-Cola ..................... $ 2.00 ||" << endl;
        cout << "|| [2] - Fanta ......................... $ 2.00 ||" << endl;
        cout << "|| [3] - Sprite ........................ $ 2.00 ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "|| [4] - Back                                   ||" << endl;
        cout << "|| [5] - Go to checkout                         ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "||==============================================||" << endl;
        cout << "||                                              ||" << endl;
        cout << "|| Your order:                                  ||" << endl;
        cout << "||                                              ||" << endl;
        displayOrder();
        cout << "||                                              ||" << endl;
        cout << "==================================================" << endl;
        try { cin >> user_input; input_idx = stoi(user_input); }
        catch(...) { invalidInput(); }

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
            break;
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
        cout << "|| [1] - Apple Pie ..................... $ 2.00 ||" << endl;
        cout << "|| [2] - Ice Cream ..................... $ 2.00 ||" << endl;
        cout << "|| [3] - Milkshake ..................... $ 4.00 ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "|| [4] - Back                                   ||" << endl;
        cout << "|| [5] - Go to checkout                         ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "||==============================================||" << endl;
        cout << "||                                              ||" << endl;
        cout << "|| Your order:                                  ||" << endl;
        cout << "||                                              ||" << endl;
        displayOrder();
        cout << "||                                              ||" << endl;
        cout << "==================================================" << endl;
        try { cin >> user_input; input_idx = stoi(user_input); }
        catch(...) { invalidInput(); }

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
            break;
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
        cout << "|| Review your order:                           ||" << endl;
        cout << "||                                              ||" << endl;
        displayOrder();
        cout << "||                                              ||" << endl;
        cout << "|| [1] - Pay and finish                         ||" << endl;
        cout << "|| [2] - Cancel order                           ||" << endl;
        cout << "|| [3] - Add more to order                      ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "==================================================" << endl;
        try { cin >> user_input; input_idx = stoi(user_input); }
        catch(...) { invalidInput(); }

        // Input handler
        switch(input_idx) {
            case 1:
            // Finish order and print receipt (menu index 8)
            current_menu_idx = 8;
            break;
            case 2:
            // Clear order and display cancelled order message (index 9)
            order_composer.clearOrder();
            current_menu_idx = 1;
            system("cls");
            cout << "==================================================" << endl;
            cout << "||                                              ||" << endl;
            cout << "||                ORDER CANCELED                ||" << endl;
            cout << "||                                              ||" << endl;
            cout << "==================================================" << endl;
            for(int i = 0; i < 1000000000; i++) {}
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

        case 8:
        // Get timestamp
        time(&timestamp);
        timestamp_out = ctime(&timestamp);
        timestamp_out.erase(timestamp_out.end() - 1);

        // Order receipt
        cout << "==================================================" << endl;
        cout << "||                                              ||" << endl;
        cout << "||";
        for(int i = 0; i < (30 - orderOfMagnitude(kitchen.incomingOrderID))/2; i++) { cout << " "; }
        cout << "RECEIT OF ORDER #" << kitchen.incomingOrderID;
        for(int i = 0; i < (30 - orderOfMagnitude(kitchen.incomingOrderID))/2; i++) { cout << " "; }
        cout << "||" << endl;
        cout << "||                                              ||" << endl;
        if(order_composer.getOrderPartDineIn() == 1) {
        cout << "|| Dine in                                      ||" << endl;
        } else {
        cout << "|| Take out                                     ||" << endl;
        }
        cout << "||                                              ||" << endl;
        displayOrder();
        cout << "||                                              ||" << endl;
        cout << "|| " << timestamp_out << "                     ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "==================================================" << endl;
        cout << "Press [1] to finish: ";
        try { cin >> user_input; input_idx = stoi(user_input); }
        catch(...) { invalidInput(); }
        if(input_idx == 1) {
            current_menu_idx = 1;
            order_composer.finishOrder();
            // order_composer.composeOrder();
            }
        else { invalidInput(); }

        system("cls");
        break;

        case 9:

        // Kitchen validation menu
        cout << "==================================================" << endl;
        cout << "||                                              ||" << endl;
        cout << "||   Enter the password or press [0] to exit    ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "==================================================" << endl;
        try { cin >> user_input; input_idx = stoi(user_input); }
        catch(...) { invalidInput(); }

        if(input_idx == 1234) {
            // Go to kitchen page
            current_menu_idx = 10;
        } else if(input_idx == 0) {
            // Exit validation screen
            current_menu_idx = 1;
        } else {
            // Display wrong password message and allow another try
            cout << "==================================================" << endl;
            cout << "||                                              ||" << endl;
            cout << "||                WRONG PASSWORD                ||" << endl;
            cout << "||                                              ||" << endl;
            cout << "==================================================" << endl;
        }
        for(int i = 0; i < 1000000000; i++) {}
        break;

        case 10:

        // Kitchen main menu
        cout << "==================================================" << endl;
        cout << "||                                              ||" << endl;
        cout << "||              under construction              ||" << endl;
        cout << "||                                              ||" << endl;
        cout << "==================================================" << endl;        

        system("cls");
        break;

        default:
        cout << "Something went wrong :(" << endl;
        break;
    }
}
return 0;
}