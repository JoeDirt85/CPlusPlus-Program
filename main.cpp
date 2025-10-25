//Josiah Roske\
//CS-210

#include "GroceryCounter.h"
#include "MenuDisplay.h"

//main function of program
int main() {
    //calls constructor to open the given .txt file
	GroceryCounter counter("CS210_Project_Three_Input_File.txt");

	int choice = 0; //initalization of int choice for switch
	string itemName; //initalization of string itemname

    //do while loop for main program that takes user input until they choose to exit
	do {
		DisplayMenu(); //calls function to display the usr menu
		cout << "Enter option: "; //asks user to enter an input option

        //loop to check if valid input option was entered
        if (!(cin >> choice)) {
            cin.clear(); //clears the fail state of invalid input
            cin.ignore(1000, '\n'); //ignores invalid input options
            cout << "Invalid entry. Please enter a number between 1 and 4.\n"; //prints error message if invalid input is recieved 
            continue; 
        }

        cin.ignore(1000, '\n'); //clears line 

        //switch that takes user input 
		switch (choice) {
        case 1: //option 1 of user menu
            cout << "Enter the item name: "; //asks for item name to be searched 
            getline(cin, itemName); //takes itemname input
            //prints the item name and the amount of times it appears
            cout << itemName << " appears "
                << counter.GetItemCounts(itemName) //calls get item counts function
                << " times." << endl;
            break;

        case 2: //option 2 from user menu, displays every item and the amount of times they appear
            cout << "\nItem Counts:" << endl;
            counter.DisplayItemCounts(); //calls display item counts function
            break;

        case 3: //option 3 from user menu, display histogram of items
            cout << "\nItem Histogram:" << endl;
            counter.DisplayHistogram(); //calls the display histogram function
            break;

        case 4: //option 4 from user menu, quits the progam
            cout << "Exiting program. Goodbye!" << endl;
            break;

        default: //prints error message for invalid choice
            cout << "Invalid choice. Please try again." << endl;
		}
        
    } while (choice != 4); //while loop that continues program if 4 isnt entered

    return 0;
}