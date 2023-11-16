// File Name: DigitQueue.cpp
// 
// Author: Raymond Nava
// Date: 4/23/2020
// Assignment Number: 6
// CS2308.255
// Instructor: Jill Seaman
//
// This program uses an int for a queue. It has a constructor, enqueue,
// dequeue, isEmpty, and a print function. 

#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

#include "DigitQueue.h"


//*****************************************************************************
//This is the constructer and sets the queue and size to default 0
DigitQueue::DigitQueue()
{
    queue = 0;
    size = 0;
}
//*****************************************************************************
//This increases the int/queue, and increases size count
void DigitQueue::enqueue(int x)
{
    queue += x * pow(10,size); //assign the next num to the int by making
                               //larger by 10^size
    size++; //adjust how many nums are inside int
}

//*****************************************************************************
//This shorts the int/queue, and decreases size count
int DigitQueue::dequeue()
{
    assert(!isEmpty());

    int num = queue % 10; //Find the remainder, or first in the list
    queue /= 10; //reduce list and lose the first number
    size--; //adjust how many nums are inside int
    return num;
}

//*****************************************************************************
//This checks to make sure that the int is empty
bool DigitQueue::isEmpty()
{
    return (size == 0); //set it to 0
}

//*****************************************************************************
//This is to print out to the screen
void DigitQueue::print()
{
   int num = queue; //to not mess with queue
   int k;
   for(int i = 0; i< size; i++)
   {
      k = num % 10; //find first number, in the 1s spot
      num /= 10; //decrease size/go onto next number/move to 1s position
      cout << k << endl;
   }
}