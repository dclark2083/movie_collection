/**
 * @file library.h
 * @author Kyle Byassee & Darren Clark
 * @date 2022-11-02
 * @brief Defines the class library and its members and methods. Creates a movie struct.
 * 
 * Header file that declares and initializes the members and methods of class library. 
 * Creates a struct of "movie" with different elements regarding movie details.
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <list>

//Struct of type movie.
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



/**
 * This library contains a private member of type movie list.
 *
 * @class library library.h "movie_collection/library.h"
 * @brief Container for STL list.
 *
 */
class library {
 private:
  std::list<movie> collection;
 public:



/**
 * Default constructor for library.
 *
 * Included for extendibility.
 * 
 */
  library();
  

/**
 * Method to retrieve movie info from user specified file.
 *
 * @param std::string fileName String variable containing name of file to be opened.
 * @pre A properly formatted string variable.
 * @post Movie collection has been updated from file.
 * 
 */
  void read_from_file(std::string fileName);

/**
 * Writes current linked list of movies to a text file.
 *
 * @param std::string fileName String variable containing the name of the file to be created.
 * @pre Linked list of movies should be created and populated.
 * @post Created an external file containing the list of movies and related information.
 * 
 */
  void write_to_file(std::string fileName);

/**
 * Sorts the movies placed into linked list by alphabetical order.
 *
 * @param New movie to be inserted into list.
 * @pre Properly formatted movie list and movie struct.
 * @post Collection of movies is incremented by 1.
 * 
 */
  void insert_sorted(movie new_movie);

/**
 * Searches movie collection by the entered string value and returns that movie struct.
 *
 * @param std::string title Properly formatted string variable of movie title.
 * @pre The linked list should contain properly formatted string variables containing the titles of movies.
 * @return movie If the movie is found, returns the movie and its related information.
 * 
 */
  movie find_movie(std::string title);

/**
 * Searches movie collection for all title(s) by a given director and returns that information.
 *
 * @param std::string director Properly formatted string variable of director's name.
 * @pre Linked list of movies has been created and contains information about the director.
 * @return movie If the director is present in the movie collection it will return that director's movie(s).
 * 
 */
  movie director_search(std::string director);

/**
 * Prints out the entire movie collection along with each movie's information values.
 *
 * @pre Linked list of movies has been created.
 * @return void If a database of movies is present it returns all movies in the database and their corresponding information.
 * 
 */
  void print();

/**
 * Removes the user specified movie title from the movie collection.
 *
 * @param std::string title Properly formatted string variable of the movie title to be deleted.
 * @pre Linked list of movies has been created and proper movie title is passed to remove.
 * @post Collection of movie  has been increased by 1.
 * 
 */
  void remove(std::string title);
};
#endif //LIBRARY_H
