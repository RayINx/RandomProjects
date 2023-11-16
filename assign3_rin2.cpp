// assign3_rin2
// Raymond Nava
// 
// Started 2/28/2020
// Assignment 3
// CS 2308.255 Jill Seaman

#include <iostream>
using namespace std;

int leftCircularShift(int *);
int sort2withSum();
int resize();
int concatenate();
int subArray();
int duplicateArray();

//*****************************************************************************
// Function for problem 1
int leftCircularShift(int *arr, int size)
{
    int PH = *(arr + 0); // Place Holder to set last variable as first
    for(int i = 0; i < size; i++)
    {
        *(arr + i) = *(arr + (i + 1));
    }
    *(arr + size) = PH; // Switch last variable after everything is over
    
    return *(arr + 1);
}

//*****************************************************************************
// Fucntion for problem 2
int sort2withSum (int *x, int *y) 
{
    if (*x > *y) 
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    return *x + *y;
}

//*****************************************************************************
// Function for Problem 3
int *resize(int *arr, int size)
{

    int size2 = (size + 1) * 2;
    int *newArr = new int[size2];
    for(int i = 0; i < size2; i++)
    {
        *(newArr + i) = *(arr + i);
    }
    for(int i = size; i < size2; i++)
    {
        *(newArr + (i + 1)) = - 1;
    }

    return newArr;
}

//*****************************************************************************
// Function for Problem 4
int *concatenate(int *arr, int size, int *arr2, int size2)
{
    int bigSize = size + size2 + 1; //Find the max size of 2 arrays
    int *bigArr = new int[15]; //Allocating memory for new array

    for(int i = 0; i <= size; i++) //Putting the 1st array into big array
    {
        *(bigArr + i) = *(arr + i);
    }
    for(int j = size + 1; j < 15; j++) //Putting 2nd array into big array
    {
        *(bigArr + j) = *(arr2 + j - size - 1);
    }

    return bigArr;

}

//*****************************************************************************
// Function for Problem 5
int *duplicateArray (int *arr, int size)
{
    int *newArray;
    if (size <= 0) //size must be positive
        return NULL; //NULL is 0, an invalid address

    newArray = new int [size]; //allocate new array

    for (int index = 0; index < size; index++)
        newArray[index] = arr[index]; //copy to new array

    return newArray;
}

int *subArray (int *array, int start, int length)
{
    int *result = duplicateArray(array + start, length);
    return result;
}

//*****************************************************************************
int main()
{
    int size = 9;
    int arr[size] = {0,1,2,3,4,5,6,7,8,9};
    int size2 = 4;
    int arr2[size] = {10,11,12,13,14};
    int number = 8;
    int number2 = 5;
    int sumNumber;
    int* newArray;
    int start = 5;
    int length = 4;

// This part will call the data for problem 1
    cout << "Testing data for leftCircularShift " << endl
         << "Testing array 1: "; 
             for(int i = 0; i < 10; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
    cout << "Expected Result: 1 2 3 4 5 6 7 8 9 0" << endl
         << "Actual Results:  ";
    leftCircularShift(arr, size); //Placed here to not mess with first call
        for(int i = 0; i < 10; i++)
        {
            cout << arr[i] << " ";
        }
    cout << endl << endl << endl;

//This will call the data for problem 2
    sumNumber  = sort2withSum(&number, &number2);
    cout << "Testing sort2withSum" << endl << "Test data: " << "number: " 
         << number << " number2: " << number2 << endl 
         << "Expected Result: 13" << endl << "Actual Results:  " 
         << sumNumber << endl << endl << endl;

//This will call the data for problem 3
    newArray = resize(arr, size);
    cout << "Testing data for resize " << endl
         << "Testing array 1: "; 
            for(int i = 0; i < 10; i++) //Call array
            {
                cout << arr[i] << " ";
            }
            cout << endl;
    cout << "Expected Result:  1 2 3 4 5 6 7 8 9 0" //The array is changed 
                                                    //from problem 1
         << " -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 " << endl
         << "Actual Results:  ";
        for(int i = 0; i < 20; i++)
        {
            cout << newArray[i] << " ";
        }
    cout << endl << endl << endl;
    delete [] newArray; //Making sure to delete it before next use

//This will call the data for problem 4
    newArray = concatenate(arr, size, arr2, size2);
    cout << "Testing data for concatenate " << endl
         << "Testing array 1 + 2: "; 
            for(int i = 0; i < 10; i++) //Call array 1
            {
                cout << arr[i] << " ";
            }
            for(int i = 0; i < 10; i++) //Call array 2
            {
                cout << arr2[i] << " ";
            }
            cout << endl;
    cout << "Expected Result:  1 2 3 4 5 6 7 8 9 0" //The array is changed 
                                                    //from problem 1
         << " 10 11 12 13 14 " << endl
         << "Actual Results:  ";
        for(int i = 0; i <= 15; i++) //15 is the combined number in both arrays
        {
            cout << newArray[i] << " ";
        }
    cout << endl << endl << endl;

    delete [] newArray;  //Making sure to delete

//This will call the data for problem 5
    newArray = subArray(arr, start, length);
    cout << "Testing subArray: " << endl
         << "test data: ";
            for(int i = 0; i < 10; i++) //Call array 1
            {
                cout << arr[i] << " ";
            }
    cout << endl << "Start: " << start << " " << "Length: " << length << endl
         << "Expected Result: 6 7 8 9 " << endl
         << "Actual result: ";
            for(int i = 0; i < length; i++) //Call array 1
            {
                cout << newArray[i] << " ";
            }
    cout << endl;
    delete [] newArray;
    return 0;
}