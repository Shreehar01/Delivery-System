#ifndef MENUFUNCTIONS_H
#define MENUFUNCTIONS_H
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include "Vanishing.h"
#include "Owl.h"
#include "Griffin.h"


/**
 * @brief Prints the homescreen of the program which has a set of instructions to follow.
 */
void main_menu();


/** 
 * @brief Checks if the id provided is unique compared to all the list of ids in the system.
 * 
 * @param A vector consisting of pointer of all the deliveries in the system and a vector consisting of all the ids that are taken by the deliveries.
 * 
 * @return true if the id generate is unique and false if it is already taken.
 */
bool is_id_unique(std::vector<std::string> &list_of_id, std::string id);


/**
 * @brief Schedules a new delivery after prompting the user to input the delivery information.
 * 
 * @param A vector consisting of pointer of all the deliveries in the system and a vector consisting of all the ids that are taken by the deliveries.
 */
void schedule_new_delivery(std::vector <Delivery*> &Deliveries, std::vector<std::string> &list_of_id);


/**
 * @brief Prints all the deliveries stored in the system.
 * 
 * @param A vector consisting of pointer of all the deliveries in the system.
 */
void print_all_deliveries(std::vector <Delivery*> &Deliveries);


/**
 * @brief Prints all the deliveries stored in the system after prompting the user to input the delivery type.
 * 
 * @param A vector consisting of pointer of all the deliveries in the system.
 */
void print_deliveries_by_type(std::vector <Delivery*> &Deliveries);


/**
 * @breif Removes a delivery from the system after prompting the user to input the entry number of the delivery.
 * 
 * @param A vector consisting of pointer of all the deliveries in the system and a vector consisting of all the ids that are taken by the deliveries.
 */
void remove_delivery(std::vector <Delivery*> &Deliveries, std::vector<std::string> &list_of_id);


/**
 * @brief Saves the delivery from a system to a file after prompting the user to input the filename.
 * 
 * @param A vector consisting of pointer of all the deliveries in the system.
 */
void save_delivery(std::vector <Delivery*> &Deliveries);


/**
 * @brief Loads all the deliveries from a file to a system after prompting the user to input the filename. If the id in file matches, it loads them with changed id.
 * 
 * @param A vector consisting of pointer of all the deliveries in the system and a vector consisting of all the ids that are taken by the deliveries.
 */
void load_delivery(std::vector <Delivery*> &Deliveries, std::vector<std::string> &list_of_id);


/**
 * @brief Prompts user to make confirmation for quitting the program.
 * 
 * @param A vector consisting of pointer of all the deliveries in the system.
 * 
 * @return 1 if the user wants to quit. Returns any other number if the user cancels to quit.
 */
int confirmation(std::vector <Delivery*> &Deliveries);





#endif