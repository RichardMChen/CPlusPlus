/*
    Description: A program that takes the information of movies, puts the information in variables of type MovieData, and prints the information.

    NOTE: This is a modification of MovieData_Struct that also includes production costs and revenue.
*/

#include<iostream>
#include<string>
using namespace std;

struct MovieData
{
    string title;  // Title of movie
    string director;  // Director of movie
    int yearReleased;  // The year the movie was released
    int runningTime;  // The run time of the movie in minutes
    int productionCost;  // The cost of production
    int revenue;  // The first year revenue
    int profitOrLoss;  // The first year profit or loss on the movie
};

/* Function to print the data from a movie. */
void printMovieData(MovieData m)
{
    cout << "Title: " << m.title << endl;  // Prints the title of the movie.
    cout << "Director: " << m.director << endl;  // Prints the director of the movie.
    cout << "Year Released: " << m.yearReleased << endl;  // Prints the release date for the movie.
    cout << "Running time (in minutes): " << m.runningTime << endl;  // Prints the running time of the movie.
    cout << "Profit/Loss of movie $" << m.profitOrLoss << "\n\n";  // Prints the profit or loss of the movie.
}

int main()
{
    MovieData movie1, movie2;  // Variables for movie data.

    /* Sample data for 2 movies. */
    movie1.title = "This Movie 1";
    movie1.director = "Awesome Productions";
    movie1.yearReleased = 2010;
    movie1.runningTime = 93;
    movie1.productionCost = 30000;
    movie1.revenue = 1000000;
    movie1.profitOrLoss = movie1.revenue - movie1.productionCost;

    movie2.title = "This Movie 2";
    movie2.director = "Awesome Productions";
    movie2.yearReleased = 2012;
    movie2.runningTime = 142;
    movie2.productionCost = 100000;
    movie2.revenue = 90000;
    movie2.profitOrLoss = movie2.revenue - movie2.productionCost;

    /* Prints the data for the 2 sample movies. */
    printMovieData(movie1);
    printMovieData(movie2);

    system("pause");
}