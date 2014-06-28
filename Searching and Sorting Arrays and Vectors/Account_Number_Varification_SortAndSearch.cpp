/*
    Description: A vector contains account numbers and the user inputs an account number to see if it is in the vector.
    The vector however is selection sorted and then binary search is the search type that is used to find a 
    possible matching account number.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* Selection sorts a vector */
void selectionSort(vector<int> &vec)
{
    int start,  // An integer to determine where the search starts in the vector  
	minIndex,  // An integer of the index that holds the minimum value
	minValue;  // An integer that holds the minimum value

    for(int start = 0; start < (vec.size() - 1); start++)
    {
	minIndex = start;  // The 'minIndex' stores the current starting position based on the current loop's iteration
	minValue = vec[start];  // The 'minValue' stores the value that is stored in the element in the vector at the position of the 'start' value

	for(int index = start + 1; index < vec.size(); index++)
	{
	    /* If the value in the current index is less than the minimum value then... */
	    if(vec[index] < minValue)
	    {
		minValue = vec[index];  // 'minValue' stores the value of the vector element to be used later in the swap
		minIndex = index;  // 'minIndex' stores the value of the index that the minimum value is in the vector to used later in the swap
	    }
	}
	vec[minIndex] = vec[start];  // The value stored at index 'minValue' is swapped with the value at index 'start'
	vec[start] = minValue;  // The value at index 'start' equals the minimum value
    }
}

/* Binary searches a vector */
int binarySearch(vector<int> vect, int value)
{
    /* Integers for the position of the boundaries to search in the vector */
    int first = 0, 
	last = vect.size() - 1,
	middle,
	position = -1;
    bool found = false;

    /* Continue searching while the value is not found or the last value bound becomes equal or less than the first value bound */
    while(found == false && first <= last)
    {
	middle = (first + last) / 2;
	if(vect[middle] == value)
	{
	    found = true;
	    position = middle;
	}
	else if(vect[middle] > value)
	{
	    last = middle - 1;
	}
	else
	{
	    first = middle + 1;
	}
    }
    return position;
}


int main()
{
    const int totalNum = 10;
    int accountNumbers[totalNum] = { 5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 8080152, 4562555, 5552012, 5050522};
    vector<int> accountNumbersV;  // Vector to hold the account numbers
    int userInput;
    bool valid = false;  // Validation flag
    int binarySearchReturn = 0;  // Integer to determine whether the binary search found target number or not

    for(int i = 0; i < totalNum; i++)  // Initialize the vector with values in the array. 
    {
	accountNumbersV.push_back(accountNumbers[i]);
    }

#pragma region Vector_Comparison_Debug
 //   cout << "The vector originally: ";
 //   for (int i = 0; i < accountNumbersV.size(); i++)
 //   {
	//cout << accountNumbersV[i] << " ";
 //   }

 //   selectionSort(accountNumbersV);

 //   cout << "\nThe vector now: ";
 //   for (int i = 0; i < accountNumbersV.size(); i++)
 //   {
	//cout << accountNumbersV[i] << " ";
 //   }
#pragma endregion

    selectionSort(accountNumbersV);  // Selection sorts the vector

    /* User Input */
    std::cout << "Enter a 7 digit account number: ";
    std::cin >> userInput;

    while(to_string(userInput).size() != 7)
    {
	std::cout << "ERROR: You did not input a 7 account digit number. Input a 7 digit account number: ";
	std::cin >> userInput;
    }

    binarySearchReturn = binarySearch(accountNumbersV, userInput);  // The binary search is performed
    if(binarySearchReturn != -1)
    {
	valid = true;
    }

    /* Responses */
    if(valid == true)
    {
	cout << "The number is valid.\n";
    }
    else 
    {
	cout << "The number is NOT valid.\n";
    }

    system("pause");
}