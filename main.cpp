#include <iostream>
#include <string> // library for string manipulation

using namespace std;

class ATM { //class blueprint
private: // private variables
    string pin;
    double balance;

public: //public variables
    ATM(string initialPin, double initialBalance) {
        pin = initialPin;
        balance = initialBalance;
    }

    bool verifyPin(string enteredPin) { //change pin state
        return enteredPin == pin;
    }

    void showMenu() {
        cout << "\n--- ATM Menu ---" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Withdraw Cash" << endl;
        cout << "3. Change PIN" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
    }

    void checkBalance() {
        cout << "\nYour current balance is: Tshs. " << balance << endl;
    }

    void withdrawCash() {
        double amount;
        cout << "\nEnter the amount to withdraw: Tshs. ";
        cin >> amount;

        if (amount > balance) {
            cout << "Insufficient funds." << endl;
        } else if (amount <= 0) {
            cout << "Invalid amount entered." << endl;
        } else {
            balance -= amount;
            cout << "Tshs. " << amount << " withdrawn successfully. Your new balance is Tshs. " << balance << endl;
        }
    }

    void changePin() {
        string oldPin, newPin, confirmPin;
        cout << "\nEnter your current PIN: ";
        cin >> oldPin;

        if (verifyPin(oldPin)) {
            cout << "Enter new PIN: ";
            cin >> newPin;
            cout << "Confirm new PIN: ";
            cin >> confirmPin;

            if (newPin == confirmPin) {
                pin = newPin;
                cout << "PIN changed successfully." << endl;
            } else {
                cout << "New PINs do not match. Try again." << endl;
            }
        } else {
            cout << "Incorrect current PIN." << endl;
        }
    }
};

int main() {
    ATM myATM("1234", 100000.00); // Default PIN and balance

    string enteredPin; //if change pin state issued
    cout << "\nWelcome to the ATM. Please enter your PIN: ";
    cin >> enteredPin;

    if (myATM.verifyPin(enteredPin)) {
        int choice; // variable to store choices
        do {
            myATM.showMenu(); //instance if pin is authenticated
            cin >> choice;

            switch (choice) {
                case 1:
                    myATM.checkBalance();
                    break;
                case 2:
                    myATM.withdrawCash();
                    break;
                case 3:
                    myATM.changePin();
                    break;
                case 4:
                    cout << "Thank you for using the ATM. Goodbye!" << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 4); // if pin is wrong
    } else {
        cout << "Incorrect PIN. Access denied." << endl;
    }

    return 0;
}