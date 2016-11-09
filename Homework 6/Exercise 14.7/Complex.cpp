#include "Complex.h"

#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


Complex operator+(const Complex & c1, const Complex & c2)
{
	return c1.add(c2);
}

Complex operator-(const Complex & c1, const Complex & c2)
{
	return c1.subtract(c2);
}

Complex operator*(const Complex & c1, const Complex & c2)
{
	return c1.multiply(c2);
}

Complex operator/(const Complex & c1, const Complex & c2)
{
	return c1.divide(c2);
}

ostream & operator<<(ostream & out, const Complex & c)
{
	out << c.toString(); // output the complex number as a string.
	return out; // Return the output stream.
}

istream & operator>>(istream & in, Complex & c)
{
	// Prompt the user to give values for a and b, and input them using the input stream.
	cout << "Input a: ";
	in >> c.a;
	cout << "Input b: ";
	in >> c.b;

	return in; // Return the input stream.
}

Complex::Complex()
{
	a = 0;
	b = 0;
}

Complex::Complex(double a)
{
	this->a = a;
	b = 0;
}

Complex::Complex(double a, double b)
{
	this->a = a;
	this->b = b;
}

Complex Complex::add(Complex c) const
{
	// Calculate the real and imaginary parts of the complex number into two corresponding variables.
	double a = this->a + c.a;
	double b = this->b + c.b;

	// Use those variables to create a new Complex object and return it.
	return Complex(a, b);
}

Complex Complex::subtract(Complex c) const
{
	// Calculate the real and imaginary parts of the complex number into two corresponding variables.
	double a = this->a - c.a;
	double b = this->b - c.b;

	// Use those variables to create a new Complex object and return it.
	return Complex(a, b);
}

Complex Complex::multiply(Complex c) const
{
	// Calculate the real and imaginary parts of the complex number into two corresponding variables.
	double a = this->a * c.a - this->b * c.b ;
	double b = this->b * c.a + this->a * c.b;

	// Use those variables to create a new Complex object and return it.
	return Complex(a, b);
}

Complex Complex::divide(Complex c) const
{
	// Calculate the real and imaginary parts of the complex number into two corresponding variables.
	double a = (this->a * c.a + this->b * c.b) / (c.a*c.a+c.b*c.b);
	double b = (this->b * c.a - this->a * c.b) / (c.a*c.a + c.b*c.b);

	// Use those variables to create a new Complex object and return it.
	return Complex(a, b);
}

double Complex::abs()
{
	// Return the double from the given equation for absolute value of a complex number.
	return sqrt(a*a+b*b);
}

string Complex::toString() const
{
	string complexString; // The string to be returned.
	ostringstream aString; // I guess this is how doubles have to be converted to strings...
	ostringstream bString; // I guess this is how doubles have to be converted to strings...

	// Do some magic with the ostringstreams.
	aString << a;
	bString << b;


	// Only use a if b is 0.
	if (b == 0) {
		complexString = aString.str(); // Create the string.
	}
	else {
		complexString = "(" + aString.str() + " + " + bString.str() + "i)"; // Create the string.
	}
	return complexString;
}

void Complex::operator+=(Complex c)
{
	Complex temp = add(c); // Create a temporary Complex object with the new a and b values.

	// Read in the a and b values from the temporary object.
	a = temp.a;
	b = temp.b;
}

void Complex::operator-=(Complex c)
{
	Complex temp = subtract(c); // Create a temporary Complex object with the new a and b values.

	// Read in the a and b values from the temporary object.
	a = temp.a;
	b = temp.b;
}

void Complex::operator*=(Complex c)
{
	Complex temp = multiply(c); // Create a temporary Complex object with the new a and b values.

	// Read in the a and b values from the temporary object.
	a = temp.a;
	b = temp.b;
}

void Complex::operator/=(Complex c)
{
	Complex temp = divide(c); // Create a temporary Complex object with the new a and b values.

	// Read in the a and b values from the temporary object.
	a = temp.a;
	b = temp.b;
}

double & Complex::operator[](int index)
{
	// Return a if the index is 0, and b if it is anything else. (like 1)
	if (index == 0) return a;
	else return b;

}

Complex Complex::operator+()
{
	return Complex(); // Just return the same thing...
}

Complex Complex::operator-()
{
	// Create and return a complex object that has negative a and b values compared to the object that called the function.
	return Complex(-a,-b);
}

Complex & Complex::operator++()
{
	// Increment a, and pass back the reference to this object.
	a++;
	return *this;
}

Complex & Complex::operator--()
{
	// Decrement a, and pass back the reference to this object.
	a--;
	return *this;
}

Complex Complex::operator++(int dummy)
{
	// Create a temporary Complex object to be returned at the end.
	Complex temp(a, b);
	// Increment a.
	a++;
	// Return the temporary object.
	return temp;
}

Complex Complex::operator--(int dummy)
{
	// Create a temporary Complex object to be returned at the end.
	Complex temp(a, b);
	// Decrement a.
	a--;
	// Return the temporary object.
	return temp;
}
