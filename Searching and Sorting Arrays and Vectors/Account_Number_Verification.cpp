/*
    Description: A simple program that takes an already filled array of account numbers and searches that same array to see
    if the user inputs an account number that matches any of the ones in the array.
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    const int totalNum = 18;  // A constant integer for the array size
    string accountNumbers[totalNum] = { "5658845", "4520125", "7895122", "8777541", "8451277", "1302850", "8080152", "4562555", "5552012", "5050522"};  // Array to hold valid account numbers
    string userInput;  // Int to hold the users input
    bool valid = false;  // Boolean indicator to help determine if an account number is valid or not

    /* Ask the user for the 7 digit integer  */
    std::cout << "Enter a 7 digit account number: ";
    std::cin >> userInput;

    /* If the user does not enter a 7 digit number then it will keep throwing an error message until a 7 digit number is entered. */
    while(userInput.size() != 7)
    {
	std::cout << "You did not enter a 7 digit account number. Reenter a 7 digit account number: ";
	std::cin >> userInput;
    }

    /* For loop to check if the 7 digit number the user entered matches any of the numbers in the account numbers array */
    for(int i = 0; i < totalNum; i++)
    {
	/* If a match is made then set 'valid' to true and break */
	if(userInput == accountNumbers[i])
	{
	    valid = true;
	    break;
	}
    }

    /* Display message if 'valid' is true */
    if(valid == true)
    {
	cout << "The number is valid.\n";
    }
    /* Display following message otherwise */
    else 
    {
	cout << "The number is NOT valid.\n";
    }

    system("pause");
}