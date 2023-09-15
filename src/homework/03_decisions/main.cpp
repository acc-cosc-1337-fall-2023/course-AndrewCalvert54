//write include statements
#include <iostream>
#include "decisions.h"

using std::cout;
using std::cin;
using std::string;

// Letter grade using if
void option1() {
    int grade;
    cout << "Enter numerical grade (0-100): ";
    cin >> grade;

    if (grade >= 0 && grade <= 100) {
        string letter_grade = get_letter_grade_using_if(grade);
        cout << "Letter grade using if: " << letter_grade << '\n';
    } else {
        cout << "Number is out of range (0-100).\n";
    }
}

//Letter grade using switch
void option2() {
    int grade;
    cout << "Enter numerical grade (0-100): ";
    cin >> grade;

    if (grade >= 0 && grade <= 100) {
        string letter_grade = get_letter_grade_using_switch(grade);
        cout << "Letter grade using switch: " << letter_grade << '\n';
    } else {
        cout << "Number is out of range (0-100).\n";
    }
}

int main() {
    int choice;

    // Display the main menu
    cout << "\nMAIN MENU\n";
    cout << "1-Letter grade using if\n";
    cout << "2-Letter grade using switch\n";
    cout << "3-Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            option1();
            break;
        case 2:
            option2();
            break;
        case 3:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice.\n";
    }

    return 0;
}