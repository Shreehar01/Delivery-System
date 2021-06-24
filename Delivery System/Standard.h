#ifndef STANDARD_H
#define STANDARD_H
#include "Delivery.h"


class Standard:public Delivery
{
  double weight; //Stores the weight of the package. Cannot be negative.
  
public:

   /**
   * @brief Will create a new Standard Delivery with weight= 0.
   */ 
    Standard ();
    
    
   /**
   * @brief Will create a new Standard Delivery with the name of sender, date of delivery, and weight given by the user.
   * 
   * @param The name of sender and date of delivery, and the weight of the package.
   */ 
    Standard (std::string sender_name, std::string date_scheduled, double weight);
    
    
   /**
   * @brief Getter
   * 
   * return The weight of the package.
   */ 
    double get_weight () { return this->weight; }
    
    
   /**
   * @brief Getter
   * 
   * @return The name of the sender.
   */ 
    std::string get_sender_name () {return Delivery::get_sender_name ();}
      
      
   /**
   * @brief Getter
   * 
   * return The date of delivery.
   */  
    std::string get_date_scheduled () {return Delivery::get_date_scheduled ();}
      
      
   /**
   * @brief Displays the delivery information( sender name, date of delivery, and the weight of the package).
   */ 
    void display ();
  
};
#endif
