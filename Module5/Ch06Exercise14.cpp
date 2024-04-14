// Ch06Exercise14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

// Function to calculate billing amount
double calculateBillingAmount(double hourlyRate, int consultingTime, bool isLowIncome) {
    double billingAmount = 0.0;

    if (isLowIncome) {
        if (consultingTime > 30) {
            // Calculate charge for the time over 30 minutes at 40% of the hourly rate
            int extraTime = consultingTime - 30; // time in minutes over 30
            billingAmount = (hourlyRate * 0.40) * (extraTime / 60.0);
        }
    }
    else {
        if (consultingTime > 20) {
            // Calculate charge for the time over 20 minutes at 70% of the hourly rate
            int extraTime = consultingTime - 20; // time in minutes over 20
            billingAmount = (hourlyRate * 0.70) * (extraTime / 60.0);
        }
    }

    return billingAmount;
}

int main() {
    double hourlyRate;
    int consultingTime;
    char incomeStatus;
    bool isLowIncome;

    // Input section
    std::cout << "Enter the hourly rate: ";
    std::cin >> hourlyRate;

    std::cout << "Enter the total consulting time in minutes: ";
    std::cin >> consultingTime;

    std::cout << "Does the person have low income? (Y/N): ";
    std::cin >> incomeStatus;

    isLowIncome = (incomeStatus == 'Y' || incomeStatus == 'y');

    // Calculate the billing amount
    double billingAmount = calculateBillingAmount(hourlyRate, consultingTime, isLowIncome);

    // Output the result
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "The billing amount is $" << billingAmount << std::endl;

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
