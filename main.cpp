#include "library.h"
#include <iostream>
#include <string>

using namespace std;

void menu();
movie new_movie();

int main() {
  /* A simple linked list-based movie DB */
  library movies;
  
  int selection = 0;
  while(selection != 8){
    menu();
    cin >> selection;
    switch(selection) {
      
    case 1: { // Prints movie collection
      cout << "Option 1" << endl;
      movies.print();
    } break;

      //Search collection for a movie
    case 2: {
      cout << "Option 2" << endl;
      string title = "";
      cout << "What do you want to watch? ";
      cin.get();
      getline(cin, title);
      movie found;
      found = movies.find_movie(title);
      cout << "Found: " << endl
	   << "Title: " << found.Title << endl
	   << "Director: " << found.Director_Name << endl
	   << "Runtime: " << found.Movie_Runtime << " minutes" << endl
	   << "Format: " << found.format << endl
	   << "Price: $" << found.Price << endl
	   << "Release Year: " << found.Year << endl
	   << endl;
    } break;

      //Print movies by director
    case 3: {
      cout << "Option 3" << endl;
      string director = "";
      cout << "What director are you in the mood for? ";
      cin.get();
      getline(cin, director);
      movie found;
      found = movies.director_search(director);
      cout << "Found: " << endl
	   << "Title: " << found.Title << endl
	   << "Director: " << found.Director_Name << endl
	   << "Runtime: " << found.Movie_Runtime << " minutes" << endl
	   << "Format: " << found.format << endl
	   << "Price: $" << found.Price << endl
	   << "Release Year: " << found.Year << endl
	   << endl;
    } break;

      //Add a movie to collection
    case 4: {
	cout << "Option 4" << endl;
	cin.get();
	movie new_one = new_movie();
	movies.insert_sorted(new_one);
    } break;

      //Delete a movie from collection
    case 5: {
      cout << "Option 5" << endl;
      string title = "";
      cout << "What movie do you not want to watch again forever? ";
      cin.get();
      getline(cin, title);
      movies.remove(title);
    } break;

      //Read in list of movies from file.
    case 6: {
      cout << "Option 6" << endl;
      string fileName = "";
      cout << "Please enter file name: ";
      cin >> fileName;
      movies.read_from_file(fileName);
    } break;

      //Write list of movies to file.
    case 7: {
      cout << "Option 7" << endl;
      string fileName = "";
      cout << "Please enter file name: ";
      cin >> fileName;
      movies.write_to_file(fileName);
    } break;

      // Exits program
    case 8: {
      cout << "Option 8" << endl;
    } break;
      
    default:
      cout << "Only use numbers 1 - 8" << endl;
    }
  }
  
  return 0;
}


void menu() {
 cout << "\nWelcome to your horror movie collection. "
      << "Please select from one of the following 8 options." << endl;
 cout << "\t[1] - Print current movie collection." << endl;
 cout << "\t[2] - Search collection for a movie using key phrase." << endl;
 cout << "\t[3] - Print movie(s) from collection by a specific director." << endl;
 cout << "\t[4] - Add a movie to collection." << endl;
 cout << "\t[5] - Delete a movie from collection." << endl;
 cout << "\t[6] - Import a list of movies to collection from file." << endl;
 cout << "\t[7] - Export movie collection to file." << endl;
 cout << "\t[8] - Exit movie collection management program." << endl;
 cout << "Option#: ";
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
