// This program uses the selection sort algorithm to sort an
// array in ascending order.
// The SelectionSort function has been modified to use the code in
//   the Unit 2 slides.

#include <iostream>
using namespace std;

// Function prototypes
int findIndexOfMin (int [], int, int);
void selectionSort(int [], int);
void showArray(int [], int);

int main()
{
   // Define an array with unsorted values
   const int SIZE = 6;
   int values[SIZE] = {5, 7, 2, 8, 9, 1};

   // Display the values.
   cout << "The unsorted values are\n";
   showArray(values, SIZE);
   
   // Sort the values.
   selectionSort(values, SIZE);
   
   // Display the values again.
   cout << "The sorted values are\n";
   showArray(values, SIZE);
   return 0;
}

//**************************************************************
// Definition of function findIndexOfMin.                      *
// This function returns the index of the smallest element in  *
// the array, starting from position start.                    *
//**************************************************************

int findIndexOfMin (int array[], int size, int start) {
    int minIndex = start;
    for (int i = start+1; i < size; i++) {
        if (array[i] < array[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

//**************************************************************
// Definition of function selectionSort.                       *
// This function performs an ascending order selection sort on *
// array. size is the number of elements in the array.         *
//**************************************************************

void selectionSort(int array[], int size)
{
    int temp;
    int minIndex;
    for (int index = 0; index < (size -1); index++) {
        minIndex = findIndexOfMin(array, size, index);
        //swap
        temp = array[minIndex];
        array[minIndex] = array[index];
        array[index] = temp;
    }

}

//**************************************************************
// Definition of function showArray.                           *
// This function displays the contents of array. size is the   *
// number of elements.                                         *
//**************************************************************

void showArray(int array[], int size)
{
   for (int count = 0; count < size; count++)
      cout << array[count] << " ";
   cout << endl;
} 
