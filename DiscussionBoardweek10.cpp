// DiscussionBoardweek10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>

int main() {
    int* ptr = nullptr;
    int val = 10;

    ptr = val;
    std::cout << "Value: " << *ptr << std::endl;

    delete ptr; 

    _getch();
    return 0;
}


