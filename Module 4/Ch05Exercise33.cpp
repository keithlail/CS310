// Ch05Exercise33.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h> //

using namespace std;

int main() {
    int a, b, t, timeSum = 0, dishes = 0;

    cout << "Enter the time (in minutes) to prepare the first dish: ";
    cin >> a;
    cout << "Enter the additional time (in minutes) for each subsequent dish: ";
    cin >> b;
    cout << "Enter the total available time (in minutes) for preparation: ";
    cin >> t;

    // Calculation part
    while (timeSum + a <= t) {
        timeSum += a; // Update the total time spent
        a += b; // Increase the time needed for the next dish
        dishes++; // Increase the count of dishes prepared
    }

    cout << "Bianca can prepare " << dishes << " dishes." << endl;

    cout << "Press any key to exit.";
    _getch(); // Wait for a key press before closing the console window

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
