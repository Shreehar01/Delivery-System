#ifndef DELIVERY_H
#define DELIVERY_H
#include <iomanip>
#include <string>
#include <iostream>

class Delivery
{
  std::string sender_name;	//name of sender of the delivery
  std::string date_scheduled;	// date of delivery
protected:


   /**
   * @brief Will create a new Delivery with a "Unknown" sender name and "Unknown" delivery date.
   */ 
  Delivery ();
  
  
   /**
   * @brief Will create a new Delivery with the sender name and date of delivery provided by the user.
   * 
   * @param The name of sender and date of delivery.
   */ 
  Delivery (std::string sender_name, std::string date_scheduled);
  
  
   /**
   * @brief Getter
   * 
   * return The name of the sender.
   */ 
  std::string get_sender_name (){ return this->sender_name; }
  
  
   /**
   * @brief Getter
   * 
   * return The date of delivery.
   */ 
  std::string get_date_scheduled (){ return this->date_scheduled; }
  
  
   /**
   * @brief Setter
   * 
   * @param The name of the sender.
   */ 
  void set_sender_name (std::string sender_name) { this->sender_name = sender_name; }
  
  
   /**
   * @brief Setter
   * 
   * @param The date of the delivery.
   */ 
  void set_date_scheduled (std::string date_scheduled){ this->date_scheduled = date_scheduled; }
  
public:


  /**
   * @brief Displays the delivery information( sender name and date of delivery).
   */ 
  virtual void display ();
};

#endif
