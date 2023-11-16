// Author: Raymond Nava
//
// Serial Number : 38
//
// Due Date: 9/29/2023
// Programming Assignment Number 3
// Fall 2023 - CS 3358 - 008
//
// Instructor: Husain Gholoom
//
// This program

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

class myInt
{
public:
    int yourInt;
    bool loop = true; // continue main loop
    bool loop2;       // continue 2nd loop
    char c;           // Char to enter if end program or not
    void enterInt();
    vector<int> vectInt;
private:
    void isMultiple(int yi);
    void isEvenOdd(int ed, vector<int> vectD);
    void sqRoot(int sr);
    void isPrime(int ip);
    void isPerfect(int ip, vector<int> vectP);
};

// Function to get int from user and validate that it meets parameters
void myInt:: enterInt()
{
    myInt mInt; // declare object for this function

    while(mInt.loop)
    {
        mInt.loop2 = true; // Reset loop2 to continue program
        cout << "Enter an integer: ";
        cin  >> mInt.yourInt;
        cout << endl;

        if(mInt.yourInt >= 100)
        {
            //***Program continues here for function calls
            mInt.isMultiple(mInt.yourInt); // function call to isMultiple
            mInt.isEvenOdd(mInt.yourInt, mInt.vectInt);  // function call
                                                         // to isEvenOdd
            mInt.sqRoot(mInt.yourInt);     // function call to sqRoot
            mInt.isPrime(mInt.yourInt);    // function call to isPrime
            mInt.isPerfect(mInt.yourInt, mInt.vectInt);  // function call
                                                         // to isPerfect

            while(mInt.loop2) // Loop2 to continue program or not
            {
                cout << "Would you like to go again? \n";
                cout << "Enter Y or N :";
                cin >> mInt.c;
                cout << endl;
                if(mInt.c == 'Y' || mInt.c == 'y')
                {
                    mInt.loop2 = false; // cancel loop and return to main loop
                    cout << endl;
                }
                else if(mInt.c == 'N' || mInt.c == 'n')
                {
                    mInt.loop2 = false; // Cancel loop and continue to main
                    mInt.loop = false; // cancel main loop to exit
                }
                else
                {
                    cout << "\n***ERROR*** Must enter Y|y or N|n \n\n";
                    cin.clear();
                    cin.ignore(256, '\n');
                }
            }
        }
        else
        {
            cout << "\n***ERROR*** Must enter an integer that is >= 100\n\n";
            cin.clear();
            cin.ignore(256, '\n');
        }
    }
}

// Function to find if the int is a multiple of 7,11,13
void myInt:: isMultiple(int yi) //Using yi = your int
{
    cout << "\nA   " << yi;

    if (yi% 7 == 0)
        cout << " is a multiple of 7, ";
    else
        cout << " not a multiple of 7, ";
    if(yi % 11 == 0)
        cout << "a multiple of 11, ";
    else
        cout << "not a multiple of 11, ";
    if(yi % 13 == 0)
        cout << "and a multiple of 13\n";
    else
        cout << "and not a multiple of 13\n";
}

// Function to find if the sum of the int is even or odd
void myInt:: isEvenOdd(int ed, vector<int> vectD) // Using ed = Even odD
{
    cout << "B   Sum of its digits is ";
    while(ed>0)
    {
        vectD.push_back(ed%10); // add element to vect
        ed = ed/10;
    }
    //ed now should equal 0, to use that 1 int

    for(int i=0; i <vectD.size(); i++)
    {
        ed += vectD[i]; // add each vect element saved to get sum
    }

    if(ed % 2 == 0)
        cout << "even\n";
    else
        cout << "odd\n";
}

// Function to find the square root of the int
void myInt:: sqRoot(int sr) // Using sr = Square Root
{
    cout << "C   SQRT of " << sr << " is " << fixed << setprecision(5)
         << sqrt(sr) << endl; // Set fixed to 5 decimal points, call
                             // cmath function for finding sqrt
}

void myInt:: isPrime(int ip) // using int ip = is prime
{
    cout << "D   " << ip ;

    for(int i = 2; i <= ip/2 +1; i++) // Check each to half the value of int
    {
        if(ip % i == 0)
        {
            cout << " is not a prime number\n";
            return; //empty return to terminate early
        }
    }

    cout << " is a prime number\n"; // if all else, its a prime
}

// Function to find if number is perfect
void myInt:: isPerfect(int ip, vector<int> vectP)
{
    cout << "E   " << ip;
    vectP.push_back(1); //start with 1 because all ints have a multiple of 1

    for(int i = 2; i <= ip/2 +1; i++) // Check each to half the value of int
    {
        if(ip % i == 0)
        {
            vectP[0] += i;
        }
    }
    if (vectP[0] == ip)
        cout << " is a perfect number\n\n";
    else
        cout << " is not a perfect number\n\n";
}

//Main function
int main()
{
    myInt mInt; //define object of mInt

    cout << "Welcome to my Interger Manipulations Program.\n\n";

    mInt.enterInt();

    cout << "\n\nThis program was implemented by Raymond Nava"
         << "\nSeptember - 2023";

    return 0;
}
