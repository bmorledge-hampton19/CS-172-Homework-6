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

// A function to extract and return only the phrase at position [pos] in a string of phrases seperated by various amounts of whitespace. (The first phrase is position 0)
string findPhrase(int pos, string phrases) {

	int whitespaceSearching; // A variable that finds the first non-whitespace character after the first region of whitespace.

	// Truncate the string by the number of phrases designated by pos.
	for (int i = 0; i < pos; i++) {

		// Find the end of the current region of whitespace by starting whitespaceSearching at the first whitespace character, and incrementing it until it reaches a non-whitespace character.
		for (whitespaceSearching = phrases.find(' '); phrases.at(whitespaceSearching) == ' '; whitespaceSearching++);
		
		// Erase the characters up until the point indicated by whitespaceSearching.
		phrases.erase(0, whitespaceSearching);

	}

	// Truncate the end of the string so that all that is left is the desired phrase.
	// Find the first bit of whitespace, and cut everything in front of it off.
	phrases.erase(phrases.find(' '), phrases.size() - phrases.find(' '));

}

// Main function
int main() {

	// Create an input stream
	ifstream input;

	string year;  // The year of the text file that will be read from.
	string name; // The name of the child being searched for.
	char gender = ' '; // The gender of the child being searched for.

	string filename; // The filename that wil be obtained based on the year given.

	int rankNumber = 0;  // Keeps track of the current ranking while sifting through a file for a name.
	string line; // The current line being read out of the file.
	string modifiedLine; // The string used in the process by which the line is modified to obtain only the name desired.


	// Prompt the user to input the year of birth, name, and gender, of the child's name they want to see ranked.

	cout << "Welcome to the super baby name searcher!!" << endl;

	cout << "What year would you like to search in (2010-2014)? ";
	cin >> year;

	// Loop until the gender given is an 'm' or 'f'.
	while ( !(tolower(gender)=='m' || tolower(gender)=='f') ) {
		cout << "What is the gender of the name you are searching for (M/F)? ";
		cin >> gender;
	}

	cout << "What is the name? ";
	cin >> name;

	// Create the filename based on the year given.
	filename = "Babynameranking" + year + ".txt";

	
	// Attempt to open the file with the filename.
	input.open(filename.c_str());

	// If the filename was invalid, let the user know, and end the program.
	if (input.fail()) {

		cout << "The year you entered was invalid." << endl;
		return 1;

	}


	// Begin reading through the file one line at a time.
	while (getline(input, line)) {

		//Increment rankNumber
		rankNumber++;

		// Based on the gender given, modify the line with the findPhrase function to return the desired name.
		if (tolower(gender) == 'm') {
			modifiedLine = findPhrase(2, line);
		}
		else if (tolower(gender) == 'f') {
			modifiedLine = findPhrase(4, line);
		}

		// Check the derived name against the user-given name.  If they match, display the rank number and exit the loop.
		if (modifiedLine == name) {
			cout << "The name " << name << " is ranked " << rankNumber << " in the year " << year << "." << endl;
			break;
		}

		// If the 1000th line has been reached, and no matches have been found, let the user know.
		if (rankNumber == 1000) cout << "The name " << name << " is not ranked in the year " << year << "." << endl;

	}

	 

	// End function.  Everything is ok!
	return 0;

}