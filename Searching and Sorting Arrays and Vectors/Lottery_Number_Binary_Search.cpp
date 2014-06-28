/*
    Description: The user a 5-digit lottery number and is matched to see if it is a winning number with an already sorted array and through binary search.
*/

#include <iostream>
#include <vector>
using namespace std;

const int numTickets = 10;

int binarySearch(vector<int> tickets, int value)
{
    int first = 0,
	last = numTickets - 1,
	middle,
	position = -1;
    bool found = false;

    while(found == false && first <= last)
    {
	middle = (first + last) / 2;
	if(tickets[middle] == value)
	{
	    found = true;
	    position = middle;
	}
	else if(tickets[middle] > value)
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
    int purchasedTickets[numTickets] = {13579, 26791, 26792, 33445, 55555,
					62483, 77777, 79422, 85647, 93121};
    vector<int> purchasedTicketsV; // Vector of the purchased tickets
    int winningNum = 0;

    for(int i = 0; i < numTickets; i++)
    {
	purchasedTicketsV.push_back(purchasedTickets[i]);
    }

    cout << "Enter this week's winning 5-digit number: ";
    cin >> winningNum;

    if(binarySearch(purchasedTicketsV, winningNum) != -1)
    {
	cout << "The ticket is a winner." << endl;
    }
    else
    {
	cout << "The ticket is not a winner." << endl;
    }

    system("pause");
}