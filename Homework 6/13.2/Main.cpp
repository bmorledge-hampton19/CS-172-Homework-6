/////////////////////
// Ben Morledge-Hampton
// CS 172-1
// 11-8-2016
// Homework 6
/////////////////////

//Pre-Processor Directives
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Main function
int main() {

	// Create the stream to read the data.
	ifstream input;

	int charCount = 0; // How many characters are in the file.

	string filename; // The filename provided by the user.

	// Have the user provide a filename.
	cout << "Gimme a file name! ";
	getline(cin,filename);

	// Attempt to open the file with the given name.
	input.open(filename.c_str());

	// Make sure that the file existed, and only proceed with reading if it did.
	if (input.fail()) {
		
		// Let the user know that the file did not exist.
		cout << "The file does not exist.  Sorry." << endl;

	}
	else {

		// Loop until the end of the file has been reached.
		while (!input.eof()) {

			// Read one character and move on to the next.
			input.get();
			// Increment the character counter if the end of the file has not been reached.
			if (!input.eof()) charCount++;

		}

		// Tell the user how may characters there were!
		cout << "The file you chose had " << charCount << " characters." << endl;

	}

	// Close the input stream
	input.close();


	// End function.  Everything is ok!
	return 0;

}