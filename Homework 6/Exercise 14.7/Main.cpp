/////////////////////
// Ben Morledge-Hampton
// CS 172-1
// 11-8-2016
// Homework 6
/////////////////////

//Pre-Processor Directives
#include "Complex.h"
#include <iostream>
#include <string>
using namespace std;

// Main function
int main() {

	// Create two default complex numbers.
	Complex* c1 = new Complex();
	Complex* c2 = new Complex();

	// Prompt the user to enter values for the two complex numbers.

	cout << "Enter values for the first complex number: " << endl;
	cin >> *c1;
	cout << endl;

	cout << "Enter values for the second complex number: " << endl;
	cin >> *c2;
	cout << endl;

	// Display the results of the four basic arithmetic operators used on the two complex numbers.

	cout << c1->toString() << " + " << c2->toString() << " = " << (*c1 + *c2).toString() << endl;
	cout << c1->toString() << " - " << c2->toString() << " = " << (*c1 - *c2).toString() << endl;
	cout << c1->toString() << " * " << c2->toString() << " = " << (*c1 * *c2).toString() << endl;
	cout << c1->toString() << " / " << c2->toString() << " = " << (*c1 / *c2).toString() << endl;
	cout << endl;


	// Display the absolute value of the first number.
	cout << "Absolute value of the first complex number: " << (c1->abs()) << endl << endl;


	// Delete objects.
	delete c1;
	delete c2;


	// End function.  Everything is ok!
	return 0;

}