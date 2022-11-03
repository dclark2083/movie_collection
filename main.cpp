/* THINGS TO THINK ABOUT BEFORE FINAL PUSH
  
  (1)For options 1, 2, 3, 5, 7 should we check the size of the list, and if empty print something
  like "Your movie collection is currently empty, try adding a movie first." But if the db does
  contain movie(s) it behaves as we have it?
  
  (2)Do we want a fail message for if a movie isn't found? Say the user doesn't own the movie
  Forest Gump. They search, and the program should tell them "That movie does not currently exist in db."
  
  (3)Same thing as (2) but for director?
  
  (4)Do we want to set all entries from user to upper or lower case so that sorting doesn't rely on user knowing ascii values?
  
  (5)On option 4, how can we add a print for the info of the movie the user just added? I tried using my movieFound print helper function. */

/**
 * @file main.cpp
 * @author Kyle Byassee & Darren Clark
 * @date 2022-11-03
 * @brief Program to manage user's horror movie collection.
 * 
 * By using the STD linked list this program is capable of 
 * creating, deleting, and managing a collection of horror movies.
 */

#include "library.h"
#include <iostream>
#include <string>

using namespace std;


/**
 * Prints the menu of program options for user.
 *
 * @pre A menu has been designed to give the user options to interact with their movie collection.
 * @return void 
 * @post 
 * 
 */
void menu();

/**
 * Determines if the search query is successful or fails.
 *
 * @param movie found A movie struct returned from search query.
 * @param string thing String to compare with director or title.
 * @pre Correctly formatted list of movies.
 * @return void 
 * @post 
 * 
 */
void movieResult(movie found, string thing);

/**
 * Prompts the user for information needed for a movie struct.
 *
 * @pre Movie struct declaration.
 * @return movie Returns a properly formatted movie struct.
 * @post 
 * 
 */
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
      cout << endl;
      cout << ">> Here is your current Horror Movie Collection <<" << endl;
      cout << endl;
      movies.print();
      cout << ">> End of movie collection. <<" << endl;
      cout << endl;
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
      // Title is found.
      if(found.Title != "Title not found.") {
	cout << '\n' << ">> " << title << " was found in your collection. << " << endl;
	cout << endl;
	movieResult(found, title);
      } else {
	cout << "\n>> " << title << " was not found in your collection. << " << endl << endl;
	cout << endl;
      }

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
      // Director is found.
      if(found.Director_Name != "Director not found.") {
	//	cout << '\n' << ">> " << director << " was found in your collection. << " << endl;
	movieResult(found, director);
      } else {
	cout << "\n>> " << director << " was not found in your collection. << " << endl << endl;
	cout << endl;
      }
    } break;
      
      //Add a movie to collection
    case 4: {
      cout << "[4] - Add a movie to collection." << endl;
      cout << endl;
      cin.get();
      movie new_fav_movie = new_movie();
      movies.insert_sorted(new_fav_movie);
      cout << endl;
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
      cout << "[6] - Import a list of movies to collection from file." << endl << endl;
      string fileName = "";
      cout << "Please enter file name to be imported: ";
      cin >> fileName;
      movies.read_from_file(fileName);
      cout << endl;
    } break;

      //Write list of movies to file.
    case 7: {
      cout << "[7] - Export movie collection to file." << endl;
      string fileName = "";
      cout << "Please enter name of file to be created: ";
      cin >> fileName;
      movies.write_to_file(fileName);
    } break;

      //Exits program
    case 8: {
      cout << ">> You have exited the program. <<" << endl;
    } break;
      
    default:
      cout << "Please select from options numbered 1 - 8 only." << endl;
    }
  }
  
  return 0;
}


void menu() {
  cout << "Welcome to your horror movie collection management program. " << endl
       << "Please select from one of the following 8 options..." << endl
       << endl
       << "[1] - Print current movie collection." << endl
       << "[2] - Search collection for a movie using key phrase." << endl
       << "[3] - Print movie(s) from collection by a specific director." << endl
       << "[4] - Add a movie to collection." << endl
       << "[5] - Delete a movie from collection." << endl;
  cout << "[6] - Import a list of movies to collection from file." << endl;
  cout << "[7] - Export movie collection to file." << endl;
  cout << "[8] - Exit movie collection management program." << endl;
  cout << endl << "Option#: ";
}

void movieResult(movie found, string thing) {
  if(found.Title == thing) {
    cout << "Title: " << found.Title << endl
	 << "Director: " << found.Director_Name << endl
	 << "Runtime: " << found.Movie_Runtime << " minutes" << endl
	 << "Format: " << found.format << endl
	 << "Price: $" << found.Price << endl
	 << "Release Year: " << found.Year << endl
	 << endl;
    return;
  }
  if(found.Director_Name == thing) {
    cout << "\n>> " << found.Director_Name << " directed these movies in your collection. << " << endl << endl;
    cout << "Title: " << found.Title << endl
	 << "Director: " << found.Director_Name << endl
	 << "Runtime: " << found.Movie_Runtime << " minutes" << endl
	 << "Format: " << found.format << endl
	 << "Price: $" << found.Price << endl
	 << "Release Year: " << found.Year << endl
	 << endl;
    return;
  }
}


movie new_movie() {
  movie new_guy;

  cout << "Please enter the title of the movie to be added: ";
  getline(cin, new_guy.Title);

  cout << "Please enter the director of this movie: ";
  getline(cin, new_guy.Director_Name);
  
  cout << "Please enter the runtime of this movie (in minutes): ";
  cin >> new_guy.Movie_Runtime;

  cout << "What format is this movie - Digital, DVD, Blu-ray, VHS: ";
  cin >> new_guy.format;

  cout << "What was the purchase price of this movie: $";
  cin >> new_guy.Price;

  cout << "What year was the movie released:  ";
  cin >> new_guy.Year;

  return new_guy;
}
