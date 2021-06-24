#include "Griffin.h"
Griffin::Griffin ()
{
  this->id = "Undefined";
}

Griffin::Griffin (std::string sender_name, std::string date_scheduled, std::string id,double weight):Standard (sender_name, date_scheduled, weight)
{
  this->id = id;
}

void Griffin::display ()
{
  std::cout << "ID                    " <<this->id<< std::endl;
  std::cout << "Type of Shipping      Griffin" << std::endl;
  std::cout << "Sender Name           " << get_sender_name () << std::endl;
  std::cout << "Date of Delivery      " << get_date_scheduled () << std::endl;
  std::cout << "Weight of the package " << std::fixed<< std::setprecision(2)<<get_weight () << std::endl;
  std::cout << "==================================" << std::endl;
}
