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
};

class Kitchen {
    private:
    map<int,vector<int>> orderStorage; //int order number, vector with ordered items (items have numerical IDs), int total $, int dine in or out

    public:
    int incomingOrderID = 1;

    void kitchenReceiveOrder(vector<int> incomingOrderContent) { 
        orderStorage.insert({incomingOrderID++, incomingOrderContent});
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
        
        int currentOrderDineInStorage; // store dinein to later put it at the end of currentOrder vector. 1 for dine in, 0 for take out
        Menu& menu;
        Kitchen& kitchen;
        
    public:
    vector<int> currentOrder; // one entry is one position in an order. a vector consists of a all item ids and dine in or out at the end
    OrderComposer(Menu& m, Kitchen& k) : menu(m), kitchen(k) {} // inherit menuVector from MenuItem class and kitchenReceiveOrder from Kitchen class

    void receiveOrderPartID(int receivedOrderPartID){ // receive an ID of an item from the menu and add it to currentOrder
        currentOrder.push_back(receivedOrderPartID);
    }

    void receiveOrderPartDineIn(int receivedOrderPartDineIn){ // 1 for dine in, 0 for take out
        currentOrderDineInStorage = receivedOrderPartDineIn;
    }

    int getOrderPartDineIn() { return currentOrderDineInStorage; }

    void finishOrder() { // add dine in or out to the end of the order vector
        currentOrder.push_back(currentOrderDineInStorage);
        composeOrder();
    }

    int convertID2Price(int receivedID){ // given an ID, this looks through all defined class members and looks for a match to find the assigned price
     
            for (int i = 0; i < menu.menuVector.size(); i++) {
                if (menu.menuVector.at(i).menuID == receivedID) {
                    return menu.menuVector.at(i).menuPrice;
                }
            }

        throw runtime_error("mcdonaldsCustomError: ID not found");
    };
    
    int returnCashTotal() {
    int cashTotal = 0;

        for (int i = 0; i < currentOrder.size(); i++)
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

    string convertID2Name(int ID) {
        for(auto item : menu.menuVector) {
            if(item.menuID == ID) {
                return item.menuItem;
            }
        }
    }
};

#endif // end "if not defined"