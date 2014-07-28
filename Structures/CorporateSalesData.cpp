/*
    Description: A struct is used to hold quater sales, total annual sales, and average quarterly sales for four coporate divisions. The user
    enters the data for each division and the division's total and average sales are calculated and stored in variables in the struct.
*/
#include<iostream>
#include<string>
using namespace std;

/* A struct for the division sales data type to hold names and sales for a division. */
struct DivisionSales
{
    string name;  // Name such as East, West, North, or South
    float firstQuarterSales;  // Float to hold first quarter sales.
    float secondQuarterSales;  // Float to hold second quarter sales.
    float thirdQuarterSales;  // Float to hold third quarter sales.
    float fourthQuarterSales;  // Float to hold fourth quarter sales.
    float totalAnnualSales;  // Float to hold total annual sales.
    float averageQuarterlySales;  // Float to hold average quarterly sales.
};

/* Function to take in and check the user's input for a division. */
void DivisionInput(DivisionSales &divInput)
{
    /* Ask the user to enter a division and store the name */
    cout << "Enter the division (East, West, North, or South): ";
    cin >> divInput.name;

    /* While loop to check that the division name entered is valid. */
    while(divInput.name != "east" && divInput.name != "East" 
    && divInput.name != "west" && divInput.name != "West" 
    && divInput.name != "north" && divInput.name != "North" 
    && divInput.name != "south" && divInput.name != "South" )
    {
	cout << "Must enter a proper division (East, West, North, South): ";
	cin >> divInput.name;
    }

    /* Ask the user to enter a sales amount and verifies that is greater than 0 */
    cout << "Enter first quarter sales: ";
    cin >> divInput.firstQuarterSales;
    while(divInput.firstQuarterSales < 0)
    {
	cout << "Enter a sale that is 0 or higher: ";
	cin >> divInput.firstQuarterSales;
    }

    cout << "Enter second quarter sales: ";
    cin >> divInput.secondQuarterSales;
    while(divInput.secondQuarterSales < 0)
    {
	cout << "Enter a sale that is 0 or higher: ";
	cin >> divInput.secondQuarterSales;
    }

    cout << "Enter third quarter sales: ";
    cin >> divInput.thirdQuarterSales;
    while(divInput.thirdQuarterSales < 0)
    {
	cout << "Enter a sale that is 0 or higher: ";
	cin >> divInput.thirdQuarterSales;
    }

    cout << "Enter fourth quarter sales: ";
    cin >> divInput.fourthQuarterSales;
    while(divInput.fourthQuarterSales < 0)
    {
	cout << "Enter a sale that is 0 or higher: ";
	cin >> divInput.fourthQuarterSales;
    }

    /* Calculates the total sales and average quaterly sales from the quarterly sales previously entered. */
    divInput.totalAnnualSales = divInput.firstQuarterSales + divInput.secondQuarterSales + divInput.thirdQuarterSales + divInput.fourthQuarterSales;
    divInput.averageQuarterlySales = divInput.totalAnnualSales / 4.0;
}

/* Function to display the sales figure of a division entered by the user. */
void diplaySalesFigures(DivisionSales info)
{
    cout << "\nDivision name: " << info.name << endl;
    cout << "Total annual sales: " << info.totalAnnualSales << endl;
    cout << "Average quarterly sales: " << info.averageQuarterlySales << "\n\n";
}

int main()
{
    DivisionSales div1, div2, div3, div4;  // 4 variables for each of the 4 divisions.

    /* Calls the functions to take in the data for 4 divisions and display their information. */
    DivisionInput(div1);
    diplaySalesFigures(div1);
    DivisionInput(div2);
    diplaySalesFigures(div2);
    DivisionInput(div3);
    diplaySalesFigures(div3);
    DivisionInput(div4);
    diplaySalesFigures(div4);

    system("pause");
}