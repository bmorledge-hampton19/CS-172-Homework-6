#pragma once

#include <fstream>
using namespace std;

class Complex {

private:
	double a; // The "a" in a + bi.  The real part of the complex number.
	double b; // The "b" in a + bi.  The imaginary part of the complex number.

public:
	Complex(); // Creates a complex object for the number 0.
	Complex(double a); // Creates a complex object with a given "a" and 0 as b.
	Complex(double a, double b); // Creates a complex object with given values for "a" and "b".

	// Functions to perform basic arithmetic operations with complex numbers as described by the book.
	Complex add(Complex c) const;
	Complex subtract(Complex c) const;
	Complex multiply(Complex c) const;
	Complex divide(Complex c) const;

	double abs(); // Return the absolute value of a complex number.

	string toString() const; // Returns the complex number as a string.

	//Overloading ALL the operators!!!!!
	
	// Operator overloading that uses the member arithmetic functions to perform the specified calcuation and return the value to the complex number that intiated the function.
	void operator+=(Complex c);
	void operator-=(Complex c);
	void operator*=(Complex c);
	void operator/=(Complex c);

	// Operator overloading that returns a for [0] and b for [1]
	double& operator[](int index);

	// Unary operator overloading for complex numbers.
	Complex operator+(); // Changes nothing before returning.
	Complex operator-(); // Returns the complex object with -a and -b.

	// Prefix operator overloading.  Only affects the a value.
	Complex& operator++();
	Complex& operator--();

	// Postfix operator overloading.  Only affects the a value.
	Complex operator++(int dummy);
	Complex operator--(int dummy);

	// Overloaded operators for the input and output operators.  Displays the complex number as a string, or reads in two values (a and b) for the Complex number.
	friend ostream& operator<<(ostream& out, const Complex& c);
	friend istream& operator>>(istream& in, Complex& c);

};

// Overloaded arithmetic operators that are non-member functions that act like the arithmetic member functions.
Complex operator+(const Complex& c1, const Complex& c2);
Complex operator-(const Complex& c1, const Complex& c2);
Complex operator*(const Complex& c1, const Complex& c2);
Complex operator/(const Complex& c1, const Complex& c2);

