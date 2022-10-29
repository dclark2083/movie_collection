#include "library.h"
#include <list>
#include <iostream>

using namespace std;

int main() {
  list<int> mylist;
  list<int>::iterator it1,it2;

  for (int i=1; i<10; ++i) {
    mylist.push_back(i*10);
  }

  it1 = it2 = mylist.begin();

  cout << "mylist contains:";
  for (it1=mylist.begin(); it1!=mylist.end(); ++it1) {
    cout << ' ' << *it1;
}
  cout << endl;
  
  
  
  /* A simple linked list-based movie DB */
  list<movie> library; // library of movies

  metadata temp;

  //temp.Title = "Primal";
  //temp.Director_Name = "Genndy Tartakovsky";
  //temp.Movie_Runtime = 22;
  
  



  
  cout << "hello." << endl;
  cout << "hello yourself" << endl;
  return 0;
}
