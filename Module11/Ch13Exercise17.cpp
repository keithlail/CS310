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
