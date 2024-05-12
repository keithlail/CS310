// Ch11Exercise13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
Name: Keith Lail
Assignment: Ch11Exercise13
Date: 5/11/24    
#include <iostream>
#include <conio.h>  // For _getch()

// Base class
class bankAccount {
protected:
    int accountNumber;
    double balance;

public:
    bankAccount(int accNum, double bal) : accountNumber(accNum), balance(bal) {}

    void setAccountNumber(int accNum) {
        accountNumber = accNum;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (balance >= amount)
            balance -= amount;
        else
            std::cout << "Insufficient funds.\n";
    }

    virtual void printAccountInfo() const {
        std::cout << "Account Number: " << accountNumber << "\nBalance: $" << balance << std::endl;
    }
};

// Derived class for checking accounts
class checkingAccount : public bankAccount {
private:
    double interestRate;
    double minimumBalance;
    double serviceCharges;

public:
    checkingAccount(int accNum, double bal, double interest, double minBal, double servCharge)
        : bankAccount(accNum, bal), interestRate(interest), minimumBalance(minBal), serviceCharges(servCharge) {}

    void setInterestRate(double rate) {
        interestRate = rate;
    }

    double getInterestRate() const {
        return interestRate;
    }

    void setMinimumBalance(double minBal) {
        minimumBalance = minBal;
    }

    double getMinimumBalance() const {
        return minimumBalance;
    }

    void setServiceCharges(double charge) {
        serviceCharges = charge;
    }

    double getServiceCharges() const {
        return serviceCharges;
    }

    void postInterest() {
        balance += balance * (interestRate / 100);
    }

    bool isBelowMinimumBalance() const {
        return balance < minimumBalance;
    }

    void writeCheck(double amount) {
        withdraw(amount);  // Write a check is essentially a withdrawal
    }

    void withdraw(double amount) override {
        if (balance - amount < minimumBalance)
            balance -= serviceCharges;
        bankAccount::withdraw(amount);
    }

    void printAccountInfo() const override {
        bankAccount::printAccountInfo();
        std::cout << "Interest Rate: " << interestRate << "%\n"
            << "Minimum Balance: $" << minimumBalance << "\n"
            << "Service Charges: $" << serviceCharges << std::endl;
    }
};

// Derived class for savings accounts
class savingsAccount : public bankAccount {
private:
    double interestRate;

public:
    savingsAccount(int accNum, double bal, double interest)
        : bankAccount(accNum, bal), interestRate(interest) {}

    void setInterestRate(double rate) {
        interestRate = rate;
    }

    double getInterestRate() const {
        return interestRate;
    }

    void postInterest() {
        balance += balance * (interestRate / 100);
    }

    void withdraw(double amount) override {
        bankAccount::withdraw(amount);
    }

    void printAccountInfo() const override {
        bankAccount::printAccountInfo();
        std::cout << "Interest Rate: " << interestRate << "%" << std::endl;
    }
};

int main() {
    checkingAccount myChecking(12345, 5000, 1.5, 300, 25);
    savingsAccount mySavings(67890, 3000, 0.5);

    std::cout << "Checking Account Initial State:\n";
    myChecking.printAccountInfo();
    myChecking.deposit(200);
    myChecking.writeCheck(1000);  // This includes handling for minimum balance and service charges
    myChecking.postInterest();
    std::cout << "Checking Account Final State:\n";
    myChecking.printAccountInfo();

    std::cout << "\nSavings Account Initial State:\n";
    mySavings.printAccountInfo();
    mySavings.deposit(100);
    mySavings.postInterest();
    std::cout << "Savings Account Final State:\n";
    mySavings.printAccountInfo();

    _getch();  // Wait for a key press
    return 0;
}


