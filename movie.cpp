/**
 * @file node.cpp
 * @author Kyle Byassee
 * @date 2022-10-17
 * @brief The implementation of the node class methods.
 * 
 * The node class methods are defined here.
 */

#include "movie.h"

using namespace std;

movie::movie() {
  //next = nullptr;
  
  billing_block.Title = "";
  billing_block.Director_Name = "";
  billing_block.Movie_Runtime = 0;
  billing_block.format = "";
  billing_block.Price = 0.0;
  billing_block.Year = 0;
}

metadata movie::getBilling_Block() {
  return billing_block;
}

void movie::setBilling_Block(metadata new_billing) {
  billing_block = new_billing;
}

movie* movie::getNext() {
  return next;
}

void movie::setNext(movie* next_movie) {
  next = next_movie;
}
