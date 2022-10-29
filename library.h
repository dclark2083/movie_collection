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

#include "movie.h"
#include <list>

/**
 * The phonebook class declaration.
 *
 * @class phonebook phonebook.h "HW2/phonebook.h"
 * @brief The phonebook class has a size and a head.
 *
 */
class library {
 private:
  //movie* head = nullptr;
  //int size = 0; // Optional helper

 public:

/**
 * Constructor
 *
 * @post A properly formed phonebook object.
 * 
 */
  library();

/**
 * Destructor
 *
 * @pre A properly formed phonebook object.
 * @post The dynamic memory is freed and the object is destructed.
 * 
 */
  ~library();

/**
 * Add a node at the head of the linked list
 *
 * @param node* new_guy The node to be added.
 * @pre A node object and a phonebook object.
 * @post The list has added one node at the head.
 * 
 */
  void push_front(movie* new_movie);

/**
 * Add a node at the tail of a linked list.
 *
 * @param node* new_guy The node to be added.
 * @pre A node object and a phonebook object.
 * @post The list has added one node at the tail.
 * 
 */
  void push_back(movie* new_movie);

/**
 * Takes a string file name as a parameter and reads the phonebook from the file with that name.
 *
 * @param std::string fileName The name of the file.
 * @pre A properly formed phonebook object.
 * @post The phonebook object has been updated with entries.
 * 
 */
  void read_from_file(std::string fileName);

/**
 * Takes a string with a file name as a parameter and writes the phonebook to the file with that name.
 *
 * @param std::string fileName The name of the file.
 * @pre A properly formed phonebook object.
 * @post The phonebook has been written to a text file.
 * 
 */
  void write_to_file(std::string fileName);

/**
 * Search for an insertion point in the list by traversing the list, insert a new node in the middle of the list in alphabetical order, sorted by the user's last name.
 *
 * @param entry new_guy The struct to be added to a new node.
 * @pre A properly formed phonebook object.
 * @post A node has been added to the list at a any point in the list.
 * 
 */
  void insert_sorted(metadata new_billing);

/**
 * Takes a name as a parameter and return the number associated with it.
 *
 * @param std::string name The person's name being searched for.
 * @pre A properly formed phonebook object.
 * @return std::string The number of the person associated with the name.
 * 
 */
  std::string find_movie(std::string title);

/**
 * Takes a phone number as a parameter and returns the name of the individual associated with it.
 *
 * @param std::string phone_number The phone number being searched for.
 * @pre A properly formed phonebook object.
 * @return std::string The name of the person with associated with the phone number.
 * 
 */
  std::string director_search(std::string director);

/**
 * Prints the content of the directory to the screen.
 *
 * @pre A properly formed phonebook object.
 * 
 */
  void print();

/**
 * Takes a user's name as a parameter and removes their entry from the phonebook.
 *
 * @param std::string name The name of the person to be deleted.
 * @pre A properly formed phone book object.
 * @post The phonebook has been shortened by one node.
 * 
 */
  void remove(std::string title);
};
#endif //LIBRARY_H
