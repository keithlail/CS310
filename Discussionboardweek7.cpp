// Discussionboardweek7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>

int main() {
    const int rows = 3;
    const int cols = 3;
    int matrix[rows][cols] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

    // Print the matrix
    for (int i = 0; i <= rows; i++) {
        for (int j = 0; j <= cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    _getch(); // Wait for a key press
    return 0;
}

