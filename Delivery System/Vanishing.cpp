#include "Vanishing.h"

VanishingCabinet::VanishingCabinet ()
{
  this->id = "Undefined";
}

VanishingCabinet::VanishingCabinet (std::string sender_name, std::string date_scheduled, std::string id):Delivery (sender_name,date_scheduled)
{
  this->id = id;
}


void VanishingCabinet::display ()
{
  std::cout << "ID                    " << std::setprecision(2)<<std::fixed<<this->id<< std::endl;
  std::cout << "Type of Shipping      Vanishing Cabinet" << std::endl;
  std::cout << "Sender Name           " << get_sender_name () << std::endl;
  std::cout << "Date of Delivery      " << get_date_scheduled () << std::endl;
  std::cout << "==================================" << std::endl;
}
