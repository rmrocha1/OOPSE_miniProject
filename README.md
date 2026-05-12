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
Run the resulting .exe

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
==================================================

Ordering menus typically look as follows:
==================================================
||     Select a burger to add to your cart      ||
||                                              ||
|| [1] - Hamburger                              ||
|| [2] - Cheeseburger                           ||
|| [3] - BigMac                                 ||
||                                              ||
|| [4] - Back                                   ||
|| [5] - Go to checkout                         ||
||                                              ||
==================================================

## Authors
Rafael Mantovani Rocha
Aleksander Miśta