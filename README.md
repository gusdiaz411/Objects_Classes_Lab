# BankAccount Class

A C++ class for simulating basic bank account operations such as creating accounts, depositing, withdrawing, and updating account holder information.  
This project also includes a menu-driven interface for managing multiple accounts using `std::vector`.

---

## Data Dictionary

| Attribute            | Data Type     | Description                                   |
|----------------------|---------------|-----------------------------------------------|
| `accountNumber`      | `std::string` | Unique identifier for the bank account.       |
| `accountHolderName`  | `std::string` | Name of the account holder.                   |
| `balance`            | `double`      | Current balance of the account.               |

---

## Methods List

| Method Signature                                      | Return Type   | Description                                   |
|-------------------------------------------------------|---------------|-----------------------------------------------|
| `BankAccount()`                                       | (Constructor) | Default constructor. Initializes empty account.|
| `BankAccount(accNum, holder, initialBalance)`         | (Constructor) | Parameterized constructor to set up an account.|
| `getAccountNumber() const`                            | `std::string` | Retrieves the account number.                 |
| `getAccountHolderName() const`                        | `std::string` | Retrieves the account holder’s name.          |
| `getBalance() const`                                  | `double`      | Retrieves the current balance.                |
| `setAccountHolderName(const std::string& newName)`    | `void`        | Updates the account holder’s name.            |
| `deposit(double amount)`                              | `void`        | Deposits money. Prints error if invalid.      |
| `withdraw(double amount)`                             | `void`        | Withdraws money. Handles insufficient funds.  |

---

## Program Features

- **Menu-driven interface** for managing accounts.
- Create multiple accounts using `std::vector`.
- Deposit and withdraw funds with input validation.
- Update account holder names.
- Display all accounts and their balances.
- Handles invalid inputs (non-numeric, negative amounts).
- Gracefully prevents overdrafts.

---

## Example Menu

===== Bank Account Management System =====

1. Create Account

2. View All Accounts

3. Deposit

4. Withdraw

5. Update Account Holder Name

6. Exit
Enter your choice:
