/*
    Name: Zach Green
    Email: zjg6tp@umsystem.edu
    Course: CS201R-0001
    Teacher: Joan Gladbach
*/
#include <iostream> 
#include <iomanip>
using namespace std;

int main() {
    /* Initialize Variables */
    int lgInv = 150, medInv = 120, smInv = 700;
    const double LGPRICE = 30.50, MEDPRICE = 25.99, SMPRICE = 10.50;
    const int LGWGT = 5, MEDWGT = 3, SMWGT = 1, MAXWGT = (lgInv * LGWGT) + (medInv * MEDWGT) + (smInv * SMWGT);
    int usrWgt, lgBars = 0, medBars = 0, smBars = 0;
    double lgCost, medCost, smCost, totalCost;

    /* Get input from user */
    cout << "Enter your order in Pounds: ";
    cin >> usrWgt;

    /* User Order is within Boundaries of available Inventory */
    if (usrWgt <= MAXWGT && usrWgt > 0) {

        /*
           Calculate total bars. First if statement executes if there is enough inventory of a certain bar to fulfill the request.
           Subtracts required amount of bars from [size]Inv.
           Else if executes if there is not enough to fulfill the request.
           Subtracts entire inventory from [size]Inv.
        */

        if (usrWgt / LGWGT <= lgInv) {    // Large Bars
            lgBars = usrWgt / LGWGT;
            usrWgt -= lgBars * LGWGT;
        }
        else {
            lgBars = lgInv;
            usrWgt -= lgBars * LGWGT;
        }


        if (usrWgt / MEDWGT <= medInv) {    // Medium Bars
            medBars = usrWgt / MEDWGT;
            usrWgt -= medBars * MEDWGT;
        }
        else {
            medBars = medInv;
            usrWgt -= medBars * MEDWGT;
        }


        if (usrWgt / SMWGT <= smInv) {      // Small Bars
            smBars = usrWgt / SMWGT;
            usrWgt -= smBars * SMWGT;
        }
        else {
            smBars = smInv;
            usrWgt -= smBars * SMWGT;
        }

        /* Calculate Price of each Bar by multiplying the price by the amount of bars*/

        lgCost = LGPRICE * lgBars;                  // Large
        medCost = MEDPRICE * medBars;               // Medium
        smCost = SMPRICE * smBars;                  // Small
        totalCost = lgCost + medCost + smCost;      // Total

        /* Calculate Remaining Inventory by subtracting the bars taken from the inventory */
        lgInv -= lgBars;                            // Large
        medInv -= medBars;                          // Medium
        smInv -= smBars;                            // Small

        /* Print Output */
        cout << fixed << setprecision(2);                                   // Decimal reaches the hundredths place
        cout << "Large Bars: " << lgBars << " = $" << lgCost << endl;       // Large
        cout << "Medium Bars: " << medBars << " = $" << medCost << endl;    // Medium
        cout << "Small Bars: " << smBars << " = $" << smCost << endl;       // Small
        cout << "Total Cost: " << " = $" << totalCost << endl;              // Total

        cout << "Remaining Inventory:" << endl;
        cout << "Large: " << lgInv << endl;
        cout << "Medium: " << medInv << endl;
        cout << "Small: " << smInv << endl;
    }

    /* Order is either greater than available inventory or less than 0 */
    else
        cout << "I'm sorry, but we are unable to fulfill your request." << endl;

    return 0;
}