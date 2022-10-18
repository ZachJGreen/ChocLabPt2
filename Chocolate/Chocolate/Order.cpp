#include <iostream>
#include <iomanip>
#include "Order.h"
using namespace std;

char MainMenu() {
	char option = 'A';
	cout << "Main Menu" << endl;
	while (option == 'A') {
		cout << "Would you like to (F)ill an order, (P)rint Inventory, (O)rder Inventory, or (E)xit. Press a key and hit enter to choose an option." << endl;
		cin >> option;
		option = toupper(option);
		switch (option) {
		case 'F': case 'P': case 'O': case 'E':
			break;
		default:
			cout << "Invalid option. Please try again." << endl;
			option = 'A';
			break;
		}
	}
	return option;
}

void printInventory(Inventory &inv) {
	cout << "Current Inventory" << endl;
	cout << right << "Large Bars: "  << setw(12) << inv.large  << endl;
	cout << right << "Medium Bars: " << setw(11) << inv.medium << endl;
	cout << right << "Small Bars: "  << setw(12) << inv.small  << endl;
}
int GetVal(string str) {
	int input;
	cout << str << endl;
	cin >> input;
	while (input <= 0) {
		valCheck();
		cout << "Please enter a number greater than 0." << endl;
		cin >> input;
	}
	return input;
}
void valCheck() {
	if (cin.fail()) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid Input. Please try again." << endl;
	}
}
void FillOrder(Inventory &inv, Order &ord) {
	int maxWgt = (inv.large * inv.LGWGT) + (inv.medium * inv.MEDWGT) + (inv.small * inv.SMWGT);
	int pounds = GetVal("Please enter the number of pounds of chocolate in the order: ");
	ord.pounds += pounds;
	if (pounds > maxWgt) {
		cout << "I'm Sorry, but we do not have enough inventory to fulfill that request." << endl;
	}
	else {
		ExtractInventory(inv, ord, pounds);
		Receipt(ord);
	}

}

void ExtractInventory(Inventory &inv, Order &ord, int pounds) {
	int largeAdd = 0, medAdd = 0, smallAdd = 0;
	if (pounds / inv.LGWGT <= inv.large) {    // Large Bars
		largeAdd = pounds / inv.LGWGT;
		pounds -= largeAdd * inv.LGWGT;
		ord.large += largeAdd;
	}
	else {
		largeAdd = inv.large;
		pounds -= largeAdd * inv.LGWGT;
		ord.large += largeAdd;
	}

	if (pounds / inv.MEDWGT <= inv.medium) {    // Medium Bars
		medAdd = pounds / inv.MEDWGT;
		pounds -= medAdd * inv.MEDWGT;
		ord.medium += medAdd;
	}
	else {
		medAdd = inv.medium;
		pounds -= medAdd * inv.MEDWGT;
		ord.medium += medAdd;
	}

	if (pounds / inv.SMWGT <= inv.small) {      // Small Bars
		smallAdd = pounds / inv.SMWGT;
		pounds -= smallAdd * inv.SMWGT;
		ord.small += smallAdd;
	}
	else {
		smallAdd = inv.small;
		pounds -= smallAdd * inv.SMWGT;
		ord.medium += smallAdd;
	}

	inv.large -= largeAdd;
	inv.medium -= medAdd;
	inv.small -= smallAdd;
}

void Receipt(Order &ord) {
	const double LPRICE = 30.50, MPRICE = 25.99, SPRICE = 10.50;
	double l = calcPrice(ord.large, LPRICE), m = calcPrice(ord.medium, MPRICE), s = calcPrice(ord.small, SPRICE);
	double shipping = shipPrice(ord.pounds), sub = total(l, m, s), tax = sub * 0.075, grand = total(sub, tax, shipping);
	cout << fixed << setprecision(2);
	cout << right << "Large Bars: "  << setw(12) << ord.large  << setw(10) << l << endl;
	cout << right << "Medium Bars: " << setw(11) << ord.medium << setw(10) << m << endl;
	cout << right << "Small Bars: "  << setw(12) << ord.small  << setw(10) << s << endl;

	cout << endl;

	cout << right << "Sub Total: "   << setw(23) << sub      << endl;
	cout << right << "Tax Total: "   << setw(23) << tax      << endl;
	cout << right << "Shipping: "    << setw(24) << shipping << endl;
	cout << right << "Grand Total: " << setw(21) << grand    << endl;
}

double calcPrice(int bar, double price) {
	return bar * price;
}

double total(double cost1, double cost2, double cost3) {
	return cost1 + cost2 + cost3;
}

double shipPrice(int pounds) {
	if (pounds <= 0)
		return 0;
	else if (pounds > 0 && pounds <= 10)
		return 5.25;
	else if (pounds > 10 && pounds <= 20)
		return 7.75;
	else if (pounds > 20 && pounds <= 50)
		return 12.25;
	else
		return 19.75;
}

void orderInv(Inventory& inv) {
	char c;
	int unit;
	cout << "What size of bars do you wish to order? (L, M, S)" << endl;
	cin >> c;
	c = toupper(c);
	while (c != 'L' && c != 'M' && c != 'S') {
		cout << "Invalid Input. Please try again." << endl;
		cin >> c;
	}
	unit = GetVal("How many units of this size would you like?");
	switch (c) {
	case 'L':
		inv.large += unit;
		break;
	case 'M':
		inv.medium += unit;
		break;
	case 'S':
		inv.small += unit;
		break;
	}
	

}