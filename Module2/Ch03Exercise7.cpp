// Ch03Exercise7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <locale>

using namespace std;

int main() {
    // Variables to store user input.
    double netBalance, payment, interestRate;
    int d1, d2;

    // Prompting user for input.
    cout << "Enter the net balance: ";
    cin >> netBalance;
    cout << "Enter the payment made: ";
    cin >> payment;
    cout << "Enter the number of days in the billing cycle (d1): ";
    cin >> d1;
    cout << "Enter the number of days payment is made before the billing cycle ends (d2): ";
    cin >> d2;
    cout << "Enter the interest rate per month (e.g., 0.0152 for 1.52%): ";
    cin >> interestRate;

    // Calculating the average daily balance.
    double averageDailyBalance = (netBalance * d1 - payment * d2) / d1;

    // Calculating the interest.
    double interest = averageDailyBalance * interestRate;

    // Formatting the output to two decimal places and adding a thousands separator.
    cout << fixed << setprecision(2);
    locale loc(""); // Using the user's locale for the thousands separator.
    cout.imbue(loc);

    // Displaying the interest.
    cout << "The interest on the unpaid balance is: $" << interest << endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
