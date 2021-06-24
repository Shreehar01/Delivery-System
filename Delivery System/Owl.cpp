#include "Owl.h"
Owl::Owl ()
{
  this->id = "Undefined";

}

Owl::Owl (std::string sender_name, std::string date_scheduled, std::string id, double weight):Standard (sender_name, date_scheduled, weight)
{
  this->id = id;
}

void Owl::display ()
{
  std::cout << "ID                    " <<this->id<< std::endl;
  std::cout << "Type of Shipping      Owl" << std::endl;
  std::cout << "Sender Name           " << get_sender_name () << std::endl;
  std::cout << "Date of Delivery      " << get_date_scheduled () << std::endl;
  std::cout << "Weight of the package " <<std::fixed<< std::setprecision(2)<< get_weight () << std::endl;
  std::cout << "==================================" << std::endl;
}
