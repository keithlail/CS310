// Ch10Exercise21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class bankAccount {
private:
    static int nextAccountNumber;  // Static member to auto-increment account numbers
    string holderName;
    int accountNumber;
    string accountType;  // 'checking' or 'saving'
    double balance;
    double interestRate;  // Stored as a decimal, e.g., 0.05 for 5%

public:
    // Default constructor (for array initialization)
    bankAccount() : holderName(""), accountType(""), balance(0.0), interestRate(0.0) {
        accountNumber = nextAccountNumber++;  // Assign an account number even if default
    }

    // Constructor to initialize a new account
    bankAccount(string name, string type, double initialBalance, double rate)
        : holderName(name), accountType(type), balance(initialBalance), interestRate(rate) {
        accountNumber = nextAccountNumber++;  // Assign and increment the static account number
    }

    // Function to deposit money into the account
    void deposit(double amount) {
        balance += amount;
    }

    // Function to withdraw money from the account if sufficient balance exists
    bool withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds." << endl;
            return false;
        }
        balance -= amount;
        return true;
    }

    // Function to calculate and add interest to the balance
    void addInterest() {
        balance += balance * interestRate;
    }

    // Function to display account details
    void display() const {
        cout << "Account Holder: " << holderName << endl
            << "Account Number: " << accountNumber << endl
            << "Account Type: " << accountType << endl
            << "Balance: $" << balance << endl
            << "Interest Rate: " << (interestRate * 100) << "%" << endl;
    }
};

// Initialize static member of class bankAccount
int bankAccount::nextAccountNumber = 1;

int main() {
    // Array to hold up to 10 bank accounts
    bankAccount accounts[10];  // Initialize with default constructor
    accounts[0] = bankAccount("John Doe", "saving", 1500.0, 0.03);
    accounts[1] = bankAccount("Jane Smith", "checking", 1800.0, 0.01);

    // Display details of all initialized accounts
    for (int i = 0; i < 2; i++) {
        accounts[i].display();
        cout << "-----------------------" << endl;
    }

    // Perform some transactions
    accounts[0].deposit(200.0);
    accounts[1].withdraw(100.0);

    // Add interest to all initialized accounts
    for (int i = 0; i < 2; i++) {
        accounts[i].addInterest();
    }

    // Display details again to see the changes
    for (int i = 0; i < 2; i++) {
        accounts[i].display();
        cout << "-----------------------" << endl;
    }

    _getch();  // Wait for user input before closing
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
