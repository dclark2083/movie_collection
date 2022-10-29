/**
 * @file node.h
 * @author Kyle Byassee
 * @date 2022-10-17
 * @brief The declaration of the node class.
 * 
 * Node contains a struct and a pointer to another node.
 */

#ifndef MOVIE_H
#define MOVIE_H

#include <string>

struct metadata {
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
  
  // Year (int or short)
  short Year = 0;
};

/**
 * The node class declaration.
 *
 * @class node node.h "HW2/node.h"
 * @brief The node class has a pointer to the next node and a struct.
 *
 */
class movie {
 private:
  movie* next = nullptr;
  metadata billing_block;

 public:

/**
 * Constructor
 *
 * @post A properly constructed node object.
 * 
 */
  movie();

/**
 * Gets the struct in the node.
 *
 * @pre A properly formed node.
 * @return entry A struct containing a name and number.
 * 
 */
  metadata getBilling_Block();

/**
 * Sets the private data in a node.
 *
 * @param entry new_guy The new struct to be stored in the node.
 * @pre A properly formed node.
 * @post The node's private struct has been updated.
 * 
 */
  void setBilling_Block(metadata new_movie);

/**
 * Gets the address of the next node.
 *
 * @pre A properly formed node.
 * @return node* A pointer to the next node.
 * 
 */
  movie* getNext();

/**
 * Sets the private pointer to the next node.
 *
 * @param node* back_guy The node to be pointed to.
 * @pre A properly formed node.
 * @post The node's private pointer has been updated.
 * 
 */
  void setNext(movie* next_movie);
};

#endif //MOVIE_H
