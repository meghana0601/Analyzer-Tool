#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account {
private:
  string accountNumber;
  string accountHolderName;
  double balance;

public:
  Account(string number, string name, double initialBalance) {
    accountNumber = number;
    accountHolderName = name;
    balance = initialBalance;
  }

  void deposit(double amount) {
    balance += amount;
    cout << "Deposit of $" << amount << " successful. New balance: $" << balance
         << endl;
  }

  void withdraw(double amount) {
    if (balance >= amount) {
      balance -= amount;
      cout << "Withdrawal of $" << amount << " successful. New balance: $"
           << balance << endl;
    } else {
      cout << "Insufficient funds. Withdrawal failed." << endl;
    }
  }

  double getBalance() const { return balance; }

  void display() const {
    cout << "Account Number: " << accountNumber << endl;
    cout << "Account Holder Name: " << accountHolderName << endl;
    cout << "Balance: $" << balance << endl;
  }
};

class Bank {
private:
  vector<Account> accounts;

public:
  void createAccount() {
    string number, name;
    double initialBalance;

    cout << "Enter account number: ";
    cin >> number;

    cout << "Enter account holder name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter initial balance: $";
    cin >> initialBalance;

    Account newAccount(number, name, initialBalance);
    accounts.push_back(newAccount);

    cout << "Account created successfully." << endl;
  }

  void performTransaction(string accountNumber) {
    Account *account = findAccount(accountNumber);
    if (account != nullptr) {
      int choice;
      double amount;

      cout << "1. Deposit" << endl;
      cout << "2. Withdraw" << endl;
      cout << "Enter your choice: ";
      cin >> choice;

      switch (choice) {
      case 1:
        cout << "Enter amount to deposit: $";
        cin >> amount;
        account->deposit(amount);
        break;
      case 2:
        cout << "Enter amount to withdraw: $";
        cin >> amount;
        account->withdraw(amount);
        break;
      default:
        cout << "Invalid choice." << endl;
        break;
      }
    } else {
      cout << "Account not found." << endl;
    }
  }

  void displayAccount(string accountNumber) const {
    Account *account = findAccount(accountNumber);
    if (account != nullptr) {
      account->display();
    } else {
      cout << "Account not found." << endl;
    }
  }

private:
  Account *findAccount(string accountNumber) {
    for (int i = 0; i < accounts.size(); i++) {
      if (accounts[i].getAccountNumber() == accountNumber) {
        return &accounts[i];
      }
    }
    return nullptr;
  }
};

int main() {
  Bank bank;

  int choice;
  string accountNumber;

  do {
    cout << "1. Create Account" << endl;
    cout << "2. Perform Transaction" << endl;
    cout << "3. Display Account Details" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      bank.createAccount();
      break;
    case 2:
      cout << "Enter account number: ";
      cin >> accountNumber;
      bank.performTransaction(accountNumber);
      break;
    case 3:
      cout << "Enter account number: ";
      cin >> accountNumber;
      bank.displayAccount(accountNumber);
      break;
    case 4:
      cout << "Exiting..." << endl;
      break;
    default:
      cout << "Invalid choice." << endl;
      break;
    }

    cout << endl;

  } while (choice != 4);

  return 0;
}
