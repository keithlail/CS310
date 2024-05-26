// Ch13Exercise17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <conio.h> // For _getch

int main() {
    // Seed with a real random value, if available
    std::random_device rd;

    // Initialize a random number generator
    std::mt19937 gen(rd());

    // Define the range for the random numbers
    std::uniform_real_distribution<> dis(10.0, 100.0);

    // Generate and print 25 random numbers
    std::cout << "25 random real numbers between 10 and 100:" << std::endl;
    for (int i = 0; i < 25; ++i) {
        std::cout << dis(gen) << std::endl;
    }

    // Wait for a key press before exiting
    std::cout << "Press any key to continue..." << std::endl;
    _getch();

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
