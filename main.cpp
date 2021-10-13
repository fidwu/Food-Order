#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "Menu.h"
using namespace std ;

void orderItem(vector<Menu> &, vector<Menu> &, int) ;
void finishOrder(vector<Menu> &) ;

int main() {

    vector<Menu> orders ;
    vector<Menu> menu ;

    ifstream menuFile ;
    menuFile.open("menu.txt") ;

    if (!menuFile) {
        cout << "Error opening file." << endl ; 
    }
    else {
        cout << left << setw(9) << " "
             << "Lucky Food Court"
             << endl ;

        // Display menu
        cout << left << setw(4) << " "
             << setw(24) << "Item"
             << setw(6) << "Price"
             << endl ;

        string item ;
        double price ;
        string extra ;
        int itemNum = 1 ;

        while (menuFile)
        {
            if (getline(menuFile, item)) 
            {
                menuFile >> price ; 
                getline(menuFile, extra) ;

                cout << left << setw(4) << itemNum
                     << setw(23) << item
                     << right << setw(6) << price
                     << endl ;

                Menu menuItem(itemNum, item, price) ;

                menu.push_back(menuItem) ;
                itemNum++ ;
            }
        }

        menuFile.close() ;
    }

    int item ;

    do {
        cout << "\nEnter item number to order (or 0 when done): " ;
        cin >> item ;

        orderItem(menu, orders, item) ;

    } while (item != 0) ;

    cout << endl ;

    if (orders.size()) {
        finishOrder(orders) ;
    }

    return 0 ;
}

void orderItem(vector<Menu> &menu, vector<Menu> &orders, int itemNum) {

    // validate inputted item number
    if (!itemNum) {
        return ;
    }

    else if (itemNum > 0 && itemNum <= menu.size()) {
        int quantity = 0 ;
        do {
            cout << "Quantity: " ;
            cin >> quantity ;

            if (quantity == 0) {
                cout << "Error - Quantity can't be 0." << endl ;
            }

        } while (quantity == 0) ;

        if (quantity) {
            for (int i = 0 ; i < menu.size() ; i++) {
                if (itemNum == menu[i].getItemNum()) {

                    string item = menu[i].getItem() ;
                    double price = menu[i].getPrice() ;

                    Menu orderItem(itemNum, item, price, quantity) ;

                    orders.push_back(orderItem) ;

                    cout << quantity << " item #" << menu[i].getItemNum() << " (" << menu[i].getItem() << ") added to order list." << endl ;
                }
            }
        }
    }

    else {
        cout << "Error - Item number not found on the menu." << endl ;
    }

}

void finishOrder(vector<Menu> &orders) {
    double orderTotal = 0 ;

    cout << left << setw(11) << " "
         << "Order Summary"
         << endl ;

    string dashes ;
    dashes.assign(36, '-');
    cout << dashes << endl ;

    for (int i = 0 ; i < orders.size() ; i++) {
        string item = orders[i].getItem() ;
        double price = orders[i].getPrice() ;
        int quantity = orders[i].getQuantity() ;

        double itemTotal = price * quantity ;

        cout << fixed << setprecision(2) ;
        cout << left << setw(3) << quantity
             << setw(25) << item
             << "$ "
             << right << setw(6) << itemTotal
             << endl ;

        orderTotal += itemTotal ;
    }

    cout << endl 
         << left << setw(28) << "Total"
         << "$ "
         << right << setw(6) << orderTotal
         << endl ;
}
