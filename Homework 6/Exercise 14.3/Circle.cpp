#include "Circle.h"
using namespace std;

int Circle::numberOfObjects = 0;

Circle::Circle()
{
	radius = 1; // Set default radius.
	numberOfObjects++; // Increment number of Objects.
}

Circle::Circle(double radius)
{

	if (radius > 0) this->radius = radius;
	else radius = 1;

	numberOfObjects++; // Increme0nt number of Objects.

}

int Circle::getNumberOfObjects()
{
	return numberOfObjects;
}

bool Circle::operator<(Circle * c)
{
	return (radius < c->getRadius());
}

bool Circle::operator<=(Circle * c)
{
	return (radius <= c->getRadius());
}

bool Circle::operator==(Circle * c)
{
	return (radius == c->getRadius());
}

bool Circle::operator!=(Circle * c)
{
	return (radius != c->getRadius());
}

bool Circle::operator>(Circle * c)
{
	return (radius > c->getRadius());
}

bool Circle::operator>=(Circle * c)
{
	return (radius >= c->getRadius());
}

double Circle::getArea() const
{
	return (3.14159265*radius*radius);
}

double Circle::getRadius() const
{
	return radius;
}

void Circle::setRadius(double radius)
{
	if (radius > 0) this->radius = radius;
}
