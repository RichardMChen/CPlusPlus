/*
    Description: A program that takes the information of movies, puts the information in variables of type MovieData, and prints the information.
*/

#include<iostream>
#include<string>
using namespace std;

/* A struct to hold the title, director, release year, and running time of a movie. */
struct MovieData
{
    string title;  // Title of movie
    string director;  // Director of movie
    int yearReleased;  // The year the movie was released
    int runningTime;  // The run time of the movie in minutes
};

/* Prints the contents inside MovieDate type variables. */
void printMovieData(MovieData m)
{
    cout << "Title: " << m.title << endl;
    cout << "Director: " << m.director << endl;
    cout << "Year Released: " << m.yearReleased << endl;
    cout << "Running time (in minutes): " << m.runningTime << "\n\n";
}

int main()
{
    MovieData movie1, movie2;  // MovieData variables.

    /* Sample data for 2 movies. */
    movie1.title = "Brave";
    movie1.director = "Pixar";
    movie1.yearReleased = 2012;
    movie1.runningTime = 93;

    movie2.title = "The Avengers";
    movie2.director = "Marvel";
    movie2.yearReleased = 2012;
    movie2.runningTime = 142;

    /* Prints the movie data from the 2 sample movies. */
    printMovieData(movie1);
    printMovieData(movie2);

    system("pause");
}