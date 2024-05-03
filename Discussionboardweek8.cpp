// Discussionboardweek8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <conio.h>  // Include for _getch()

// Class to represent a Book
class Book {
public:
    std::string title;
    std::string author;

    // Constructor to initialize a Book object with title and author
    Book(std::string t, std::string a) : title(t), author(a) {}

    // Function to display book information
    void display() {
        std::cout << "Book: " << title << " by " << author << std::endl;
    }
};

// Class to represent a Library
class Library {
public:
    Book books[5];
    int numBooks = 0;  // Initialized to 0 to keep track of the number of books

    // Adds a book to the library
    void addBook(Book book) {
        if (numBooks < 5) {
            books[numBooks++] = book;
        }
    }

    // Displays all books in the library
    void showLibrary() {
        for (int i = 0; i < numBooks; i++) {
            books[i].display();
        }
    }
};

int main() {
    Library lib;

    // Creating and adding new books to the library
    lib.addBook(Book("1984", "George Orwell"));
    lib.addBook(Book("To Kill a Mockingbird", "Harper Lee"));

    // Displaying all books in the library
    lib.showLibrary();

    // Wait for user input to close console window
    std::cout << "Press any key to exit." << std::endl;
    _getch();  // Captures a key press without showing it in the console

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
