// This program uses the bubble sort algorithm to sort an
// array in ascending order.
#include <iostream>
using namespace std;

// Function prototypes
void bubbleSort(int [], int);
void showArray(const int [], int);

int main()
{
   // Array of unsorted values
   int values[6] = {7, 2, 3, 8, 9, 1};

   // Display the values.
   cout << "The unsorted values are:\n";
   showArray(values, 6);

   // Sort the values.
   bubbleSort(values, 6);

   // Display them again.
   cout << "The sorted values are:\n";
   showArray(values, 6);
   return 0;
}

//***********************************************************
// Definition of function bubbleSort                         *
// This function performs an ascending order bubble sort on *
// array. size is the number of elements in the array.     *
//***********************************************************

void bubbleSort(int array[], int size)
{
   bool swap;
   int temp;

   do
   {
      swap = false;
      for (int i = 0; i < (size - 1); i++)
      {
         if (array[i] > array[i + 1])
         {
            temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
            swap = true;
         }
      }
   } while (swap);
}

//*************************************************************
// Definition of function showArray.                          *
// This function displays the contents of array. size is the *
// number of elements.                                        *
//*************************************************************

void showArray(const int array[], int size)
{
   for (int j = 0; j < size; j++)
      cout << array[j] << " ";
   cout << endl;
}