#pragma once
#include <iostream>
using namespace std;

struct Inventory {
	const int LGWGT = 5, MEDWGT = 3, SMWGT = 1;
	int large = 1500, medium = 1200, small = 7000;
	
};
struct Order {

	int large = 0, medium = 0, small = 0;
	int pounds = 0;
};
char MainMenu();
//pre:  prompts user for input
//post: returns user's input if option is valid

void printInventory(Inventory &inv);
//pre:  accepts no parameters
//post: prints the current inventory of chocolate

int GetVal(string str);
//pre:  accepts a string
//post: prints string relating to selected option. returns int value relating to selected option

void valCheck();
//pre:  accepts no parameters
//post: checks whether user input is an int or not. if it is not, clear cin to allow for another cin to be made.

void FillOrder(Inventory& inv, Order& ord);
//pre:  accepts Inventory and Order structs
//post: executes fill order option to purchase chocolate

void ExtractInventory(Inventory& inv, Order& ord, int pounds);
//pre:  accepts Inventory and Order structs as well as integer representing pounds of chocolate
//post: transfers the number of pounds in the inventory into the order struct.

void Receipt(Order& ord);
//pre:  accepts Order struct
//post: uses order to output amount of chocolate purchased as well as the price with and without extra fees.

double calcPrice(int bar, double price);
//pre:  accepts int of chocolate bars of a certain size and the price of the respective bar
//post: returns the product of bars and price

double total(double cost1, double cost2, double cost3);
//pre:  accepts 3 doubles
//post: returns the sum of all 3 doubles

double shipPrice(int pounds);
//pre:  accepts number of pounds as an int
//post: returns shipping price based on amount of pounds

void orderInv(Inventory& inv);
//pre:  accepts Inventory struct
//post: adds more inventory to the selected size bar