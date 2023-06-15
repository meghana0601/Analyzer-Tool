#include <iostream>
#include <vector>
#include <string>

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
        cout << "Deposit of $" << amount << " successful. New balance: $" << balance << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawal of $" << amount << " successful. New balance: $" << balance << endl;
        } else {
            cout << "Insufficient funds. Withdrawal failed." << endl;
        }
    }

    void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Balance: $" << balance << endl;
    }
};

class Bank {
private:
    vector<Account> accounts;

public:
    void addAccount(Account account) {
        accounts.push_back(account);
        cout << "Account added successfully." << endl;
    }

    void removeAccount(string accountNumber) {
        for (int i = 0; i < accounts.size(); i++) {
            if (accounts[i].getAccountNumber() == accountNumber) {
                accounts.erase(accounts.begin() + i);
                cout << "Account removed successfully." << endl;
                return;
            }
        }
        cout << "Account not found." << endl;
    }

    Account* findAccount(string accountNumber) {
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

    Account acc1("123456", "John Doe", 1000.0);
    bank.addAccount(acc1);

    Account acc2("789012", "Jane Smith", 500.0);
    bank.addAccount(acc2);

    Account* acc3 = bank.findAccount("123456");
    if (acc3 != nullptr) {
        acc3->deposit(200.0);
        acc3->withdraw(300.0);
        acc3->display();
    } else {
        cout << "Account not found." << endl;
    }

    Account* acc4 = bank.findAccount("999999");
    if (acc4 != nullptr) {
        acc4->display();
    } else {
        cout << "Account not found." << endl;
    }

    bank.removeAccount("789012");

    return 0;
}
