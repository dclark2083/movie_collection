#include "library.h"
#include <string>

using namespace std;

//void push_front(movie* new_movie);
//void push_back(movie* new_movie);


void read_from_file(std::string fileName) {

  movie movies;


}


void write_to_file(std::string fileName) {




}

// sort by the movie's title.
void insert_sorted(metadata new_billing) {




}

// prints all of the movies with the searched string as a substring
std::string find_movie(std::string title) {

  movie movies;

  return title;
}

// prints information on all movies by a given director
std::string director_search(std::string director) {


  //return Title;
  return director;
}


void print() {



}

void remove(std::string title) {


  
}



// removes them from the database
// void remove(std::string title) {
//   movie* bad_movie;
//   movie* link_guy;
//   link_guy = head;
  
//   billing_block checker;
//   checker = link_guy->getBilling_Block();

//   // Checks first node.
//   if(checker.Title == title) {
//     head = link_guy->getNext();
//     delete link_guy;
//     size--;
//     return;
//   }
  
//   while(link_guy->getNext() != nullptr) {
//     bad_movie = link_guy->getNext();
//     checker = bad_movie->getBilling_Block();
    
//     if(checker.Title == title) {
//       link_guy->setNext(bad_movie->getNext());
//       delete bad_movie;
//       size--;
//       return;
//     }
//     link_guy = link_guy->getNext();
//   }
  
//   // If last node is reached.
//   checker = link_guy->getBilling_Block();
  
//   if(checker.Title == title) {
//     delete link_guy;
//     size--;
//   }
// }
