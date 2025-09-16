#include <iostream>
#include <vector>
#include <string>
#include <limits> // for input validation

class BankAccount {
private:
    std::string accountNumber; // unique id for the account
    std::string accountHolderName; // name of the person who owns the account
    double balance; // current balance in the account

public:
    // default constructor sets everything to empty or zero
    BankAccount() : accountNumber(""), accountHolderName(""), balance(0.0) {}

    // constructor to initialize account with info
    BankAccount(const std::string& accNum, const std::string& holder, double initialBalance)
        : accountNumber(accNum), accountHolderName(holder), balance(initialBalance) {}

    // getters to see the account info
    std::string getAccountNumber() const { return accountNumber; }
    std::string getAccountHolderName() const { return accountHolderName; }
    double getBalance() const { return balance; }

    // lets you change the account holder name
    void setAccountHolderName(const std::string& newName) { accountHolderName = newName; }

    // deposit some money, prints message if invalid
    void deposit(double amount) {
        if (amount <= 0) {
            std::cout << "Deposit amount must be positive.\n";
            return;
        }
        balance += amount;
        std::cout << "Deposit successful! New balance: $" << balance << "\n";
    }

    // withdraw money, checks for negative amount or insufficient funds
    void withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "Withdrawal amount must be positive.\n";
            return;
        }
        if (amount > balance) {
            std::cout << "Insufficient funds.\n";
            return;
        }
        balance -= amount;
        std::cout << "Withdrawal successful! New balance: $" << balance << "\n";
    }
};

// utility function to safely read a double, keeps asking until input is valid
double readDouble() {
    double value;
    while (true) {
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Enter a number: ";
        } else {
            return value;
        }
    }
}

// utility function to safely read an int, same idea as readDouble
int readInt() {
    int value;
    while (true) {
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Enter a number: ";
        } else {
            return value;
        }
    }
}
// shows the main menu to the user
void showMenu() {
    std::cout << "\n===== Bank Account Management System =====\n";
    std::cout << "1. Create Account\n";
    std::cout << "2. View All Accounts\n";
    std::cout << "3. Deposit\n";
    std::cout << "4. Withdraw\n";
    std::cout << "5. Update Account Holder Name\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    // stores all the accounts
    std::vector<BankAccount> accounts;
    int choice;

    do {
        showMenu();
        // get the user's menu choice
        choice = readInt();

        switch (choice) {
        case 1: { // create a new account
            std::string accNum, name;
            double initialBalance;

            std::cout << "Enter account number: ";
            std::cin >> accNum;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush

            std::cout << "Enter account holder name: ";
            std::getline(std::cin, name);

            std::cout << "Enter initial balance: ";
            initialBalance = readDouble();

            accounts.emplace_back(accNum, name, initialBalance); // add new account to vector
            std::cout << "Account created successfully!\n";
            break;
        }

        case 2: { // view all accounts
            if (accounts.empty()) {
                std::cout << "No accounts found.\n";
            } else {
                std::cout << "\n--- Account List ---\n";
                for (const auto& acc : accounts) {
                    std::cout << "Account Number: " << acc.getAccountNumber() << "\n";
                    std::cout << "Account Holder: " << acc.getAccountHolderName() << "\n";
                    std::cout << "Balance: $" << acc.getBalance() << "\n";
                    std::cout << "-----------------------------\n";
                }
            }
            break;
        }

        case 3: { // deposit money
            std::string accNum;
            std::cout << "Enter account number to deposit into: ";
            std::cin >> accNum;

            double amount;
            std::cout << "Enter amount to deposit: ";
            amount = readDouble();

            bool found = false;
            for (auto& acc : accounts) {
                if (acc.getAccountNumber() == accNum) {
                    acc.deposit(amount);
                    found = true;
                    break;
                }
            }
            if (!found) std::cout << "Account not found.\n";
            break;
        }

        case 4: { // withdraw money
            std::string accNum;
            std::cout << "Enter account number to withdraw from: ";
            std::cin >> accNum;

            double amount;
            std::cout << "Enter amount to withdraw: ";
            amount = readDouble();

            bool found = false;
            for (auto& acc : accounts) {
                if (acc.getAccountNumber() == accNum) {
                    acc.withdraw(amount);
                    found = true;
                    break;
                }
            }
            if (!found) std::cout << "Account not found.\n";
            break;
        }

        case 5: { // update account holder name
            std::string accNum;
            std::cout << "Enter account number to update: ";
            std::cin >> accNum;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush

            std::string newName;
            std::cout << "Enter new account holder name: ";
            std::getline(std::cin, newName);

            bool found = false;
            for (auto& acc : accounts) {
                if (acc.getAccountNumber() == accNum) {
                    acc.setAccountHolderName(newName);
                    std::cout << "Account holder name updated successfully.\n";
                    found = true;
                    break;
                }
            }
            if (!found) std::cout << "Account not found.\n";
            break;
        }

        case 6: // exit the program
            std::cout << "Exiting program. Goodbye!\n";
            break;

        default: // invalid choice
            std::cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6); // keep looping until user chooses to exit

    return 0;
}
