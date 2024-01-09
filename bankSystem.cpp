#include <iostream>
#include <map>

using namespace std;

class BankAccount
{
private:
    string name;
    double balance;

public:
    BankAccount(string name)
    {
        this->name = name;
        balance = 0;
    }

    BankAccount()
    {
        name = "";
        balance = 0;
        cout << "Default constructor called" << endl;
    }

    ~BankAccount()
    {
        cout << "Destructor called" << endl;
    }

    bool deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            return true;
        }
        else
            return false;
    }

    double withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            return amount;
        }
        else
        {
            cout << "Insufficient funds" << endl;
            return 0;
        }
    }

    void viewBalance()
    {
        cout << "Balance is: " << balance << endl;
    }
};

int main()
{
    map<string, BankAccount> accounts;
    bool running = true;
    string currentUser;

    // welcome user
    cout << "Welcome!\n"
         << endl;

    // Ask for name and create an account
    cout << "Enter your name" << endl;
    cin >> currentUser;
    BankAccount *account = new BankAccount(currentUser);

    // Use emplace to directly construct the BankAccount in-place
    accounts.emplace(currentUser, *account);

    delete account;

    // Program loop
    while (running)
    {
        // Ask for action: (withdraw, deposit, viewBalance, close program)
        int choice;
        cout << "Choose an action:" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. View Balance" << endl;
        cout << "4. Close Program" << endl;
        cout << "Enter your choice: 1-4";
        cout << "\n"
             << endl;
        cin >> choice;

        switch (choice)
        {
            // Deposit
        case 1:
        {
            double amount;
            cout << "Enter deposit amount: ";
            cin >> amount;
            accounts[currentUser].deposit(amount);
            break;
        }
        case 2:
        {
            // Withdraw
            double amount;
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            accounts[currentUser].withdraw(amount);
            break;
        }
            // View balance
        case 3:
            accounts[currentUser].viewBalance();
            break;
        case 4:
            // Quit
            running = false;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
            break;
        }
    }

    return 0;
}