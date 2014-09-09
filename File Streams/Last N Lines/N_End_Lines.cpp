/* Accepts a number from the user prints the last n lines from the file and if the user's number
   is greater than the number of lines then the whole file is printed. */
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

void PrintLastNLines(vector<string>, int, int);

int main()
{
    fstream inputFile;  // fstream to hold the input file that will be read.
    string fileName;  // A string to hold the name of the file that the user wants to read.
    int counter = 0;  // Integer to keep track of how many lines there are from the start until the end of the file.
    int numOfLinesToDisplay = 0 ;  // Integer to hold the number of lines from the end the user wants to display.

    /* Ask the user to enter the name of the file that they want to read. */
    std::cout << "Enter the name of the file you want to read from (You do not need to have the .txt extension): ";
    std:: cin >> fileName;

    inputFile.open((fileName + ".txt"));  // Reads the file with the name that the user entered and does not need the ".txt" extension.

    /* If the file the user wanted to open fails then an error message is displayed. */
    if(inputFile.fail())
    {
	std::cout << "ERROR: Cannot open file named " << fileName << endl;
    }
    else
    {
	/* Ask the user to enter the number of lines from the end they want to display. */
	std::cout << "Enter the number of lines you want to display from the end of the file: ";
	std::cin >> numOfLinesToDisplay;
	vector<string> lines(numOfLinesToDisplay);  // Create a vector to hold the number of lines the user specified.

	/* While it is not the end of the input file... */
	while(!inputFile.eof())
	{
	    /* Get the line from the file and store it in the vector. The counter is incremented as each line is added and
	       moded in order to keep it within the number lines the user wanted to display.  */
	    getline(inputFile, lines[counter%numOfLinesToDisplay]);  
	    counter++;
	}

	// Call the function to print the vector that contains all the lines from the end of the file.
	PrintLastNLines(lines, counter, numOfLinesToDisplay);
    }
    inputFile.close();  // Close the input file.
    system("pause");  // Pause the program until a key is pressed.
}

/* A function that prints the contents of the vector that had the lines from the end of the file that the user wants displayed. */
void PrintLastNLines(vector<string> linesV, int count, int numLines)
{
    int start = 0;  // Integer to determine where in the vector should the printing start from

    int numLinesToPrint = min(count, numLines);  /* Integer that is the number of lines to be printed and is the minimum of the count variable or the 
						    number of lines that the user wants to display. So it either prints all of the lines if the user
						    specified a larger number than there are lines in the file or partial if the specified number is 
						    less than the number of lines in the file.*/

    /* If the count is greater than the user specified number of lines...*/
    if(count > numLines)
    {
	/* ...start is equal to the count modded by the number of lines specified by the user. */
	start = count % numLines;
    }
    else
    {
	/* ...else start is equal to 0. */
	start = 0;
    }

    /* For loop to display the contents of the vector holding the lines */
    for (int i = 0; i < numLinesToPrint; i++)
    {
	std::cout << linesV[(start + i) % numLines] << endl;
    }
}