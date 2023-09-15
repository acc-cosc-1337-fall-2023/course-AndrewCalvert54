//write include statement for decisions header
#include "decisions.h"

//Write code for function(s) code here

// Function to convert numerical grade to letter grade using if-else
string get_letter_grade_using_if(int grade) {
    if (grade >= 90 && grade <= 100) {
        return "A";
    } else if (grade >= 80 && grade < 90) {
        return "B";
    } else if (grade >= 70 && grade < 80) {
        return "C";
    } else if (grade >= 60 && grade < 70) {
        return "D";
    } else if (grade >= 0 && grade < 60) {
        return "F";
    } else {
        return "Invalid";
    }
}

// Function to convert numerical grade to letter grade using switch
string get_letter_grade_using_switch(int grade) {
    if (grade < 0 || grade > 100) {
        return "Invalid";
    }

    switch (grade / 10) {
        case 10:
        case 9:
            return "A";
        case 8:
            return "B";
        case 7:
            return "C";
        case 6:
            return "D";
        default:
            return "F";
    }
}

