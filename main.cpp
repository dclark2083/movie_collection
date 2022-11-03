/**
 * @file main.cpp
 * @author Kyle Byassee & Darren Clark
 * @date 2022-11-02
 * @brief Program to manage user's horror movie collection.
 * 
 * By using the STD linked list this program is capable of creating, deleting, and managing a collection of horror movies.
 */

#include "library.h"
#include <iostream>
#include <string>

using namespace std;

void menu();
void movieFound();
movie new_movie();

int main() {
  //Movie database facilitated by a linked list.
  library movies;
  
  int selection = 0;
  while(selection != 8){
    menu();
    cin >> selection;
    switch(selection) {

      // Prints movie collection
    case 1: { 
      cout << "[1] - Print current movie collection." << endl;
      movies.print();
    } break;

      //Search collection for a movie
    case 2: {
      cout << "[2] - Search collection for a movie using key phrase." << endl;
      string title = "";
      cout << "What movie would you like to search for? ";
      cin.get();
      getline(cin, title);
      movie found;
      found = movies.find_movie(title);
      movieFound();
    } break;

      //Print movies by director
    case 3: {
      cout << "[3] - Print movie(s) from collection by a specific director." << endl;
      string director = "";
      cout << "What director would you like to search for? ";
      cin.get();
      getline(cin, director);
      movie found;
      found = movies.director_search(director);
      movieFound();
    } break;

      //Add a movie to collection
    case 4: {
      cout << "[4] - Add a movie to collection." << endl;
      cin.get();
      movie new_one = new_movie();
      movies.insert_sorted(new_one);
    } break;

      //Delete a movie from collection
    case 5: {
      cout << "[5] - Delete a movie from collection." << endl;
      string title = "";
      cout << "What movie should be deleted from the collection?" << endl;
      cin.get();
      getline(cin, title);
      movies.remove(title);
    } break;

      //Read in list of movies from file.
    case 6: {
      cout << "[6] - Import a list of movies to collection from file." << endl;
      string fileName = "";
      cout << "Please enter file name to be imported: ";
      cin >> fileName;
      movies.read_from_file(fileName);
    } break;

      //Write list of movies to file.
    case 7: {
      cout << "[7] - Export movie collection to file." << endl;
      string fileName = "";
      cout << "Please enter name of file to be created: ";
      cin >> fileName;
      movies.write_to_file(fileName);
      cout <<"Movie collection successfully exported to file: " << fileName << endl;
    } break;

      //Exits program
    case 8: {
      cout << "You have exited the program." << endl;
    } break;
      
    default:
      cout << "Please select from options numbered 1 - 8 only." << endl;
    }
  }
  
  return 0;
}


void menu() {
  cout << "\nWelcome to your horror movie collection. " << endl;
  cout << "\nPlease select from one of the following 8 options." << endl;
  cout << "[1] - Print current movie collection." << endl;
  cout << "[2] - Search collection for a movie using key phrase." << endl;
  cout << "[3] - Print movie(s) from collection by a specific director." << endl;
  cout << "[4] - Add a movie to collection." << endl;
  cout << "[5] - Delete a movie from collection." << endl;
  cout << "[6] - Import a list of movies to collection from file." << endl;
  cout << "[7] - Export movie collection to file." << endl;
  cout << "[8] - Exit movie collection management program." << endl;
  cout << "Option#: ";
}

void movieFound() {
  movie found;
  cout << "Found: " << endl
       << "Title: " << found.Title << endl
       << "Director: " << found.Director_Name << endl
       << "Runtime: " << found.Movie_Runtime << " minutes" << endl
       << "Format: " << found.format << endl
       << "Price: $" << found.Price << endl
       << "Release Year: " << found.Year << endl
       << endl;
}


movie new_movie() {
  movie new_guy;
  cout << "Title: ";
  getline(cin, new_guy.Title);
  
  cout << endl
       << "Director: ";
  getline(cin, new_guy.Director_Name);
  
  cout << endl
       << "Runtime (minutes): ";
  cin >> new_guy.Movie_Runtime;

  cout << endl
       << "Movie format: ";
  cin >> new_guy.format;

  cout << endl
       << "Price: $";
  cin >> new_guy.Price;

  cout << endl
       << "Release year: ";
  cin >> new_guy.Year;

  return new_guy;
}
