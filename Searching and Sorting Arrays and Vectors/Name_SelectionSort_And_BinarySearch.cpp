/*
    Description: A vector of names is selection sorted then the user enters a desired first and last name and binary search is 
    performed on the vector to see if the desired name is in the list.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Selection sorts a string vector */
void selectionSort(vector<string> &theNames)
{
    int start, minIndex;
    string sortName;
    for (int start = 0; start < (theNames.size() - 1); start++)
    {
	minIndex = start;
	sortName = theNames[start];

	for(int index = start + 1; index < theNames.size(); index++)
	{
	    if(theNames[index] < sortName)
	    {
		sortName = theNames[index];
		minIndex = index;
	    }
	}
	theNames[minIndex] = theNames[start];
	theNames[start] = sortName;
    }
}

/* Binary search a string vector for a given name */
int binarySearch(vector<string> nameVec, string lookName)
{
    int first = 0,
	last = nameVec.size() - 1,
	middle,
	position = -1;
    bool found = false;

    while(found == false && first <= last)
    {
	middle = (first + last) / 2;
	if(nameVec[middle] == lookName)
	{
	    found = true;
	    position = middle;
	}
	else if(nameVec[middle] > lookName)
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

/* Prints and displays a string vector */
void show(vector<string> showVec)
{
    for(int show = 0; show < showVec.size(); show++)
    {
	cout << showVec[show] << endl;
    }
}

int main()
{
    const int NUM_NAMES = 15; // The number of names
    string names[NUM_NAMES] = { "Collins, Bill", "Smith, Bart", "Allen, Jim", "Griffin, Jim", "Stamey, Marty", // Array with all of the names
				"Rose, Geri", "Taylor, Terri", "Johnson, Jill", "Allison, Jeff", "Looney, Joe", 
				"Wolfe, Bill", "James, Jean", "Weaver, Jim", "Pore, Bob", "Rutherford, Greg"};
    vector<string> namesV; // A vector to hold all the names
    string wantedName; // The name that the user inputs and is looking for
    int itemLocation = 0;

    /* For loop to transfer all the items */
    for (int i = 0; i < NUM_NAMES; i++)
    {
	namesV.push_back(names[i]);
    }

    cout << "Inside vector:" << endl; // Shows what is inially in the vector
    show(namesV);
    
    selectionSort(namesV); // Selection sorts the vector
    cout << "\nNow:\n";  // Shows what is in the vector after the selection sort  
    show(namesV);   
    
    /* Ask the user for the name they want to check for being in the list */
    cout << "\nEnter the name you are looking for (last name, first name): ";
    getline(cin, wantedName);
    
    itemLocation = binarySearch(namesV, wantedName);  // Perform binary search for desired name

    /* Displays a message if the name was found or not */
    if(itemLocation != -1)
    {
	cout << "\nThe name is in the list.\n";
    }
    else
    {
	cout << "\nThe name is not on the list.\n";
    }


    system("pause");
}