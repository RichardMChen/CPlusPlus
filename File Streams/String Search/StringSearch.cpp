/*
    Description: A program that asks the users for a file name and a string to
    search for. The program then searches the file for every occurence of the string
    given by the user. The line that the string is found is also displayed and the number
    of times the string appeared in the file.
*/
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
    fstream inputFile;  // fstream to hold the input file that will be read.
    string fileName = "";  // String to hold the name of the file to be searched.
    string fileLine = "";  // String to hold the current line from the file.
    string userString = "";  // String to hold the string that the user is looking for in the file.
    int found = 0;  //  Integer that holds the position of where the string starts if it is in the line.
    int counter = 0;  // Integer to count the number of times the string appears in the file

    /* Asks the user what the name of the file that they want to read from. */
    std::cout << "Enter the name of the text file to read from: ";
    std::cin >> fileName;
    inputFile.open((fileName + ".txt"));    

    /* Checks if the file fails to open */
    if(inputFile.fail())
    {
	std::cout << "ERROR: Cannot open file named " << fileName << endl;
    }
    /* If it does open... */
    else
    {
	/* Ask the user for the string they want to search for and store it. */
	std::cout << "Enter the string you wish to search for: ";
	std::cin >> userString;

	/* While it is not the end of the file... */
	while(!inputFile.eof())
	{
	    getline(inputFile, fileLine);  // Get a line from the file.
	    found = fileLine.find(userString, 0);  // The position of the desired string or npos if it is not found.
	    
	    /* While the 'found' position is not the npos position then... */
	    while(found != std::string::npos)
	    {
		    std::cout << fileLine << endl;  // The line is printed.
		    counter++;  // The counter is incremented by 1.
		    found = fileLine.find(userString, found + 1);  /* The 'found' integer position is set to the next position after the found string, 
								      based on the user string's size.*/
	    }
	}

	std::cout << "Number of times the string has appeared in the file: " << counter << endl;  // Displays the number of times the string appeared in the file.
    }

    system("pause");
}