/*
    Name:    Zach Green
    Email:   zjg6tp@umsystem.edu
    Course:  CS201R-0001
    Teacher: Joan Gladbach
*/
#include <iostream> 
#include <iomanip>
#include "Order.h";
using namespace std;

int main() {
    Inventory inv;
    Order order;
    bool cont = true;
    char mm = MainMenu();
    while (cont) {
        switch (mm) {
        case 'F':
            FillOrder(inv, order);
            cout << endl;
            break;
        case 'P':
            printInventory(inv);
            cout << endl;
            break;
        case 'O':
                orderInv(inv);
                cout << endl;
                break;
        case 'E':
            cont = false;
            Receipt(order);
            break;
        default:
            cout << "Invalid Input" << endl;
            break;
        }
        if (cont)
            mm = MainMenu();
    }
    cout << "Thank you for shopping with us!" << endl;
    return 0;
}