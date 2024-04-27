// Ch08Exercise7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>  // for std::setprecision
#include <conio.h>  // for _getch()

int main() {
    const int NUM_CANDIDATES = 5;
    std::string names[NUM_CANDIDATES];
    int votes[NUM_CANDIDATES];
    int totalVotes = 0;
    int maxVotes = 0;
    int winnerIndex = 0;

    // Input phase
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        std::cout << "Enter candidate " << (i + 1) << "'s last name: ";
        std::cin >> names[i];
        std::cout << "Enter votes received by " << names[i] << ": ";
        std::cin >> votes[i];
        totalVotes += votes[i];

        if (votes[i] > maxVotes) {
            maxVotes = votes[i];
            winnerIndex = i;
        }
    }

    // Output phase
    std::cout << "\nElection Results:\n";
    std::cout << "Candidate\tVotes Received\t% of Total Votes\n";

    for (int i = 0; i < NUM_CANDIDATES; i++) {
        double percent = 100.0 * votes[i] / totalVotes;
        std::cout << std::left << std::setw(16) << names[i]
            << std::setw(16) << votes[i]
            << std::fixed << std::setprecision(2) << percent << "%\n";
    }

    // Announcing the winner
    std::cout << "\nThe winner of the election is " << names[winnerIndex] << ".\n";

    // Wait for key press before exiting
    std::cout << "\nPress any key to exit...\n";
    _getch();  // Wait for user input before closing the console window

    return 0;
}

