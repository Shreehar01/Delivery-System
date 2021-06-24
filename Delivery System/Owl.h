#ifndef OWL_H
#define OWL_H
#include "Standard.h"



class Owl:public Standard
{
  std::string id;  //unique id of the Owl Delivery.
  
public:

  /**
   * @brief Will create a new Owl Delivery with an "Undefined" id.
   */ 
  Owl ();
  
  
  /**
   * @brief Will create a new Owl Delivery with the name of sender, date of delivery, weight and id given by the user.
   */ 
  Owl (std::string sender_name, std::string date_scheduled, std::string id, double weight);


  /**
   * @brief Getter
   * 
   * return The id of the delivery.
   */ 
  std::string get_id (){ return this->id; }
  
  
    
   /**
   * @brief Displays the delivery information( sender name, date of delivery,the weight of the package, and the id of the delivery).
   */ 
  void display ();
};
#endif
