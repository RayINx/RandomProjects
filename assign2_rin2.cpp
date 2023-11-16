// assign2_rin2
//
// Raymond Nava
// Worked with Terry Tosh
// Started 2/8/2020
// Assignment 2
// CS 2308.255 Jill Seaman
//
// This program reads in data from a file that is based off a race.
// It then asks the user different sorting and searching options
// and computes for the request.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//*****************************************************************************
// This is where I put named constants
const int SIZE = 100;

//*****************************************************************************
// This is where I create the struct
// This struct holds the main data of each runner
struct INFO
{
	int bibNum;
	string name;
	double dist;
	string time;
};

// This struct helps with the swapping process so I dont have to create
// new data types each time
struct TEMP
{
   int tempBibNum;
   string tempName;
   double tempDist;
   string tempTime;
};

//*****************************************************************************
// This is where I will read the file
void readFile(INFO racer[])
{
   ifstream inputFile;
   int i = 0;

    // Open the file.
    inputFile.open("dataset.txt");

    // Read the numbers and strings from the file and display them.
    while (inputFile >> racer[i].bibNum) // While the input of the next number
                                         // succeeds and read their bibNum
    {
        inputFile >>  ws;
        getline(inputFile, racer[i].name);      // Reads until end of line for
                                                // the name
        inputFile >> ws;
        inputFile >> racer[i].dist;             // Reads the laps
        inputFile >> ws;
        getline(inputFile, racer[i].time);      // Reads in each persons time
         i++;
    }

    // Close the file.
    inputFile.close();
}

//*****************************************************************************
// This part will display the info of each racer
void display(INFO racer[])
{
   float calc = 0.0;
   int count = 0;
   float x;

   cout << right << "BibNum" << setw(8) << "Name" << setw(19) << "Distance" << setw(11)
        << "Time" << setw(18) <<  setprecision(4) <<"Avg Spd" << endl;


   for(int i = 0; i < 6; i++)
   {
      cout << left << setw(10) << racer[i].bibNum << setw(15) << racer[i].name << setw(15)
      << racer[i].dist << setw(15) << racer[i].time;

      string tempStr = racer[i].time;
      stringstream time(tempStr);

   while(getline(time,tempStr, ':'))
      {
         istringstream(tempStr) >> x;
      
         if(count == 0)
         {
            calc += x;
            count++;
         }
         else if(count == 1)
         {
            calc += x * (1.0/60.0);
            count++;
         }
         else if (count == 2)
         {
         calc += x * (1.0/3600.0);
         }
      }
      cout << setw(10) << racer[i].dist / calc << endl;
   }
}

//*****************************************************************************
// This part is searching with binary
// I want to say there is a logical error somewhere in here but I cant find it.
int bSearch(INFO racer[], int value)
{
   int first = 0,             // First array element
       last = SIZE - 1,       // Last array element
       middle,                // Mid point of search
       position = -1;         // Position of search value
   bool found = false;        // Flag

   while (!found && first <= last)
   {
      middle = (first + last) / 2;     // Calculate mid point
      if (racer[middle].bibNum == value)      // If value is found at mid
      {
         position = middle;
         found = true;
      }
      else if (racer[middle].bibNum > value)  // If value is in lower half
      {
         last = middle - 1;
         cout << last << " ";
      }
      else if (racer[middle].bibNum < value) // If value is in upper half
      {
         first = middle + 1;           
         cout << middle <<  " ";
      }
   }
   return position;
}

void searchRacer(INFO racer[])
{
   int results = 0;
   int racerNum;

   cout << "Enter the racer number you wish to search for: ";
   cin >> racerNum;


   results = bSearch(racer, racerNum);

   if(results == racerNum)
   {
      cout << "That racer is: " << left << setw(10) << racer[results].bibNum
           << setw(15) << racer[results].name << setw(15) << racer[results].dist 
           << setw(15) << racer[results].time;
   }
   else
   {
      cout << "That racer does not exist.\n";
   }
}

//*****************************************************************************
// This part will sort the bib number
void bibSort(INFO racer[], TEMP tempp[])
{
   bool swap;

   do
   {
      swap = false;
      for (int i = 0; i < 5; i++) // 5 here because doesnt work otherwise
      {
         if (racer[i].bibNum > racer[i + 1].bibNum)
         {
            // Swapping the bib num of racer
            tempp[i].tempBibNum = racer[i].bibNum;
            racer[i].bibNum = racer[i + 1].bibNum;
            racer[i + 1].bibNum = tempp[i].tempBibNum;

            // Swapping the name of racer
            tempp[i].tempName = racer[i].name;
            racer[i].name = racer[i + 1].name;
            racer[i + 1].name = tempp[i].tempName;

            // Swapping the distance completed by racer
            tempp[i].tempDist = racer[i].dist;
            racer[i].dist = racer[i + 1].dist;
            racer[i + 1].dist = tempp[i].tempDist;

            // Swapping the time by racer
            tempp[i].tempTime = racer[i].time;
            racer[i].time = racer[i + 1].time;
            racer[i + 1].time = tempp[i].tempTime;

            swap = true;
         }
      }
   } while (swap);

}

//*****************************************************************************
// This part will sort the bib number
void distTimeSort(INFO racer[], TEMP tempp[])
{
   bool swap;

   do
   {
      swap = false;
      for (int i = 0; i < 5; i++) // 5 here because doesnt work otherwise
      {
         if (racer[i].dist > racer[i + 1].dist)
         {

            // Swapping the bib num of racer
            tempp[i].tempBibNum = racer[i].bibNum;
            racer[i].bibNum = racer[i + 1].bibNum;
            racer[i + 1].bibNum = tempp[i].tempBibNum;

            // Swapping the name of racer
            tempp[i].tempName = racer[i].name;
            racer[i].name = racer[i + 1].name;
            racer[i + 1].name = tempp[i].tempName;

            // Swapping the distance completed by racer
            tempp[i].tempDist = racer[i].dist;
            racer[i].dist = racer[i + 1].dist;
            racer[i + 1].dist = tempp[i].tempDist;

            // Swapping the time by racer
            tempp[i].tempTime = racer[i].time;
            racer[i].time = racer[i + 1].time;
            racer[i + 1].time = tempp[i].tempTime;

            swap = true;
         }
         if (racer[i].dist == racer[i + 1].dist)
         {
             if (racer[i].time > racer[i+1].time)
             {
                // Swapping the bib num of racer
                tempp[i].tempBibNum = racer[i].bibNum;
                racer[i].bibNum = racer[i + 1].bibNum;
                racer[i + 1].bibNum = tempp[i].tempBibNum;

                // Swapping the name of racer
                tempp[i].tempName = racer[i].name;
                racer[i].name = racer[i + 1].name;
                racer[i + 1].name = tempp[i].tempName;

                // Swapping the distance completed by racer
                tempp[i].tempDist = racer[i].dist;
                racer[i].dist = racer[i + 1].dist;
                racer[i + 1].dist = tempp[i].tempDist;

                // Swapping the time by racer
                tempp[i].tempTime = racer[i].time;
                racer[i].time = racer[i + 1].time;
                racer[i + 1].time = tempp[i].tempTime;
             }
         }
      }
   } while (swap);

}
//*****************************************************************************
// This is a linear search looking for a persons name
void nameSearch(INFO racer[])
{
   int i = 0;       // Used as a subscript to search array
   bool found = false;  // Flag to indicate if the value was found
   string findName;

   cout << "Enter name of a racer to look for: " << endl;
   getline(cin >> ws, findName);

   while (found == false)
   {

     if ((racer[i].name.compare(findName)) == 0 && !found)  // If the value is found
      {
         racer[i].name;
         cout << "The number of the racer with the name " << racer[i].name << " is: " << racer[i].bibNum;
         found = true;       // Set the flag
      }
      i++;                   // Go to the next element */
   };
}

//*****************************************************************************
// The menu will be called here
void menu(INFO racer[], TEMP tempp[])
{
   // Constants for menu choices
   const int bibNum = 1,
             distTime = 2,
             name = 3,
             result = 4,
			    quit = 5;

   // Menu choice
   int choice;
   string findName;

   do
   {
      // Display the menu.
      cout << "\n\t\tMenu\n\n"
         << "1. Display results by bib number\n"
         << "2. Display Results sorted by distance, then time\n"
         << "3. Lookup a bib number given a name\n"
         << "4. Lookup a result by bib number\n"
		   << "5. Quit the Program\n\n"
         << "Enter your choice: ";
      cin >> choice;

      // Validate the menu selection.
      while (choice < 0 || choice > 5)
      {
         cout << "Please enter a valid menu choice: ";
         cin >> choice;
      }

      // Validate and process the user's choice.
      if (choice != quit)
      {

         // Respond to the user's menu selection.
         switch (choice)
         {
            case bibNum:
               bibSort(racer, tempp);
               display(racer);
               break;
            case distTime:
               distTimeSort(racer, tempp);
               display(racer);
               break;
            case name:
               nameSearch(racer);
				   break;
			   case result:
				   searchRacer(racer);
				   break;
         }

      }
   } while (choice != quit);
};

//*****************************************************************************
int main()
{
	INFO racer[SIZE];
   TEMP tempp[SIZE];

   readFile(racer);

	menu(racer,tempp);

   return 0;
}
