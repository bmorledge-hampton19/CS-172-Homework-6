#pragma once

class Circle {

public:
	Circle();  // Create a default circle with radius 1.
	Circle(double radius); // Create a circle with a given radius.  Must be positive, or it defaults to 1.
	
	static int getNumberOfObjects(); // Return the number of circles created.

	// A series of operators which compare the radii of two circles.
	bool operator<(Circle* c);
	bool operator<=(Circle* c);
	bool operator==(Circle* c);
	bool operator!=(Circle* c);
	bool operator>(Circle* c);
	bool operator>=(Circle* c);

	// Basic getters and a setter.
	double getArea() const; // Returns the area of the circle (pi * r * r)
	double getRadius() const; 
	void setRadius(double radius); // Radius must be positive.

private:
	double radius;
	static int numberOfObjects;

};