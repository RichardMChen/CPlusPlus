/*
    Description: The program takes and already filled array of strings puts it into an array and performs selection sort on
    the vector.
*/
#include<iostream>
#include<string>
#include<vector>
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

    /* For loop to transfer all the items from the array to a vector */
    for (int i = 0; i < NUM_NAMES; i++)
    {
	namesV.push_back(names[i]);
    }

    cout << "Before selection sort:" << endl; // Shows what is inially in the vector
    show(namesV);  // Display the names in the vector
    
    selectionSort(namesV); // Selection sorts the vector
    cout << "\nAfter selection sort:\n";  // Shows what is in the vector after the selection sort  
    show(namesV);  // Display the names in the vector

    system("pause");
}