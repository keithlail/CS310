// Discussionboardweek11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h> // Include for _getch
using namespace std;

// Template function to find the maximum of two values
template <typename T>
T max(T a, T b) {
    // This function is intended to return the larger of two values a and b.
    return a > b ? a : b;
}

int main() {
    int x = 10;      // Declare an integer variable x and initialize it with 10.
    double y = 20.5; // Declare a double variable y and initialize it with 20.5.

    // This line intends to print the maximum of x and y using the max template function.
    cout << "The maximum is: " << max(x, y) << endl;

    // The next part intends to declare a template function to print a value.
    tempalte <typename T>
        void print(T value) {
        // This function is intended to print the value passed to it.
        cout << value << endl;
    }

    // This line intends to call the print function to print "Hello, World!" 
    print("Hello, World!");

    // Pause the program and wait for a key press
    cout << "Press any key to continue..." << endl;
    _getch(); // Waits for a key press

    return 0; // Indicate that the program ended successfully.
}
