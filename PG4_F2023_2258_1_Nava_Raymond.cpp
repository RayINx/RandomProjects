// Author: Raymond Nava
//
// Serial Number : 38
//
// Programming Assignment Number 4
//
// Fall 2023 - CS 3358 - 008
//
// Due Date : Oct 16th 2023
//
// Instructor: Husain Gholoom
//
// This program will simulate an ADT stack and queue using linked list ADT.
// To do this it will be implemented using pointers and preform a series of
// operations, that include IN ORDER
// A) Building a stack of 5 random Capital letter that are >= C and <= K;
// B) A queue of 5 capital letters that are >= H and <= S;
// C) insert element W in stack;
// D) insert X in stack;
// E) remove element from stack;
// F) insert X in queue;
// G) insert A at 2nd location in queue;
// H) remove 1st element of queue;
// I) remove 4th element of queue;
// J) find min and max element in queue;
// K) delete the entire stack;
// L) Remove W from stack, error message if empty(which it should be)
// M) Delete entire queue
// N) Remove X from queue, error message if empty (which it should be)
// X) Exit program
// The entire list will be displayed after steps A-I, K, and M.

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//Struct for LL node for stack
struct Node
{
  char data;
  Node *link;

  Node(char n)
  {
    this->data = n;
    this->link = NULL;
  }
};

//Class for functions related to stack
class myStack
{
  Node* top;
public:
  myStack() {top = NULL; }
  void buildStack(); //Create stack (A
  void inWStack(); //Insert W into stack (C
  void inXStack(); //Insert X into stack (D
  void remStack(); //Remove an element from stack (E + ifEmpty check
  void remStack(char ec);
  void delStack(); //Delete entire stack (K
  void displayStack(); //Display stack when called
};

//Build Stack
void myStack:: buildStack()
{
  char c;
  for(int i=0; i<5; i++)
  {
    c = static_cast<char>(rand() % 9 + 67); //Set char between ASCII 67-75
    Node *temp = new Node(c); //Create new Node with C in it
    temp->data = c; //attach data
    temp->link = top; //attach link
    top = temp; //add to list
  }
}

//Display Stack
void myStack:: displayStack()
{
  Node *temp;

  //Could make check if empty but no need here

  temp = top;
  while(temp != NULL)
  {
    cout << temp->data;
    temp = temp->link;
    cout << " ";
  }
  cout << "\n\n";
}

//Insert W into stack
void myStack:: inWStack()
{
  Node *temp = new Node(87); //ASCII W = 87
  temp->data = 87;
  temp->link = top; //Add to top of stack
  top = temp;
}

//Insert X into stack
void myStack:: inXStack()
{
  Node *temp = new Node(88); //ASCII X = 88
  temp->data = 88;
  temp->link = top; //Add to top of stack
  top = temp;
}

//Remove from stack when no parameter is passed
void myStack:: remStack()
{
  if(top != NULL)
  {
    Node *temp = top;
    top = top ->link;
    delete temp; //Remove from top of stack
  }
  else
  {
    cout << "Error stack empty! \n";
  }
}

//Remove from stack when parameter is passed
void myStack:: remStack(char ec)
{
  //If time find for char ec
  if(top != NULL)
  {
    Node *temp = top;
    top = top ->link;
    delete temp;
  }
  else
  {
    cout << "Error stack empty! \n\n";
  }
}
//Delete stack
void myStack:: delStack()
{
  while(top != NULL)
  {
    remStack();
  }
}

//Struct for LL node for queue
struct Node2
{
  char data;
  Node2 *link;

  Node2(char n2)
  {
    this->data = n2;
    this->link = NULL;
  }
};

//Class for functions related to queue
class myQueue
{
  Node2 *top;
  Node2 *bot;
public:
  myQueue() : top(NULL), bot(NULL) {}
  void buildQueue(); //Create queue (B
  void inXQueue(); //Insert X in queue (F
  void inA2Queue(); //Insert A in 2nd position of queue (G
  void remQueue(); //Remove 1st element from queue (H
  void remQueue(char ec); //Remove char with parameter passed
  void rem4thQueue(); //Remove 4th element from queue (I
  void minMax(); //Find min and max element in queue (J
  void delQueue(); //Delete entire queue (M
  void displayQueue(); //Display queue when called
};

//Build queue
void myQueue:: buildQueue()
{
  char c;
  top = bot = new Node2(static_cast<char>(rand() % 11 + 72)); //Initialized
          // to first node for both top and bot to char between ASCII 72-83
  for(int i=0; i<4; i++)
  {
    c = static_cast<char>(rand() % 11 + 72); //Set char between ASCII 72-83
    Node2 *temp = new Node2{c};
    bot->link = temp;
    bot = temp;
  }
}

//Display queue
void myQueue:: displayQueue()
{
  Node2 *temp = top;
  while(temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->link;
  }
  cout << "\n\n";
}

//Insert X into queue
void myQueue:: inXQueue()
{
  Node2 *temp = new Node2(88); //ASCII X = 88
  temp->link = NULL; //Set end of list
  bot->link = temp;
  bot = temp;
}

//Insert A into 2nd location in queue
void myQueue:: inA2Queue()
{
  Node2 *temp = new Node2(65); //ASCII A = 65
  temp->link = NULL; //Set end of list
  temp->link = top->link; //Set linker to tops linker, or soon pos3
  top->link = temp; //set 'A' into tops linker
}

//Remove 1st in queue no parameter
void myQueue:: remQueue()
{
  if(top != NULL)
  {
    Node2 *temp = top;
    top = top ->link;
    delete temp;
  }
  else
  {
    cout << "Error queue empty! \n\n";
  }
}

//Remove from queue when parameter is passed
void myQueue:: remQueue(char ec)
{
  if(top != NULL)
  {
    Node2 *temp = top;
    top = top ->link;
    delete temp;
  }
  else
  {
    cout << "Error queue empty! \n\n";
  }
}

//Remove 4th in queue
void myQueue:: rem4thQueue()
{
  //I cant think of how to loop this one
  Node2 *temp = top->link->link->link; //Temp points to the 4th element
  top->link->link->link = temp->link; //Top->link 3x skips 3rd to 5th
  delete temp; // Delete the 4th element
}

//Find min/max based on ASCII values
void myQueue:: minMax()
{
  char minChar = top->data; //initialize to tops data
  char maxChar = top->data; //initialize to tops data

  Node2 *temp = top->link;

  while(temp != NULL)
  {
    if(minChar > temp->data)
      minChar = temp->data;
    if(maxChar < temp->data)
      maxChar = temp->data;

    //Move temp link next position
    temp = temp->link;
  }

  cout << "The min element in queue is: " << minChar << "\n"
       << "The max element in queue is: " << maxChar <<"\n\n";
}

//Delete queue
void myQueue:: delQueue()
{
  while(top != NULL)
  {
    remQueue();
  }
}

int main()
{
  srand(time(0)); //seed rand to time

  cout << "Linked List, Stack, Queue Operations\n\n";

  //Creating instance of stack and queue
  myStack s;
  myQueue q;

  char userIn;
  bool loop = true;
  while(loop)
  {
    loop = true; //reset loop condition

    //Call to a and display stack
    cout << "A) Stack : ";
    s.buildStack();
    s.displayStack();

    //Call to b and display queue
    cout << "B) Queue : ";
    q.buildQueue();
    q.displayQueue();

    //Call to c and display stack
    cout << "C) Stack : ";
    s.inWStack();
    s.displayStack();

    //Call to d and display stack
    cout << "D) Stack : ";
    s.inXStack();
    s.displayStack();

    //Call to e and display stack
    cout << "E) Stack : ";
    s.remStack();
    s.displayStack();

    //Call to F and display queue
    cout << "F) Queue : ";
    q.inXQueue();
    q.displayQueue();

    //Call to G and display queue
    cout << "G) Queue : ";
    q.inA2Queue();
    q.displayQueue();

    //Call to H and display queue
    cout << "H) Queue : ";
    q.remQueue();
    q.displayQueue();

    //Call to I and display queue
    cout << "I) Queue : ";
    q.rem4thQueue();
    q.displayQueue();

    //Call to J and display the MaxMin queue
    q.minMax();

    //Call to K and display empty stack
    cout << "K: Stack : ";
    s.delStack();
    s.displayStack();

    //Call to L Remove W From stack, error otherwise
    cout << "L: Stack : ";
    s.remStack('W');

    //Call to M and display empty
    cout << "M) Queue : ";
    q.delQueue();
    q.displayQueue();

    //Call to N Remove X from queue, error otherwise
    cout << "N) Queue : ";
    q.remQueue('X');
    q.displayQueue();

    cout << "Press X if you would like to stop program, or press any input: ";
    cin >> userIn;

    if(userIn == 'X' || userIn == 'x')
    {
      loop = false;
    }
    else
    {
      cin.clear();
      cin.ignore();
      cout << "\n";
      loop = true;
    }
  };

  cout << "\nLL / Stack & Queue Program is Implemented By: \n"
       << "Raymond Nava - October 16th, 2023\n\n";

  return 0;
}
