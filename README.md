# McDonald's Kiosk System
Connects the kiosk screen with the kitchen by handling order completion and transfer.

## Table of contents
* [Description](#description)
* [How to Run](#how-to-run)
* [Example Output](#example-output)
* [Authors](#authors)

## Description
The backend consists of a menu item ID system, order completion from user input, calculating cash total, and communication between the kiosk and the kitchen. The frontend allows for user input by going through the menu step-by-step, and feedback from the backend.

## How to run
Compile:
g++ main.cpp -o program
Run the resulting program.exe

Then select an option from the menu by pressing on the according number on your keyboard and then pressing enter.

## Example output

Once started, the program will show the following menu:
==================================================
||                                              ||
||            Welcome to McDonald's!            ||
||                                              ||
||     Enter the characters in brackets []      ||
||     to select an option                      ||
||                                              ||
|| [1] - Dine in                                ||
|| [2] - Take out                               ||
||                                              ||
|| [3] - Kitchen (protected)                    ||
||                                              ||
==================================================

Ordering menus typically look as follows:
==================================================
||    Select a beverage to add to your cart     ||
||                                              ||
|| [1] - Coca-Cola ..................... $ 2.00 ||
|| [2] - Fanta ......................... $ 2.00 ||
|| [3] - Sprite ........................ $ 2.00 ||
||                                              ||
|| [4] - Back                                   ||
|| [5] - Go to checkout                         ||
||                                              ||
||==============================================||
||                                              ||
|| Your order:                                  ||
||                                              ||
|| 1. Cheeseburger                       $ 5.00 ||
|| 2. Medium Fries                       $ 3.00 ||
||- - - - - - - - - - - - - - - - - - - - - - - ||
|| Order total:                          $ 8.00 ||
||                                              ||
==================================================
The bottom part of the display updates as items are added to the order.

After ordering, a receipt is produced.
==================================================
||                                              ||
||              RECEIPT OF ORDER #1             ||
||                                              ||
|| Dine in                                      ||
||                                              ||
|| 1. Cheeseburger                       $ 5.00 ||
|| 2. Medium Fries                       $ 3.00 ||
|| 3. Coca-Cola                          $ 2.00 ||
|| 4. Apple Pie                          $ 2.00 ||
||- - - - - - - - - - - - - - - - - - - - - - - ||
|| Order total:                         $ 12.00 ||
||                                              ||
|| Sun May 17 20:33:17 2026                     ||
||                                              ||
==================================================

The program may also be used by the kitchen staff who have a password to access
the following proteceted menu:
==================================================
||                                              ||
||       It's always a good day to work         ||
||       at McDonald's!                         ||
||                                              ||
|| [1] - View an order                          ||
|| [2] - Delete an order                        ||
|| [3] - See all orders                         ||
||                                              ||
|| [4] - Exit                                   ||
||                                              ||
==================================================

## Authors
Rafael Mantovani Rocha
Aleksander Miśta