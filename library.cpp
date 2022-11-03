/**
 * @file library.cpp
 * @author Kyle Byassee & Darren Clark
 * @date 2022-11-02
 * @brief .cpp file to implement the library header file.
 * 
 * I can't recall, do these need a description other than brief?
 */

#include "library.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

library::library() {} // Included for extendability.


//Reads the library from a file.
void library::read_from_file(string fileName) {
  ifstream in;
  movie new_movie;
  
  in.open(fileName);
  getline(in, new_movie.Title); // Priming read
  while(in) {
    getline(in, new_movie.Director_Name);
    in >> new_movie.Movie_Runtime;
    in.get();
    in >> new_movie.format;
    in.get();
    in >> new_movie.Price;
    in.get();
    in >> new_movie.Year;
    in.get();
    insert_sorted(new_movie);
    in.get();
    getline(in, new_movie.Title);
  }
  in.close();
  
  if (in.eof()) {
    cout << ">> " << fileName << " has been imported into your collection. <<" << endl; // Joy
  } else {
    cout << ">> " <<  fileName << " was not found. <<" << endl;
  }
}


//Writes the library to a text file.
void library::write_to_file(string fileName) {
  ofstream out;
  list<movie>::iterator it;
  it = collection.begin();
  
  out.open(fileName);
  while(it != collection.end()) {
    out << it->Title << '\n'
	<< it->Director_Name << '\n'
	<< it->Movie_Runtime << '\n'
	<< it->format << '\n'
	<< it->Price << '\n'
	<< it->Year << '\n'
	<< '\n';
    it++;
  }
  out.close();
  
  if (out.fail()) {
    cout << '\n' << ">> " << fileName << " is not valid a valid filename. << " << endl;
    cout << ">> Movie collection export cancelled. << " << endl;
    cout << endl;
  }
  else {
    cout << ">> File " << fileName << " was written successfully. <<" << endl;
    cout << endl;
  }
}


//Sort by the movie's title.
void library::insert_sorted(movie new_movie) {
  if(collection.size() == 0) {
    collection.push_back(new_movie);
    return;
  }
  
  list<movie>::iterator it;
  it = collection.begin();

  while( (it->Title < new_movie.Title) && (it != collection.end()) ) {
    it++;
  }
  collection.insert(it, new_movie);
}

//Prints all of the movies with the searched string as a substring.
movie library::find_movie(string title) {
  movie not_found;
  not_found.Title = "Title not found.";
  not_found.Director_Name = "Director not found.";
  
  list<movie>::iterator it;
  it = collection.begin();

  while( (it->Title != title) && (it != collection.end()) ) {
    it++;
  }

  if(it == collection.end()) {
    return not_found;
  }
  
  return *it;
}


//Prints information on all movies by a given director.
movie library::director_search(string director) {
  movie temp;
  temp.Director_Name = "Director not found.";
  temp.Title = "Title not found.";
  
  list<movie>::iterator it;
  it = collection.begin();
  
  while( (it->Director_Name != director) && (it != collection.end()) ) {
    it++;
  }
  if(it != collection.end()) {
    return *it;
  }
  return temp;
}


// prints the library to screen
void library::print() {
  list<movie>::iterator it;
  it = collection.begin();
  while(it != collection.end()) {
    cout << "   " << it->Title << endl
	 << "Director: " << it->Director_Name << endl
	 << "Runtime: " << it->Movie_Runtime << " minutes" << endl
	 << "Format: " << it->format << endl
	 << "Price: $" << it->Price << endl
	 << "Release Year: " << it->Year << endl
	 << endl;
    it++;
  }
}

//Removes movie from the database based on title.
void library::remove(string title) {
  list<movie>::iterator it;
  it = collection.begin();
  
  while(it != collection.end()) {
    if(it->Title == title) {
      collection.erase(it);
      return;
    }
    it++;
  }
}
