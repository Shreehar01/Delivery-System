#include "Standard.h"
Standard::Standard(){
        this->weight=0;
    }
    Standard::Standard(std::string sender_name,std::string date_scheduled, double weight):Delivery(sender_name, date_scheduled)
    {
        this->weight= weight;
    }
    
    void Standard::display(){
        std::cout << "Sender Name         " << get_sender_name () << std::endl;
        std::cout << "Date of Delivery    " << get_date_scheduled () << std::endl;
        std::cout << "Weight              " << this->weight << std::endl;
        std::cout << "==================================" << std::endl;
    }