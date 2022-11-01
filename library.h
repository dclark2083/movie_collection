/**
 * @file phonebook.h
 * @author Kyle Byassee
 * @date 2022-10-17
 * @brief The declaration of the phonebook class.
 * 
 * The phonebook class is a linked list.
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <list>

/* A simple movie struct */
struct movie {
  // Title - (string) May include spaces.
  std::string Title = "";
  
  // Director Name - (string) May include spaces.
  std::string Director_Name = "";
  
  // Movie Runtime - (int) The total runtime in minutes.
  int Movie_Runtime = 0;
  
  // format - (string) Digital, DVD, Blu-ray, or VHS.
  std::string format = "VHS";
  
  // Price (float).
  float Price = 0.0;
  
  // Year (int or short).
  short Year = 0;
};


class library {
 private:
  std::list<movie> collection;
 public:

/**
 * Unused Default Constructor
 *
 * @post A properly formed phonebook object.
 * 
 */
  library();
  void read_from_file(std::string fileName);
  void write_to_file(std::string fileName);
  void insert_sorted(movie new_movie);
  std::string find_movie(std::string title);
  std::string director_search(std::string director);
  void print();
  void remove(std::string title);
};
#endif //LIBRARY_H
