#include "menufunctions.h"

void main_menu ()
{
  std::cout << " What would you like to do? " << std::endl;
  std::cout << "==================================" << std::endl;
  std::cout << "1. Schedule a new Delivery" << std::endl;
  std::cout << "2. Remove a Delivery" << std::endl;
  std::cout << "3. Load Deliveries from a file" << std::endl;
  std::cout << "4. Save Deliveries to a file" << std::endl;
  std::cout << "5. Print all Deliveries" << std::endl;
  std::cout << "6. Print Deliveries by type" << std::endl;
  std::cout << "7. Quit" << std::endl;
  std::cout << "==================================" << std::endl;
  std::cout << "Enter numbers from 1-7 to carry out the respective instructions."<< std::endl;
}




bool is_id_unique (std::vector < std::string > &list_of_id, std::string id)
{
  if (std::find (list_of_id.begin (), list_of_id.end (), id) != list_of_id.end ())   //Checking if the newly generated id exists in the list of ids in the system.
    {
      return false;
    }
  else
    {
      return true;
    }
}




void schedule_new_delivery (std::vector < Delivery * >&Deliveries, std::vector < std::string > &list_of_id)
{
    
  //Prompting the user to input sender's name.
  std::string sender_name;
  std::cout << "Enter sender's name" << std::endl;
  std::getline (std::cin >> std::ws, sender_name); //To ensure we take values with spaces in between as well.
  
  
  //Prompting the user to input sender's name.
  //Checking if the date entered is valid and converting the date to desired format.
  int year, month, day;   //year must be positive 4 digits. month must be between 1 and 12 inclusive. day must be between 1 and 31 inclusive.
  std::string date_scheduled = "";
  do{
      
      std::cout << "Enter month(mm)" << std::endl;
      std::cin >> month;
      std::cout << "Enter day(dd)" << std::endl;
      std::cin >> day;
      std::cout << "Enter year(yyyy)" << std::endl;
      std::cin >> year;
      if ((year <= 0 || std::to_string (year).length () != 4) || (month <= 0 || month > 12) || (day <= 0 || day > 31))
        {
          std::cout << "Invalid Date! Please try again." << std::endl;
        }
  }while((year <= 0 || std::to_string (year).length () != 4) || (month <= 0 || month > 12) || (day <= 0 || day > 31));
  
  date_scheduled += std::to_string (month).length () < 2 ? "0" + std::to_string (month) + "-" : std::to_string (month) + "-";// To ensure month is in mm format and not just m
  date_scheduled += std::to_string (day).length () < 2 ? "0" + std::to_string (day) + "-" : std::to_string (day) + "-";// To ensure day is in dd format and not just d.
  date_scheduled += std::to_string (year);
  
  //Prompting the user to select type of delivery and scheduling delivery based on given information.
  std::string id;
  bool is_id_possible = false;      // Variable that stores false if the id is already taken and stores true if id is unique. 
  int delivery_type;                //Variable that stores 1 and 2 depending on the type of delivery user wants to create.
  
  do{
      std::cout << "Enter the type of delivery" << std::endl;
      std::cout << "1. Vanishing Cabinet" << std::endl;
      std::cout << "2. Standard Delivery" << std::endl;
      std::cin >> delivery_type;
      if(delivery_type != 1 && delivery_type != 2)
          {
            std::cout<< "Invalid entry! Please try again."<< std::endl;  
          }
    } while(delivery_type != 1 && delivery_type != 2);
  
  if (delivery_type == 1)
    {
        std::string id1, id2;     // id1 and id2 are the two parts separated by '-' in id of Vanishing Cabinet
        
        //Ensuring that the generated id is unique.
        while (is_id_possible != true)
    	  {
        	  id1 = std::to_string (std::rand () % 100000000);
        	  //To ensure that first part of the id has 8 digits.
        	  while(id1.length() != 8)
        	  {
        	      id1 = "0"+id1;
        	  }    
        	  id2 = std::to_string (std::rand () % 100000000);
        	  //To ensure that second part of the id has 8 digits.
        	  while(id2.length() != 8)
        	  {
        	      id2 = "0"+id2;
        	  }   
        	  id = id1 + "-" + id2;
        	  is_id_possible = is_id_unique (list_of_id, id);  //Checking if id is unique.
    	  }
        list_of_id.push_back (id);                          //Storing newly generated id in the list of ids in the system.
        Deliveries.push_back (new VanishingCabinet (sender_name, date_scheduled, id));//Storing pointer of the delivery in the vector.
    }
  else if (delivery_type == 2)
    {
      double weight=0;  //weight of the package. must be greater than 0.
      //Ensuring that the weight entered is valid.
      do{
          std::cout << "Enter the weight" << std::endl;
          std::cin >> weight;
          if (weight <= 0)
        	{
        	  std::cout << "Invalid entry for weight! Try again." << std::endl;
        	}
        } while( weight <=0);
      
      if (weight <= 1.58)
	    {
	        //Ensuring that the generated id is unique.
	        while (is_id_possible != true)
	            {
        	      id = std::to_string (std::rand () % 1000); 
        	      //To ensure that the id is has 3 digits.
            	  while(id.length() != 3)
            	  {
            	      id = "0"+id;
            	  }
            	  id = "o" +id;
        	      is_id_possible = is_id_unique (list_of_id, id);   //Checking if id is unique.
        	    }
	        list_of_id.push_back (id);                           //Storing newly generated id in the list of ids in the system.
	        Deliveries.push_back (new Owl (sender_name, date_scheduled, id, weight)); 
	    }
      else
	    {
	      //Ensuring that the generated id is unique.
    	 while (is_id_possible != true)
            {
    	      id = std::to_string (std::rand () % 10000000);
    	      //To ensure that the id is has 7 digits.
        	  while(id.length() != 7)
        	  {
        	      id = "0"+id;
        	  }
        	  id = "g" +id;
    	      is_id_possible = is_id_unique (list_of_id, id);   //Checking if id is unique.
    	    }
	  list_of_id.push_back (id);                                //Storing newly generated id in the list of ids in the system.
	  Deliveries.push_back (new Griffin (sender_name, date_scheduled, id, weight)); 
	    }
    }
  
  std::cout << "Your delivery has been scheduled." << std::endl;
}




void print_all_deliveries (std::vector < Delivery * >&Deliveries)
{
  //Checking if there are existing deliveries in the system or not.
  if (Deliveries.size () == 0)
    {
      std::cout << "There are no deliveries in the system." << std::endl;
      return;
    }
  std::cout << "==================================" << std::endl;
  std::cout << "*****   Printing Deliveries  *****" << std::endl;
  std::cout << "==================================" << std::endl;
  
  //Printing all the deliveries 
  for (int i = 0; i < Deliveries.size (); i++)
    {
      std::cout << "**** Entry no. " << i + 1 << " ****" << std::endl;
      Deliveries.at (i)->display ();
    }
  std::cout << "All the deliveries have been printed." << std::endl;
}




void print_deliveries_by_type (std::vector < Delivery * >&Deliveries)
{
  //Checking if there are existing deliveries in the system or not.
  if (Deliveries.size () == 0)
    {
      std::cout << "There are no deliveries in the system." << std::endl;
      return;
    }
  int type = 0;     //Variable that stores the type of delivery that is to be printed. Can be 1, 2 or 3.
  
  //Ensuring that the user entered correct choice of delivery.
  do{
      std::cout << "Select the delivery type you want to search in the entry" <<std::endl;
      std::cout << "1. Vanishing Cabinet" << std::endl;
      std::cout << "2. Standard Shipping->Owl" << std::endl;
      std::cout << "3. Standard Shipping->Griffin" << std::endl;
      std::cin >> type;
      if (type != 1 && type != 2 && type != 3)
        {
          std::cout << "Invalid Entry!! Please try again." << std::endl;
        }
  } while(type != 1 && type != 2 && type != 3 );
  
  std::cout << "==================================" << std::endl;
  std::cout << "*****   Printing Deliveries  *****" << std::endl;
  std::cout << "==================================" << std::endl;
  int count = 0;    // Variable that checks the number of deliveries of the type that is selected by the user.
  
  //Printing all the deliveries of the given type.
  for (int i = 0; i < Deliveries.size (); i++)
    {
      //Checking which child delivery class the pointer of delivery can be suitably casted into.
      if (dynamic_cast < VanishingCabinet * >(Deliveries.at (i)) && type == 1)
    	{
    	  Deliveries.at (i)->display ();
    	  count++;
    	}
      else if (dynamic_cast < Owl * >(Deliveries.at (i)) && type == 2)
    	{
    	  Deliveries.at (i)->display ();
    	  count++;
    	}
      else if (dynamic_cast < Griffin * >(Deliveries.at (i)) && type == 3)
    	{
    	  Deliveries.at (i)->display ();
    	  count++;
    	}
    }
    
  // Printing the final message depending on the existence of the type of delivery that was selected. 
  if (count == 0)
    std::cout << "Sorry!! There are no deliveries of the type you selected." <<std::endl;
  else
    std:: cout << "All the deliveries of the type you selected have been printed."<< std::endl;
}




void remove_delivery (std::vector < Delivery * >&Deliveries, std::vector < std::string > &list_of_id)
{
  //Checking if there are existing deliveries in the system or not.
  if (Deliveries.size () == 0)
    {
      std::cout << "There are no deliveries in the system to remove." << std::endl;
      return;
    }

  //Prompting the user to enter the entry number to be deleted and ensuring that it exists.
  int entry;   //Entry number can have any integer starting from 1 to the size of the Delivery vector. 
  do{
      std::cout << "Enter the entry number which you want to remove::" << std::endl;
      std::cin >> entry;
      if (entry > Deliveries.size () || entry <= 0)
        {
          std::cout << "Invalid Entry!! Please try again." << std::endl;
        }
  } while (entry > Deliveries.size () || entry <= 0);
  
  //Recreating deliveries of a suitable child class from the list of deliveries in the system to get its id.
  std::string id;    //Variable that stores the id of object that is being removed from the system.
  if (dynamic_cast < VanishingCabinet * >(Deliveries.at (entry - 1))) 
    {
      VanishingCabinet *delivery = dynamic_cast < VanishingCabinet * >(Deliveries.at (entry - 1));
      id = delivery->get_id ();     
    }
  else if (dynamic_cast < Owl * >(Deliveries.at (entry - 1)))
    {
      Owl *delivery = dynamic_cast < Owl * >(Deliveries.at (entry - 1));
      id = delivery->get_id ();     
    }
  else if (dynamic_cast < Griffin * >(Deliveries.at (entry - 1)))
    {
      Griffin *delivery = dynamic_cast < Griffin * >(Deliveries.at (entry - 1));
      id = delivery->get_id ();    
    }
    
  //Removing the delivery object and its id. 
  list_of_id.erase (std::remove (list_of_id.begin (), list_of_id.end (), id), list_of_id.end ());  //Removing the id of the selected delivery from the existing list of ids in the system.
  delete Deliveries.at (entry - 1);                                  //Deallocating the memory occupied by the selected delivery.
  Deliveries.erase (Deliveries.begin () + entry - 1);                //Deleting the selected delivery from the system(vector).
  std::cout << "Delivery has been removed" << std::endl;
}




void save_delivery (std::vector < Delivery * >&Deliveries)
{
  //Checking if there are existing deliveries in the system or not.
  if (Deliveries.size () == 0)
    {
      std::cout << "There are no deliveries in the system to save." << std::endl;
      return;
    }
    
  //Prompting the user to input filename and ensuring it is in .txt format.
  std::string file_name;                      //Variable that stores the name of the file eneterd by user.
  do{
      std::cout <<"Enter the filename(in .txt format) form in which you want to save the deliveries:"<< std::endl;
      std::cin >> file_name;
      if (file_name.length () <= 4 || file_name.substr (file_name.length () - 4, 4) != ".txt")
        {
          std::	cout << "Invalid filename. Note that the file must be in .txt format. Please try again." << std::endl;
        }
    } while(file_name.length () <= 4 || file_name.substr (file_name.length () - 4, 4) != ".txt");
  
  std::string error = "Error in accessing the file.";   //Variable that stores the error message that is to be displayed when an error occures in file handling.
  std::string sender_name_edit="";   //Variable that contain's sender's name with '_' instead of ' ' in the middle of first, middle or last name.(eg. Shreehar_Joshi)
  try
  {
    std::fstream output (file_name, output.out | output.app);
    if (output.fail ())
      throw error;
      
    //Saving all the deliveries from the system to the file.
    for (int i = 0; i < Deliveries.size (); i++)
      {
	if (dynamic_cast < VanishingCabinet * >(Deliveries.at (i)))
	  {
	    VanishingCabinet *delivery = dynamic_cast < VanishingCabinet * >(Deliveries.at (i));    //Recreating delivery of a suitable child class from the list of deliveries in the system.
	    sender_name_edit= delivery->get_sender_name();
	    std::replace (sender_name_edit.begin (), sender_name_edit.end (), ' ', '_');   
	    output << std::fixed<< std::setprecision (2)<< delivery->get_id () << " " << "VanishingCabinet" << " " << sender_name_edit << " " << delivery->get_date_scheduled () << " " << 0.00 << std::endl;
	  }
	else if (dynamic_cast < Owl * >(Deliveries.at (i)))
	  {
	    Owl *delivery = dynamic_cast < Owl * >(Deliveries.at (i));                              //Recreating delivery of a suitable child class from the list of deliveries in the system.
	    sender_name_edit= delivery->get_sender_name();
	    std::replace (sender_name_edit.begin (), sender_name_edit.end (), ' ', '_');            //Replacing "_" with " " in sender's name to to store in a file.
	    output << std::fixed<< std::setprecision (2)  << delivery->get_id () << " " << "Owl" << " " << sender_name_edit << " " << delivery->get_date_scheduled () << " " << delivery->get_weight () << std::endl;
	  }
	else if (dynamic_cast < Griffin * >(Deliveries.at (i)))
	  {
	    Griffin *delivery = dynamic_cast < Griffin * >(Deliveries.at (i));                     //Recreating delivery of a suitable child class from the list of deliveries in the system.
	    sender_name_edit= delivery->get_sender_name();
	    std::replace (sender_name_edit.begin (), sender_name_edit.end (), ' ', '_');           //Replacing " " with " " in sender's name to store in a file.
	    output<< std::fixed << std::setprecision (2) << delivery->get_id () << " " << "Griffin" << " " << sender_name_edit << " " << delivery->get_date_scheduled () << " " << delivery->get_weight () << std::endl;
	  }
      }
    output.close ();
    std::cout << "All the deliveries have been saved." << std::endl;
  }
  //Printing if there is an error during file handling.
  catch (std::string error)
  {
    std::cout << error << std::endl;
    return;
  }
}




void load_delivery (std::vector < Delivery * >&Deliveries, std::vector < std::string > &list_of_id)
{
  //Prompting the user to enter filename from which the deliveries are to be loaded.
  std::string file_name;
  do{
      std::cout <<"Enter the filename(in .txt format) from which you want to load the deliveries"<< std::endl;
      std::cin >> file_name;
      //Ensuring that the file entered is in .txt format.
      if (file_name.length()<= 4 ||file_name.substr (file_name.length () - 4, 4) != ".txt")
        {
          std::cout << "Invalid filename. Note that the file must be in .txt format. Please try again." << std::endl;
        }
    } while(file_name.length()<= 4 ||file_name.substr (file_name.length () - 4, 4) != ".txt");
  
  std::string error = "Error in opening file or file not found.";  //Variable that stores the error message that is to be displayed when error occures in file handling.
  std::string delivery_type, id, sender_name, date_scheduled;      //Variables that store type, id, sender's name and date of delivery.
  double weight;                                                   //Variable that store the weight of the package.
  
  
  
  try
  {
    std::fstream input (file_name, input.in);
    if (input.fail ())
      throw error;
    //Reading the contents of the file.
    bool is_id_possible;           // Variable that stores false if the id is already taken and stores truw if id is unique.
    while (!input.eof ())
      {
	    input >> id >> delivery_type >> sender_name >> date_scheduled >>weight;
	    std::replace (sender_name.begin (), sender_name.end (), '_', ' ');       //Replacing "_" with " " in sender's name to have better layout for the customer.
	    if (input.eof ())         //Ensuring that the last line of the file isnt read twice. 
	    break;
	    
	    is_id_possible = false;
	    //Creating appropriate Child Delivery classes and storing their pointers in the system(vector).
	    if (delivery_type == "VanishingCabinet")
    	   {
    	    //To ensure that the id is unique. A new id is generated if the id is found to clash with the ones already in the system.
    	    if(is_id_unique(list_of_id, id) == false)//Checking if the id is unique.
        	    {
        	      while (is_id_possible != true)
        	       {
        	          std::string id1, id2;       // First and Second part of id of Vanishing Cabinet separated by "-" in the middle.
                      id1 = std::to_string (std::rand () % 100000000);
                	  //To ensure that first part of the id is not less than 8 digits.
                	  while(id1.length() != 8)
                	  {
                	      id1 = "0"+id1;
                	  }    
                	  id2 = std::to_string (std::rand () % 100000000);
                	  //To ensure that second part of the id is not less than 8 digits.
                	  while(id2.length() != 8)
                	  {
                	      id2 = "0"+id2;
                	  }   
                	  id = id1 + "-" + id2;
                	  is_id_possible = is_id_unique (list_of_id, id);  //Checking if id is unique.
        	       }
        	    }
            list_of_id.push_back (id);                          //Storing id in the list of ids in the system.
    	    Deliveries.push_back (new VanishingCabinet (sender_name, date_scheduled, id));
    	   }
    	   
    	else if (delivery_type == "Owl")
    	   {
    	     //To ensure that the id is unique. A new id is generated if the id is found to clash with the ones already in the system.
    	     if(is_id_unique(list_of_id, id) == false)  //Checking if the id is unique.
        	   {
        	      while (is_id_possible != true)
        	       {
                      id = std::to_string (std::rand () % 1000); 
            	      //To ensure that the id is not less than 3 digits.
                	  while(id.length() != 3)
                	  {
                	      id = "0"+id;
                	  }
                	  id = "o" +id;
            	      is_id_possible = is_id_unique (list_of_id, id);   //Checking if id is unique. 
        	       }
        	   }
        	 list_of_id.push_back (id);                          //Storing id in the list of ids in the system.
    	     Deliveries.push_back (new Owl (sender_name, date_scheduled, id, weight));
    	   }
    	   
    	else if(delivery_type== "Griffin")
    	   {
    	     //To ensure that the id is unique. A new id is generated if the id is found to clash with the ones already in the system.
    	     if(is_id_unique(list_of_id, id) == false)  //Checking if the id is unique.
        	   {
        	      while (is_id_possible != true)
        	       {
                      id = std::to_string (std::rand () % 10000000); 
            	      //To ensure that the id is not less than 7 digits.
                	  while(id.length() != 7 )
                	  {
                	      id = "0"+id;
                	  }
                	  id = "g" +id;
            	      is_id_possible = is_id_unique (list_of_id, id);   //Checking if id is unique. 
        	       }
        	   }
        	 list_of_id.push_back (id);                          //Storing id in the list of ids in the system. 
    	     Deliveries.push_back (new Griffin (sender_name, date_scheduled, id, weight));
    	   }
      }
    std::cout << "All the deliveries have been loaded" << std::endl;
    input.close ();
  }
  
  //Printing if there is an error during file handling.
  catch (std::string error)
  {
    std::cout << error << std::endl;
    return;
  }
}




int confirmation (std::vector < Delivery * >&Deliveries)
{
  // Checking if there are existing deliveries in the system.
  if (Deliveries.size () == 0)
    return 1;
    
  // Asking for confirmation to quit from the user.
  int response;  //Variable that stores the response from the user. Will store 1 if the user wants to quit and any other number if user cancels the quitting.
  if (Deliveries.size () > 0)
    {
      std::cout <<"You have deliveries that may be unsaved. Are you sure you want to quit? "<< std::endl;
      std::cout << "Press 1 to Confirm." << std::endl;
      std::cout << "Press any other number to Cancel" << std::endl;
      std::cin >> response;
    }
  if (response == 1)
    {
      //Deleting all the deliveries from the system(vector) and deallocating their memories.
      for (int i = Deliveries.size () - 1; i >= 0; i--)
	   {
	     delete Deliveries.at (i);                     //Deallocating memory where delivery object is stored.
	     Deliveries.erase (Deliveries.begin () + i);   // Removing pointer that points to delivery information from the system(vector).
	   }

    }
  return response;
}
