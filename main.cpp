/**
 * @file main.cpp
 * @author Darren Clark & Kyle Byassee
 * @date 2022-10-11
 * @brief This program maintains a movie collection database.
 * 
 * This program provides users with an interface presenting several
 * options to manage their movie collection. They can add, remove, 
 * search the database.
 */


#include <iostream>
#include <list>

using namespace std;

void menu();

int main() {
  int selection = 0;
  while(selection != 8){
    menu();
    cin >> selection;

    switch(selection) {
    case 1 : { //Prints movie collection
      cout << "option 1" << endl;
    }
      break;
    case 2 : { //Search collection for a movie
      cout << "option 2" << endl;
    }
      break;
    case 3 : { //Print movies by director
      cout << "option 3" << endl;
    }
      break;
    case 4 : { //Add a movie to collection
	cout << "option 4" << endl;
      }
      break;
    case 5 : { //Delete a movie from collection
      cout << "option 5" << endl;
    }
      break;
    case 6 : { //Read in list of movies from file. 
      cout << "option 6" << endl;
    }
      break;
    case 7 : { //Write list of movies to file.
      cout << "option 7" << endl;
    }
      break;
    case 8 : { //Exits program
      cout << "option 8" << endl;
    }
      break;
    default: {
    cout << "only use numbers 1 -8" << endl;
    }
    }
  }
  /*
    list<movie> movies;

  movie billing_block;
  //billing_block movie
  billing_block.title = "Pi";
  billing_block.director = "Darren Aronofsky";

  //add movie to list
  movies.push_back(billing_block);

  //second movie
  billing_block.title = "Star Wars";
  billing_block.director = "George Lucas";

  movies.push_back(billing_block);

  list<movie>::iterator it;

  cout << "List of items" << endl;
  for(it = movies.begin(); it != movies.end(); it++) {
    cout << "List item: " << it->director << " - " << it->title << endl;
  }
  cout << endl << endl;

  billing_block.title = "Primer";
  billing_block.director= "Carruth";

  //Insert 3rd(??) movie in alphabetical order
  it = movies.begin();

  //Move iterator to correct location?
  it++;

  //Insert movie using list.insert()
  movies.insert(it, billing_block);

  cout << "List of 3 items: " << endl;
  //iterator over the list and print the contents (2 movies)
  for(it = movies.begin(); it != movies.end(); it++) {
    cout << "List item: " << it->director << " - " << it->title << endl;
  }
*/
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
  cout << "Option #:";
}

