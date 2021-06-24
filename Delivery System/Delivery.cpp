#include "Delivery.h"

Delivery::Delivery ()
{
  this->sender_name = "Unknown";
  this->date_scheduled = "Unknown";
}

Delivery::Delivery (std::string sender_name, std::string date_scheduled)
{
  this->sender_name = sender_name;
  this->date_scheduled = date_scheduled;
}


void Delivery::display ()
{
  std::cout << "Sender Name         " << get_sender_name () << std::endl;
  std::cout << "Date of Delivery    " << get_date_scheduled () << std::endl;
  std::cout << "==================================" << std::endl;
}
