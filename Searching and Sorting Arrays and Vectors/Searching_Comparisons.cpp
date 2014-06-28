/*
    Description: A program that takes an integer array and performs a linear search and binary search to find a number given by the
    user. The number of comparisons are also displayed to show how many comparisons it took for each search to try and
    find the user's number.
*/
#include<iostream>
using namespace std;

const int NUM_ITEMS = 20;  // Constant integer to hold the size of the array.

/* Linear search function that takes in an array, integer for array size and the value that is being searched for. Searches the array and 
   compares elements one by one.*/
int linearSearch(int array[], int size, int value)
{
    int linearSearchComparison = 0;
    int position = -1;
    int index = 0;
    bool found = false;
    
    while(found == false && index < size)
    {
	if(array[index] == value)
	{
	    found = true;
	    position = index;
	}
	index++;
	linearSearchComparison++;
    }
    return linearSearchComparison;
}

/* Binary search that takes in an array, integer for array size and the value that is being searched for. */
int binarySearch(int array[], int size, int value)
{
    int first = 0,
	last = size - 1,
	middle,
	position = -1;
    int binarySearchComparison = 0;
    bool found = false;

    while(found == false && first <= last)
    {
	middle = (first + last) / 2;
	binarySearchComparison++;
	if(array[middle] == value)
	{
	    found = true;
	    position = middle;
	}
	else if(array[middle] > value)
	{
	    last = middle - 1;
	}
	else
	{
	    first = middle + 1;
	}
    }
    return binarySearchComparison;
}

/* Selection sort that takes in an array and integer for array size. Used to sort the array before the binary search is performed.*/
void selectionSort(int array[], int size)
{
    int start, 
    minIndex,
    minValue;

    for(start = 0; start < (size - 1); start++)
    {
	minIndex = start;
	minValue = array[start];
	for(int index = start + 1; index < size; index++)
	{
	    if(array[index] < minValue)
	    {
		minValue = array[index];
		minIndex = index;
	    }
	}
	array[minIndex] = array[start];
	array[start] = minValue;
    }
}

/* Function to print the contents of the array. */
void printArray(int theArray[], int size)
{
    for(int i = 0; i < size; i++)
    {
	cout << theArray[i] << " ";
    }
}

int main()
{
    int numbers[NUM_ITEMS] = {5, 1, 2, 150, 1654542, 25, 56, 80, 654, 15, 20, 1, 5, 30, 1444, 164, 26, 15, 850, 50000};  // Integer array holding the numbers to be searched.
    int desiredValue;  // Integer to hold the number that the user wants to look for.
    int linearSearchResult = 0;  // Holds the number of comparisons made by the linear search.
    int binarySearchResult = 0;  // Holds the number of comparisons made by the binary search.

    /* Displays the contents of the array originally without any sorting done. */
    cout << "The original array: ";
    printArray(numbers, NUM_ITEMS);

    /* Ask the user the number they want to find from the array. */
    cout << "\nWhat is the number you are looking for: ";
    cin >> desiredValue;

    linearSearchResult = linearSearch(numbers, NUM_ITEMS, desiredValue);  // Perform the linear search and store the number of comparisons made.

    /* Display the number of comparisons it took to find the number or not by using linear search. */
    cout << "Number of comparisions using linear search (If a number appears more than once then returns first one): " << linearSearchResult << endl;
    
    /* Display the number of comparisons it took to find the number or not by using binary search. */
    cout << "\nThe sorted array: ";
    selectionSort(numbers, NUM_ITEMS);  // Sort array first by selection sort.
    printArray(numbers, NUM_ITEMS);  // Print the sorted array.
    binarySearchResult = binarySearch(numbers, NUM_ITEMS, desiredValue);  // Perform binary search and store the number of comparisons made.

    /* Display the number of comparisons it took to find the number or not by using binary search. */
    cout << "\nNumber of comparisions using binary search (If a number appears more than once then returns first one): " << binarySearchResult << endl;
    system("pause");
}