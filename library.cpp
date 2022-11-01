#include "library.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

library::library() {} // Unused default constructor...


// reads the library from a file
void library::read_from_file(string fileName) {
  ifstream in;
  movie new_movie;
  
  in.open(fileName);
  in >> new_movie.Title; // Priming read
  while(in) {
    in >> new_movie.Director_Name >> new_movie.Movie_Runtime
       >> new_movie.format >> new_movie.Price >> new_movie.Year;
    insert_sorted(new_movie);
    in >> new_movie.Title;
  }
  in.close();
}


// writes the library to a text file
void library::write_to_file(string fileName) {
  ofstream out;
  list<movie>::iterator it;
  it = collection.begin();
  
  out.open(fileName);
  while(it != collection.end()) {
    out << it->Title << it->Director_Name << it->Movie_Runtime
	<< it->format << it->Price << it->Year << '\n';
    it++;
  }
  out.close();
}


// sort by the movie's title.
void library::insert_sorted(movie new_movie) {
  list<movie>::iterator it;
  it = collection.begin();
  
  while(it != collection.end()) {
    if(it->Title < new_movie.Title) {
      collection.insert(it, new_movie);
      return;
    }
    it++;
  }
}


// prints all of the movies with the searched string as a substring
string library::find_movie(string title) {
  string temp = "Title not found.";
  
  list<movie>::iterator it;
  it = collection.begin();
  while(it != collection.end()) {
    if(it->Title == title) {
      return it->Title;
    }
    if(it->Director_Name == title) {
      return it->Director_Name;
    }
    it++;
  }

  return temp;
}


// prints information on all movies by a given director
string library::director_search(string director) {
  string temp = "Director not found.";
  
  list<movie>::iterator it;
  it = collection.begin();
  while(it != collection.end()) {
    if(it->Director_Name == director) {
      return it->Director_Name;
    }
    it++;
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


// removes movie from the database based on title
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
