/////////////////////
// Ben Morledge-Hampton
// CS 172-1
// 11-8-2016
// Homework 6
/////////////////////

//Pre-Processor Directives
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Circle.h"
using namespace std;

// Main function
int main() {

	// Seed the RNG with time.
	srand((unsigned)time(NULL));

	// Create two Circle objects with random radii from 1-5.
	Circle* circle1 = new Circle(rand() % 5 + 1);
	Circle* circle2 = new Circle(rand() % 5 + 1);

	// Display the circles' radii.
	cout << "Circle 1 radius: " << circle1->getRadius() << endl;
	cout << "Circle 2 radius: " << circle2->getRadius() << endl << endl;

	// Preform the various checks between the two circles.
	cout << boolalpha;

	cout << "Circle 1 > Circle 2: " << (*circle1 > circle2) << endl;
	cout << "Circle 1 >= Circle 2: " << (*circle1 >= circle2) << endl;
	cout << "Circle 1 == Circle 2: " << (*circle1 == circle2) << endl;
	cout << "Circle 1 != Circle 2: " << (*circle1 != circle2) << endl;
	cout << "Circle 1 < Circle 2: " << (*circle1 < circle2) << endl;
	cout << "Circle 1 <= Circle 2: " << (*circle1 <= circle2) << endl << endl;

	// End function.  Everything is ok!
	return 0;
	
}