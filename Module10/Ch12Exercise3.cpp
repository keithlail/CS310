// Ch12Exercise3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
Name Keith Lail
Assignment Ch12Exercise3
Date 05/18/24
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    int numCandidates;

    // Ask the user for the number of candidates
    cout << "Enter the number of candidates: ";
    cin >> numCandidates;

    // Dynamic allocation of arrays
    string* candidates = new string[numCandidates];
    int* votes = new int[numCandidates];
    int totalVotes = 0;

    // Input candidate names and votes
    for (int i = 0; i < numCandidates; ++i) {
        cout << "Enter the last name of candidate " << (i + 1) << ": ";
        cin >> candidates[i];
        cout << "Enter the number of votes received by " << candidates[i] << ": ";
        cin >> votes[i];
        totalVotes += votes[i];
    }

    // Output each candidate's name, votes, and vote percentage
    cout << "\nCandidate      Votes Received      % of Total Votes\n";
    cout << "------------------------------------------------------\n";
    for (int i = 0; i < numCandidates; ++i) {
        double percentage = (static_cast<double>(votes[i]) / totalVotes) * 100;
        cout << left << setw(15) << candidates[i]
            << setw(18) << votes[i]
            << fixed << setprecision(2) << percentage << "%\n";
    }

    // Determine the winner
    int maxVotes = votes[0];
    string winner = candidates[0];
    for (int i = 1; i < numCandidates; ++i) {
        if (votes[i] > maxVotes) {
            maxVotes = votes[i];
            winner = candidates[i];
        }
    }

    // Output the winner
    cout << "\nThe winner of the election is " << winner << " with " << maxVotes << " votes.\n";

    // Deallocate the dynamic arrays
    delete[] candidates;
    delete[] votes;

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
