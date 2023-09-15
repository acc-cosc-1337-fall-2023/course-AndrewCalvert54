//write include statements
#include <iostream>
#include "hwexpressions.h"

using std::cout;
using std::cin;

//write namespace using statement for cout

int main()
{
	//Variables
	double meal_amount, tip_rate, tip_amount, tax_amount, total;

	//Capture meal amount
	std::cout << "Enter meal amount: ";
	std::cin >> meal_amount;

	//Calculate tax_amount using get_sales_tax_amount
	tax_amount = get_sales_tax_amount(meal_amount);

	//Capture tip rate
	std::cout << "Enter tip rate as a decimal: ";
	std::cin >> tip_rate;

	//Calculate tip_amount
	tip_amount = get_tip_amount(meal_amount, tip_rate);

	//Calculate Total
	total = meal_amount + tax_amount + tip_amount;

	//Display
	std::cout << "Meal Amount: " << meal_amount << std::endl;
	std::cout << "Sales Tax: " << tax_amount << std::endl;
	std::cout << "Tip Amount: " << tip_amount << std::endl;
	std::cout << "Total: " << total << std::endl;

	return 0;
}
