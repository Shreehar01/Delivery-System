#ifndef GRIFFIN_H
#define GRIFFIN_H
#include "Standard.h"



class Griffin:public Standard
{
  std::string id;  //unique id of the Griffin Delivery.
  
public:

  /**
   * @brief Will create a new Griffin Delivery with an "Undefined" id.
   */ 
  Griffin ();
  
  
  /**
   * @brief Will create a new Griffin Delivery with the name of sender, date of delivery, weight and id given by the user.
   */ 
  Griffin (std::string sender_name, std::string date_scheduled, std::string id, double weight);


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
