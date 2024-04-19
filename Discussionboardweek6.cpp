// Discussionboardweek6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// Define an enumeration for days of the week
enum Day { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

int main() {
    Day today = Sunday;

    cout << "Today is " << today << std::endl;

    std::cout << "Numeric value of today: " << today << std::endl;

    return 0;
}
