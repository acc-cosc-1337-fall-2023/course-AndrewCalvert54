//add include statements
#include "repetition.h"

//add function(s) code here

// Function to calculate factorial using a loop
int factorial(int num) 
{
    if (num < 0)
        return -1; //Factorial is not defined for negative numbers

    int sum = 1;
    while (num > 0) {
        sum *= num;
        num--;
    }
    return sum;
}

// Function to calculate gcd using a loop
// Function to calculate gcd using a loop
int gcd(int num1, int num2) {
    while (num1 != num2) {
        if (num1 < num2) {
            int temp = num1;
            num1 = num2;
            num2 = temp;
        }
        num1 -= num2;
    }
    return num1;
}