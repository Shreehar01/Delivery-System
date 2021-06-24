#include <iostream>
#include <ctime>
#include <vector>
#include "menufunctions.h"
int main ()
{
    std::srand(std::time(0));
    std::vector<std::string> list_of_id;    // Vector that will store the id of all the Deliveries in the system.
    std::vector <Delivery*> Deliveries;    // Vector that will store the pointer of all the Deliveries in the system.
    int input=0;                           // Variable that will store commands from the user. Can have any number from (1-7) to execute different tasks.
    int flag=0;                            // Variable used to determine when to quit the program. When it equals 1, the program will end.
    while (flag != 1){
        main_menu();
        std::cin >> input;
        switch(input){
            case 1: schedule_new_delivery(Deliveries, list_of_id);
                    break;
            case 2: remove_delivery(Deliveries, list_of_id);
                    break;
            case 3: load_delivery(Deliveries, list_of_id);
                    break;
            case 4: save_delivery(Deliveries);
                    break;
            case 5: print_all_deliveries(Deliveries);
                    break;
            case 6: print_deliveries_by_type(Deliveries);
                    break;
            case 7: flag= confirmation(Deliveries);
                    break;
            default: std::cout<< "Error! Please enter number from 1-7" <<std::endl;
        }
    }
     std::cout << "Your program has ended"<< std::endl;
    return 0;
}


