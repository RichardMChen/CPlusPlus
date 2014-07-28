/*
    Description: An array of 12 structures hold weather data for an entire year. The user enteres data for each month, which are then calculated and 
    then the average monthly rainfall, total rainfall for the year, the highest and lowest temperatures for the year (and the month they occured in),
    and the average of all the monthly average temperatures are displayed.
*/

#include <iostream>
#include <string>
using namespace std;

const int NUM_MONTHS = 12;  // Constant integer for the size of the array.

/* Struct for the monthly weather data. */
struct MonthWeatherData
{
    float totalRainfall;  // Float for the total rainfall for the month.
    float highTemperature;  // Float for the highest temperature for the month.
    float lowTemperature;  // Float for the lowest temperature for the month.
    float avgTemperature;  // Float for the average temperature for the month.
};

int main()
{
    MonthWeatherData yearRainfall[NUM_MONTHS];  // An array for 12 months to hold the weather data.
    string months[NUM_MONTHS] = {"January", "February", "March", "April", "May", "June", "July", "August", 
				 "September", "October", "November", "December"};  // An array to hold the names of the months.
    float yearTotalRainfall = 0.0;  // Float for the total rainfall for the year.
    float avgMonthlyRainfall = 0.0;  // Float for the average monthly rainfall.
    float avgYearTemperature = 0.0;  // Float for the average temperature for the year.

    /* For loop to go through all 12 months. */
    for(int i = 0; i < NUM_MONTHS; i++)
    {
	/* Ask the user to enter the total rainfall for a month */
	cout << "Enter the data for " << months[i];
	cout << "\nTotal rainfall: ";
	cin >> yearRainfall[i].totalRainfall;

	/* Ask the user to enter the high temperature for a month a validate whether it is between -100 and 140 degrees Fahrenheit. */
	cout << "High temperature (degrees Fahrenheit): ";
	cin >> yearRainfall[i].highTemperature;
	while(yearRainfall[i].highTemperature < -100 || yearRainfall[i].highTemperature > 140)
	{
	    cout << "Enter a Fahrenheit temperature betwee -100 degrees and 140 degrees: ";
	    cin >> yearRainfall[i].highTemperature;
	}
	
	/* Ask the user to enter the low temperature for a month a validate whether it is between -100 and 140 degrees Fahrenheit. */
	cout << "Low temperature (degrees Fahrenheit): ";
	cin >> yearRainfall[i].lowTemperature;
	while(yearRainfall[i].lowTemperature < -100 || yearRainfall[i].lowTemperature > 140)
	{
	    cout << "Enter a Fahrenheit temperature betwee -100 degrees and 140 degrees: ";
	    cin >> yearRainfall[i].lowTemperature;
	}

	/* Calculate the average temperature for a month and adds the current month's rainfall to the total rainfall. */
	yearRainfall[i].avgTemperature = (yearRainfall[i].highTemperature + yearRainfall[i].lowTemperature) / 2;
	yearTotalRainfall += yearRainfall[i].totalRainfall;
	cout << "\n\n";
    }

    float highestTemperature = yearRainfall[0].highTemperature;  // Initialize the highest temperature.
    float lowestTemperature = yearRainfall[0].lowTemperature;  // Initialize the lowest temperature.
    int highestTempMonth = 0;  // Initialize the variable for the month with the highest temperature.
    int lowestTempMonth = 0;  // Initialize the variable for the month with the lowest temperature.

    /* Loop through to see which months had the highest and lowest temperatures. */
    for(int m = 1; m < NUM_MONTHS; m++)
    {
	if(highestTemperature < yearRainfall[m].highTemperature)
	{
	    highestTemperature = yearRainfall[m].highTemperature;
	    highestTempMonth = m;
	}
	if(lowestTemperature > yearRainfall[m].lowTemperature)
	{
	    lowestTemperature = yearRainfall[m].lowTemperature;
	    lowestTempMonth = m;
	}
    }

    avgMonthlyRainfall = yearTotalRainfall / NUM_MONTHS;  // Calculate the average monthly rainfall.

    /* Display the weather data for the year. */
    cout << "\nAverage monthly rainfall: " << avgMonthlyRainfall;
    cout << "\nTotal rainfall for the year: " << yearTotalRainfall;
    cout << "\nThe highest temperature was: " << highestTemperature;
    cout << "\nMonth with the highest temperature: " << months[highestTempMonth];
    cout << "\nThe lowest temperature was: " << lowestTemperature;
    cout << "\nMonth with the lowest temperature: " << months[lowestTempMonth] << endl;


    system("pause");
}