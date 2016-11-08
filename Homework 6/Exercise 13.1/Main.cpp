/////////////////////
// Ben Morledge-Hampton
// CS 172-1
// 11-8-2016
// Homework 6
/////////////////////

//Pre-Processor Directives
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Main function
int main() {

	// Seed the RNG with the current time.
	srand((unsigned)time(NULL));

	// Create an fstream for writing to the file.
	fstream inout;

	// Open a file in order to append to its current contents.
	inout.open("Exercise13_1.txt", ios::out | ios::app);

	// Make sure the file was opened successfully.
	if (inout.fail()) {

		// If there was an issue, make it known, and exit the program.
		cout << "Something went horribly wrong." << endl;
		return 1;

	}

	// Generate 100 random integers from 0-100, with a space between each number and a newline every 10 numbers.
	for (int i = 0; i < 100; i++) {

		// Append the generated integer to the file, followed by a space.
		inout << rand() % 100 << " ";

		// If this is the 10th, 20th, etc. iteration of the loop, add a newline!
		if (i % 10 == 9) inout << endl;

	}


	// If everything worked out, make note of it!
	cout << "Everything seems to have gone alright!" << endl;

	// End function.  Everything is ok!
	return 0;

}
