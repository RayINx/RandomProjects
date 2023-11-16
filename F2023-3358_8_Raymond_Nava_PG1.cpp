// Author: Raymond Nava
// Serial Number /s: 38
// Due Date:
// Programming Assignment Number 1
// Fall 2023 - CS 3358 - 008
// Instructor: Husain Gholoom
//
// Create 2 arrays of size 3x3. Populate them both with random numbers
// between 1 and 15. Add and multiply the elements of array_1 and array_2.
// Display transpose of array_1. Display sum of elements in rows, in columns,
// and diagonally. Lastly determine if array_1 is special.

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// Function declarations
void populateArray(int arr[][3], int row, int col);
void displayArray(int arr[][3], int row, int col);
void sumArray(int arr1[][3], int arr2[][3], int arr3[][3], int row, int col);
void multArray(int arr1[][3], int arr2[][3], int arr4[][3], int row, int col);
void tposedArray(int arr1[][3], int row, int col);
void sumRow(int arr1[][3], int row, int col);
void sumColumn(int arr1[][3], int row, int col);
void sumDiag(int arr1[][3], int row, int col);
bool specialArray(int arr1[][3], int sN, int row, int col);

int main()
{
  srand(time(0)); // Seeding rand with time
  const int SIZE_ROW = 3; // Quick adjust of array row size
  const int SIZE_COLUMN = 3; // Quick adjust of array column size

  int arr_1[SIZE_ROW][SIZE_COLUMN]; // Declaring arr_1 by const int
  int arr_2[SIZE_ROW][SIZE_COLUMN]; // Declaring arr_2 by const int
  int arr_3[SIZE_ROW][SIZE_COLUMN]; // Declare 3rd array for sum
  int arr_4[SIZE_ROW][SIZE_COLUMN]; // Declare 4th array for mult

  int n = SIZE_ROW; //Taking a guess that this is what determines special num
  int specNum = (n*(n*n+1))/2; // Equation for finding special number

  cout << "Welcome to my Array Program. The Function of this program is to :"
       << "\n\n"
       << "1. Create two Arrays (Array_1, Array_2) of size 3x3, each.\n"
       << "2. Populate both Arrays with distinct random numbers that are "
       << "between 1 and 15. Display both Arrays.\n"
       << "3. Adding and multiplying Array_1 and Array_2.\n"
       << "4. Displaying the transposed of Array_1.\n"
       << "5. Displaying the sum of elements of each row of Array_1, \n"
       << " displaying the sum of elements of each column of Array_1, \n"
       << " displaying the sum of both diagonal elements of Array_1.\n"
       << "6. Finally, determing whether or not Array_1 is special array.\n\n";

  populateArray(arr_1, SIZE_ROW, SIZE_COLUMN);
  populateArray(arr_2, SIZE_ROW, SIZE_COLUMN);

  cout << "Array_1 : \n\n";
  displayArray(arr_1, SIZE_ROW, SIZE_COLUMN);
  cout << "\nArray_2 : \n\n";
  displayArray(arr_2, SIZE_ROW, SIZE_COLUMN);

  cout << "\nSum of Array 1 and Array 2 \n\n";
  sumArray(arr_1, arr_2, arr_3, SIZE_ROW, SIZE_COLUMN);
  displayArray(arr_3, SIZE_ROW, SIZE_COLUMN);


  cout << "\nProduct of Array 1 and Array 2 \n\n";
  multArray(arr_1, arr_2, arr_4, SIZE_ROW, SIZE_COLUMN);
  displayArray(arr_4, SIZE_ROW, SIZE_COLUMN);

  cout << "\nTranspose of Array 1 \n\n";
  tposedArray(arr_1, SIZE_ROW, SIZE_COLUMN);

  cout << "\n\n";
  sumRow(arr_1, SIZE_ROW, SIZE_COLUMN);

  cout << "\n\n";
  sumColumn(arr_1, SIZE_ROW, SIZE_COLUMN);

  cout << "\n\n";
  sumDiag(arr_1, SIZE_ROW, SIZE_COLUMN);


  cout << "\nSpecial Number is " << specNum << "\n";

  if(specialArray(arr_1, specNum, SIZE_ROW, SIZE_COLUMN) == true) //Calling specialArray and checking it
    cout << "Array 1 is a special array";
  else
    cout << "Array 1 is not a special array";

  return 0;
}

// Takes input of array and populates it with rand
void populateArray(int arr[][3], int row, int col)
{
  for(int r=0; r<row; r++) // Loop through row
  {
    for(int c=0; c<col; c++) // Per row, loop through column
    {
      arr[r][c] = rand() % 15 + 1; // Set random number between 15 and 1
    }
  }
}

// Takes array from main and displays it
void displayArray(int arr[][3], int row, int col)
{
  for(int r=0; r<row; r++) // Loop row
  {
    for(int c=0; c<col; c++) // Loop column
    {
      cout << arr[r][c] << "  "; // Display array
    }
    cout << "\n";
  }
}


// Takes input of both array_1 and array_2 and adds them into array_3
void sumArray(int arr1[][3], int arr2[][3], int arr3[][3], int row, int col)
{
  for(int r=0; r<row; r++)
  {
    for(int c=0; c<col; c++)
    {
      arr3[r][c] = arr1[r][c] + arr2[r][c]; // Add arr1 and arr2 into arr3
    }
  }
}

// Takes input of both array_1 and array_2 and multiplies them into array_4
void multArray(int arr1[][3], int arr2[][3], int arr4[][3], int row, int col)
{
  for(int r=0; r<row; r++)
  {
    for(int c=0; c<col; c++)
    {
      arr4[r][c] = arr1[r][c] * arr2[r][c]; // Multiply arr1 and arr2 into arr4
    }
  }
}

// Reverses displaying of array 1 to make transposed
void tposedArray(int arr1[][3], int row, int col)
{
  for(int c=0; c<col; c++) // Loop col first
  {
    for(int r=0; r<row; r++) // Loop row second
    {
      cout << arr1[r][c] << "  "; // Display array as normal
    }
    cout << "\n";
  }
}


// Finds the sum of row in array 1
void sumRow(int arr1[][3], int row, int col)
{
  for(int r=0; r<row; r++) // Loop row
  {
    int sumR = 0; // Erase sumR per row loop
    for(int c=0; c<col; c++) // Loop column
    {
      sumR += arr1[r][c]; // Add sum by row[r] c1+c2+c3...
    }
    cout << "\nThe sum of numbers in Row #" << r+1 << " in Array 1 = " << sumR;
  }
}

// Finds the sum of columns in array 1
void sumColumn(int arr1[][3], int row, int col)
{
  for(int c=0; c<col; c++) // Loop col first
  {
    int sumC = 0;
    for(int r=0; r<row; r++) // Loop row second
    {
      sumC += arr1[r][c]; // Add sum of cul[c] r1+r2+r3...
    }
    cout << "\nThe sum of numbers in Column #" << c+1 << " in Array 1 = "
         << sumC;
  }
}

// Finds sum of diagonal in array 1
void sumDiag(int arr1[][3], int row, int col)
{
  int diag1 = 0;
  int diag2 = 0;

  int c = 0; // Track column
  int c2 = col-1; // Track column from the back, -1 because arrays are 0-n

  for(int r=0; r<row; r++) // Loop row
  {
    diag1 += arr1[r][c];
    c++;
    diag2 += arr1[r][c2];
    c2--;
  }
  cout << "\nThe sum of the first diagonal in Array 1 = " << diag1;
  cout << "\nThe sum of the second diagonal in Arary 2 = " << diag2;
}

bool specialArray(int arr1[][3], int sN, int row, int col)
{
  int specNumCheck; // Temp used to compare against sN(special number)

  for(int r=0; r<row; r++) // Loop row, checking if row is specialNum
  {
    int specNumCheck = 0; // Erase specNumCheck per row loop
    for(int c=0; c<col; c++) // Loop column
    {
      specNumCheck += arr1[r][c]; // Add sum by row[r]
    }
    if(specNumCheck != sN) // If row check is not special number, exit return false
    {
      return false;
    }
  }

  for(int c=0; c<col; c++) // Loop col first, checking if col is special num
  {
    int specNumCheck = 0; // Erase specNumCheck per col loop
    for(int r=0; r<row; r++) // Loop row second
    {
      specNumCheck += arr1[r][c]; // Add sum of col[c]
    }
    if(specNumCheck != sN) // If row check is not special number, exit return false
    {
      return false;
    }
  }

  int diag1 = 0, diag2 = 0; // Save to compare diag numbers
  int c = 0; // Track column
  int c2 = col-1; // Track column from the back, -1 because arrays are 0-n

  for(int r=0; r<row; r++) // Loop row
  {
    diag1 += arr1[r][c];
    c++;
    diag2 += arr1[r][c2];
    c2--;
  }

  if(diag1 != sN)
    return false;
  if(diag2 != sN)
    return false;

  return true;
}
