
#include <iostream>
#include <list>

using namespace std;


//Movie struct - it's pretty straight forward.
struct movie {
  string title;
  string director;
};

int main() {

  cout << "Welcome to hell.";

  //link list of movies.
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

  return 0;
}
