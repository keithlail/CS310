// Ch14Exercise1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stdexcept>
#include <conio.h> // for _getch
#include <cstdlib> // for system("CLS")

class negativeNumber : public std::runtime_error {
public:
    negativeNumber() : std::runtime_error("Negative number entered.") {}
};

class nonNumber : public std::runtime_error {
public:
    nonNumber() : std::runtime_error("Non-digit character entered.") {}
};

double getLengthInFeet() {
    std::string input;
    std::cout << "Enter length in feet: ";
    std::getline(std::cin, input);

    for (char ch : input) {
        if (!isdigit(ch) && ch != '-' && ch != '.') {
            throw nonNumber();
        }
    }

    double feet = std::stod(input);
    if (feet < 0) {
        throw negativeNumber();
    }

    return feet;
}

double getLengthInInches() {
    std::string input;
    std::cout << "Enter length in inches: ";
    std::getline(std::cin, input);

    for (char ch : input) {
        if (!isdigit(ch) && ch != '-' && ch != '.') {
            throw nonNumber();
        }
    }

    double inches = std::stod(input);
    if (inches < 0) {
        throw negativeNumber();
    }

    return inches;
}

int main() {
    while (true) {
        try {
            double feet = getLengthInFeet();
            double inches = getLengthInInches();

            double totalInches = (feet * 12) + inches;
            double centimeters = totalInches * 2.54;

            std::cout << "Equivalent length in centimeters: " << centimeters << " cm" << std::endl;

            std::cout << "Press any key to exit...";
            _getch();
            break;
        }
        catch (const negativeNumber& e) {
            std::cout << "Error: " << e.what() << std::endl;
            std::cout << "Please enter positive numbers." << std::endl;
        }
        catch (const nonNumber& e) {
            std::cout << "Error: " << e.what() << std::endl;
            std::cout << "Please enter valid numbers." << std::endl;
        }
        std::cout << "Press any key to try again...";
        _getch();
        system("CLS");
    }

    return 0;
}
