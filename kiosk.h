#ifndef KIOSK_H  // if not defined – if KIOSK_H has not been defined yet
#define KIOSK_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream> 
#include <iomanip>

using namespace std;

class Kiosk {
    private:
        int kioskID;

    public:
        bool kioskOutOfOrder;

    Kiosk(int a, bool b) {
        kioskID = a;
        kioskOutOfOrder = b;
    }

    map<int,bool> returnKioskState() { // returns a map with the kiosk ID and its state
        map<int,bool> tempMap;
        tempMap.insert({kioskID, kioskOutOfOrder});
        return tempMap;
    }
};

class Menu {
    private:

    public:
    string menuItem;
    int menuPrice;
    int menuID;

    class MenuItem {
        public:
        string menuItem;
        int menuPrice;
        int menuID;

        MenuItem(int a, string b, int c) {
            menuID = a;
            menuItem = b;
            menuPrice = c;
        }
    };
    vector<Menu::MenuItem> menuVector;

    /* PUT THIS INTO MAIN.CPP
    vector<Menu::MenuItem> menuVector = {
    Menu::MenuItem (1, "hamburger", 4),
    Menu::MenuItem (2, "cheeseburger", 5),
    Menu::MenuItem (3, "big mac", 6),
    Menu::MenuItem (4, "small fries", 2),
    Menu::MenuItem (5, "medium fries", 3),
    Menu::MenuItem (6, "large fries", 4),
    Menu::MenuItem (7, "coca-cola", 2),
    Menu::MenuItem (8, "fanta", 2),
    Menu::MenuItem (9, "sprite", 2)
    };*/
};

class Kitchen {
    private:
    map<int,vector<int>> orderStorage; //int order number, vector with ordered items (items have numerical IDs), int total $, int dine in or out

    public:
    int incomingOrderID = 0;

    void kitchenReceiveOrder(vector<int> incomingOrderContent) { 
        orderStorage.insert({incomingOrderID, incomingOrderContent});
        incomingOrderID++;
    }

    void kitchenEraseOrder(int orderID) { // erase the order with the given ID
        orderStorage.erase(orderID);
    }

    void coutOrders() { // show all orders currently in storage
        for (auto x : orderStorage) {
            cout << "Order ID: " << x.first << " Order content: ";
            for (int i = 0; i < x.second.size(); i++) {
                cout << x.second[i] << " ";
            }
            cout << endl;
        }
    }
};

class OrderComposer {
    private:
        vector<int> currentOrder; // one entry is one position in an order. a vector consists of a all item ids and dine in or out at the end
        int currentOrderDineInStorage; // store dinein to later put it at the end of currentOrder vector. 1 for dine in, 0 for take out
        Menu& menu;
        Kitchen& kitchen;
        
    public:
    OrderComposer(Menu& m, Kitchen& k) : menu(m), kitchen(k) {} // inherit menuVector from MenuItem class and kitchenReceiveOrder from Kitchen class

    void receiveOrderPartID(int receivedOrderPartID){ // receive an ID of an item from the menu and add it to currentOrder
        currentOrder.push_back(receivedOrderPartID);
    }

    void receiveOrderPartDineIn(int receivedOrderPartDineIn){ // 1 for dine in, 0 for take out
        currentOrderDineInStorage = receivedOrderPartDineIn;
    }

    void finishOrder() { // add dine in or out to the end of the order vector
        currentOrder.push_back(currentOrderDineInStorage);
        composeOrder();
    }

    int convertID2Price(int receivedID){ // given an ID, this looks through all defined class members and looks for a match to find the assigned price
        for (const auto& item : menu.menuVector) {
            if (item.menuID == receivedID) {
                return item.menuPrice;
            }
        }

        throw runtime_error("ID not found");
    };
    
    int returnCashTotal() {
    int cashTotal = 0;

        for (int i = 0; i < currentOrder.size() - 1; i++)
        {
            cashTotal += convertID2Price(currentOrder[i]);
        }

        return cashTotal;
    }

    void clearOrder() {
        currentOrder.clear();
    }
    
    void composeOrder(){
        vector<int> composedOrder;

        for (int i = 0; i <= currentOrder.size()-1; i++) { // extract items from composed order
            composedOrder.push_back(currentOrder[i]);
        }

        composedOrder.push_back(returnCashTotal()); // complete the order vector by adding the cash total

        currentOrder.clear();

        kitchen.kitchenReceiveOrder(composedOrder); // send the composed order to the kitchen
    }
};

#endif // end "if not defined"