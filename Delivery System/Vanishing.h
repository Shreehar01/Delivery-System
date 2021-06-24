#ifndef VANISHING_H
#define VANISHING_H
#include "Delivery.h"

class VanishingCabinet:public Delivery
{
  std::string id;		//Unique id for each delivery.
  
public:


  /**
   * @brief Will create a new Vanishing Cabinet Delivery with an "undefined" id.
   */ 
  VanishingCabinet ();
  
  
  /**
   * @brief Will create a new Vanishing Cabinet Delivery with the sender name, date of delivery , and id provided by the user.
   * 
   * @param The name of sender and date of delivery, and id
   */ 
  VanishingCabinet (std::string sender_name, std::string date_scheduled,std::string id);
  
  
  /**
   * @brief Getter
   * 
   * return The id of the delivery.
   */ 
  std::string get_id (){ return this->id;}
  
  
  /**
   * @brief Getter
   * 
   * return The date of delivery.
   */ 
  std::string get_date_scheduled () { return Delivery::get_date_scheduled (); }
  
  
   /**
   * @brief Getter
   * 
   * @return The name of the sender.
   */ 
  std::string get_sender_name (){return Delivery::get_sender_name ();}
  
  
  /**
   * @brief Displays the delivery information( sender name, date of delivery, and the id of the delivery ).
   */ 
  void display ();
};

#endif
