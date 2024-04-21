// Ch07Exercise4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

bool isVowel(char ch) {
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

std::string removeVowels(const std::string& input) {
    std::string result;
    for (char ch : input) {
        if (!isVowel(ch)) {
            result += ch;
        }
    }
    return result;
}

int main() {
    std::string str;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);
    std::string noVowels = removeVowels(str);
    std::cout << "String after removing vowels: " << noVowels << std::endl;
    return 0;
}
