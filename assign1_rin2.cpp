// assign1_rin2
//
// Raymond Nava
// Started 1/28/2020
// Assignment 1
// CS 2308.255 Jill Seaman
//
// This program is meant to keep data of bins that hold different parts,
// how many there are and the price of each part. It is stored in arrays
// representing 10 bins.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//*****************************************************************************
//This is allowing the easy change of the size of arrays

const int SIZE = 10;

//*****************************************************************************

struct BINS {

    string partName;
    int partQuantity;
    double partPrice;

};

//*****************************************************************************
//This is going to be printing out the table to the screen

void table(BINS parts[])
{
    cout << "Parts Inventory      " << "Quantity   \n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << i + 1 << parts[i].partName << setw(10) << parts[i].partQuantity
             << endl;
    }

    return;
}

//*****************************************************************************
// Calculates the price of total inventory
double total(BINS parts[])
{
    double partsTotal = 0;

    for ( int i = 0; i < SIZE; i++)
    {
        partsTotal = partsTotal + (parts[i].partQuantity * parts[i].partPrice);
    }

    return partsTotal;
}

//*****************************************************************************
// Find the largest element in the array

void maximum1(BINS maxParts[])
{
    int maxx = maxParts[0].partQuantity;
    string maxxName = maxParts[0].partName;
    for (int i = 1; i < SIZE; i++)
    {
        if (maxx < maxParts[i].partQuantity)
        {
            maxx = maxParts[i].partQuantity;
            maxxName = maxParts[i].partName;
        }
    }
    cout << maxx << maxxName << endl;
}

//*****************************************************************************
//This is the main body of the code

int main()
{
    // These are the values used for bin selection and addition/subtraction
    int selectBin = 1;
    char addRemove = 'a';
    int changeContents;

    // This is the table or array information

    BINS parts[SIZE] =
    {
    {" Chain          ", 10, 8.99},
    {" Handlebar      ", 5, 19.95},
    {" Pedals         ", 15, 7.99},
    {" Chainring      ", 21, 8.99},
    {" Cassette       ", 7, 10.99},
    {" Wheel          ", 5, 53.99},
    {" Saddle         ", 5, 29.95},
    {" Derailleur     ", 25, 11.99},
    {" Seat post      ", 18, 7.49},
    {" Tire          ", 12, 9.99}
    };

    table (parts);

    cout << endl;

    // This is the start of the bin selection and add/remove

    // First it loops to keep you in the program then it checks if its
    // a valid bin

    while (selectBin > 0 && selectBin < 12)
    {
        cout << "Select a bin number or 11 to quit: ";
        cin  >> selectBin;

        while(selectBin < 1 || selectBin > 11)
        {
            cout << "Invalid bin, try again:  ";
            cin  >> selectBin;
        }
        if (selectBin == 11)
        {
            cout << "Total Value of current inventory: $" << total (parts)
                 << endl;
            cout << "Part with the maximum quantity: ";

            maximum1(parts);

            return 0;
        }
        cout << "To add parts, enter A and to remove parts, enter R: " << endl;
        cin  >> addRemove;

        //This is where it checks if you want to add/subtract from a bin

        if (addRemove == 'A' || addRemove == 'a')
        {
            cout << "Enter how much you would like to add: ";
            cin >> changeContents;
            parts[selectBin - 1].partQuantity =parts[selectBin -1].partQuantity
                + changeContents;

            table (parts);
        }
        else if (addRemove == 'R' || addRemove == 'r')
        {
            cout << "Enter how much you would like to remove: ";
            cin >> changeContents;

                if (parts[selectBin -1].partQuantity - changeContents < 0)
                {
                    cout << "Bin doesn't have enough parts, try again " << endl;
                }
                else
                {
                    parts[selectBin - 1].partQuantity = parts[selectBin -1].partQuantity - changeContents;

                    table (parts);
                }
        }
        else
        {
            cout << "Invalid character, try again " << endl;
        }
    }

    return 0;

};
