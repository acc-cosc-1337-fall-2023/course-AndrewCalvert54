//write include statements
#include <iostream>
#include "repetition.h"

//write using statements
using std::cout;
using std::cin;

int main() {
    int choice;
    bool exitConfirmed = false;

    do {
        cout << "Menu:" << '\n';
        cout << "1-Factorial" << '\n';
        cout << "2-Greatest Common Divisor" << '\n';
        cout << "3-Exit" << '\n';
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int num;
            cout << "Enter a positive integer for factorial calculation: ";
            cin >> num;

            if (num >= 0) {
                int result = factorial(num);
                cout << "Factorial of " << num << " is: " << result << '\n';
            } else {
                cout << "Invalid input. Please enter a non-negative integer." << '\n';
            }
        } else if (choice == 2) {
            int num1, num2;
            cout << "Enter two positive integers for GCD calculation (space-separated): ";
            cin >> num1 >> num2;

            if (num1 >= 0 && num2 >= 0) {
                int result = gcd(num1, num2);
                cout << "GCD of " << num1 << " and " << num2 << " is: " << result << '\n';
            } else {
                cout << "Invalid input. Please enter non-negative integers." << '\n';
            }
        } else if (choice == 3) {
            char confirm;
            cout << "Are you sure you want to exit? (y/n): ";
            cin >> confirm;

            if (confirm == 'y' || confirm == 'Y') {
                exitConfirmed = true;
                cout << "Exiting the program." << '\n';
            } else {
                cout << "Returning to the main menu." << '\n';
            }
        } else {
            cout << "Invalid choice. Please select a valid option." << '\n';
        }
    } while (!exitConfirmed);

    return 0;
}
