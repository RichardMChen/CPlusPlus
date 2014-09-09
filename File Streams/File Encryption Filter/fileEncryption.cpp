/*
    Description: A program that reads a file's contents and enrypts it, then it prints out the coded message in the file on screen and
    on a separate text file. The text file that contains the secret code I created is 26 characters on one line for each of the letters
    in the alphabet.

    NOTE: The encryption only changes letters. Numbers, spaces, punctuation, etc. that are not letters are left alone.
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Function prototypes.
bool OpenFile(fstream&, string);
void Encryption(fstream&, fstream&);

int main()
{
    fstream inputFile, codeFile;  // File streams for the input file and the code file that will be used.
    string  inputFileName = "",  // String for the name of the input file.
	    codeFileName = "",  // String for the name of the code file that the user is using.
	    fileLine = "";  // String to hold a line from the input file.
    
    /* Asks the user for the name of the text file that contains the code to encrypt the message. Error message is displayed if
       the file with the entered name is not found. */
    std::cout << "Enter the name of the text file you want to use for the code (Do not need the .txt extension): ";
    std::cin >> codeFileName;
    if(!OpenFile(codeFile, codeFileName))
    {
	std::cout << "ERROR: Could not open file named: " << codeFileName << endl;
    }

    /* User is asked the name of the text file that they want to read from and accepts the file name. If the file could not
       be opened then an error message is displayed. */
    std::cout << "Enter the name of the text file you want to read from: ";
    std::cin >> inputFileName;
    if(!OpenFile(inputFile, inputFileName))
    {
	std::cout << "ERROR: Could not open file named: " << inputFileName << endl;
    }
    else
    {
	/* If the file was able to be opened then the Encryption function is called and then the files are closed when it the function is done. */
	Encryption(codeFile, inputFile);
	std::cout << endl;

	codeFile.close();
	inputFile.close();
    }

    system("pause");
}

/* Function that recieves the fstream for a file and the string name of the file to open. */
bool OpenFile(fstream &file, string fName)
{
    file.open((fName + ".txt"), ios::in);  // Tries to open the file

    /* Returns false if file failed to open. */
    if(file.fail())
    {
	return false;
    }
    /* Returns true if the file was able to be opened. */
    else
    {
	return true;
    }
}

/* Function that takes in the fstream for the file of the code for the letters and another fstream for the input file. */
void Encryption(fstream &codeFile, fstream &inputFile)
{
    // Character array to hold all the letters.
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    string code = "",  // string to hold the line from the file that represents the code for each of the letters.
	   inputFileLine = "";
    fstream outputFile("output.txt", ios::out);

    getline(codeFile, code);
    while(!inputFile.eof())
    {
	getline(inputFile, inputFileLine);
	for (int i = 0; i < inputFileLine.length(); i++)
	{
	    if( isalpha(inputFileLine.at(i)) )
	    {
		for (int j = 0; j < 26; j++)
		{
		    if(tolower(inputFileLine.at(i)) == alphabet[j])
		    {
			std::cout << code.at(j);
			outputFile << code.at(j);
		    }
		}
	    }
	    else
	    {
		std::cout << inputFileLine.at(i);
		outputFile << inputFileLine.at(i);
	    }
	}
	std::cout << endl;
	outputFile << endl;
    }
}