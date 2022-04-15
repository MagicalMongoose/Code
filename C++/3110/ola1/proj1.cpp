/*
Name: Drew Lickman
Course: CSCI 3110-001
Project: #1
Due: 1/25/22
*/

#include <iostream>
#include <fstream>
using namespace std;

//dynamically double the size of the array
int * doubleArray(int * arrayOfInts, int * arraySize)
{
    //dynamically allocate memory for an array
    //copies elements from old array to new
    //deallocates memory of old array
    //returns a pointer to newly allocated array
    *arraySize = *arraySize * 2;
    int * doubledArray = new int[*arraySize];
    for(int k = 0; k < *arraySize/2; k++)
    {
        doubledArray[k] = arrayOfInts[k];
    }
    delete [] arrayOfInts;  
    arrayOfInts = nullptr;
    return doubledArray;
}

//calculate the average of the numbers so far
double calcAvg(int * arrayOfInts, int intsRead)
{
    double average = 0;
    double sum = 0;
    for(int j = 0; j < intsRead; j++)
    {
        sum += arrayOfInts[j];
    }
    average = sum / intsRead;
    return average;
}

int main()
{
    //read "nums.txt"
    //output to "p1out.txt"
    ifstream nums;
    ofstream output;
    nums.open("nums.txt");
    output.open("p1out.txt");

    //new array of 200 elements
    int arrSize = 200; //hardcoded
    int * arrSizePtr = &arrSize;
    int * arr = new int[arrSize];

    //read input file 
    int i = 0;
    double avg;
    int input;
    while(nums >> input)
    {
        
        arr[i] = input;
        //cout << i << " / " << arrSize << " (" << arr[i] << ")" << endl;
        i++;
        
        if(i == *arrSizePtr || nums.eof())
        {
            //if at array capacity call calcAvg() and print 
                //(to console and output file) the count of elements
                //and the average of integers as a double
                //and call doubleArray() to double size of the array until finished
            //output to console and output file the size of array, the number of integers read, and average of those ints
            cout << arrSize << " ";
            output << arrSize << " ";
            avg = calcAvg(arr, i);
            cout << avg << endl;
            output << avg << endl;
            arr = doubleArray(arr, arrSizePtr);
        }
    }
    //output on the last number
    cout << arrSize << " ";
    output << arrSize << " ";
    cout << i << " ";    
    output << i << " ";
    avg = calcAvg(arr, i);
    cout << avg << endl;
    output << avg << endl;

    nums.close();
    output.close();
    delete [] arr;
    arr = nullptr;
    return 0;
}