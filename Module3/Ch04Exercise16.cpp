// Ch04Exercise16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip> // For std::setprecision

using namespace std;

// Named constants for the fixed royalties and royalty rates
const double OPTION1_FIXED_PAYMENT_1 = 5000.0;
const double OPTION1_FIXED_PAYMENT_2 = 20000.0;
const double OPTION2_ROYALTY_RATE = 0.125; // 12.5%
const double OPTION3_INITIAL_ROYALTY_RATE = 0.10; // 10% for the first 4000 copies
const double OPTION3_ADDITIONAL_ROYALTY_RATE = 0.14; // 14% beyond 4000 copies
const int OPTION3_THRESHOLD_COPIES = 4000;

int main() {
    double netPrice;
    int estimatedCopies;

    // Prompt the user for input
    cout << "Enter the net price of each copy of the novel: ";
    cin >> netPrice;
    cout << "Enter the estimated number of copies that will be sold: ";
    cin >> estimatedCopies;

    // Calculate royalties for each option
    double option1Royalties = OPTION1_FIXED_PAYMENT_1 + OPTION1_FIXED_PAYMENT_2;
    double option2Royalties = estimatedCopies * netPrice * OPTION2_ROYALTY_RATE;
    double option3Royalties = estimatedCopies <= OPTION3_THRESHOLD_COPIES ?
        estimatedCopies * netPrice * OPTION3_INITIAL_ROYALTY_RATE :
        OPTION3_THRESHOLD_COPIES * netPrice * OPTION3_INITIAL_ROYALTY_RATE +
        (estimatedCopies - OPTION3_THRESHOLD_COPIES) * netPrice * OPTION3_ADDITIONAL_ROYALTY_RATE;

    // Display the calculated royalties
    cout << fixed << setprecision(2); // Format the output to two decimal places
    cout << "Royalties under option 1: $" << option1Royalties << endl;
    cout << "Royalties under option 2: $" << option2Royalties << endl;
    cout << "Royalties under option 3: $" << option3Royalties << endl;

    // Determine and display the best option
    if (option1Royalties > option2Royalties && option1Royalties > option3Royalties) {
        cout << "The best option is Option 1." << endl;
    }
    else if (option2Royalties > option1Royalties && option2Royalties > option3Royalties) {
        cout << "The best option is Option 2." << endl;
    }
    else if (option3Royalties > option1Royalties && option3Royalties > option2Royalties) {
        cout << "The best option is Option 3." << endl;
    }
    else {
        cout << "Two or more options are equally profitable." << endl;
    }

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
