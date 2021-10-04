/*
Name : Tyler Felts, Ethan Cox, Drew Faust, Connor Bass
Date : 09-27/2021
Class : Algorithms

Description : Algorithms Project
Target grade : A
*/




#include <iostream>
#include <chrono>
#include <algorithm>     //the cardinal sin

#include "BubbleSort.cpp"
#include "ExchangeSort.cpp"
#include "InsertionSort.cpp"
#include "MergeSort.cpp"
#include "QuickSort.cpp"
#include "SelectionSort.cpp"
#include "Swap.cpp"
#include "Dataset.hpp"
#include "HeapSort.cpp"
#include "ReverseExchangeSort.cpp"

using namespace std;
using fpseconds = chrono::duration<double, ratio<1,1>>;   //Floating-point seconds

/*
    The amount of elements in an array that has not decayed into a pointer can be deduced 
    by dividing the size of the array (in bytes) by the size of the first element (in bytes).
*/
#define SIZE(array) sizeof(array) / sizeof(array[0])

//Simple average function
long double average(double array[], const size_t size)
{
    long double sum = 0;

    for(size_t i=0; i < size; i++)
    {
        sum += array[i];
    }
    
    return sum / size;
}

// DRIVER CODE //
int main()
{
    //Delcarations 
    Dataset<int,1000> array;         //A class wrapper around an array - added some convenience methods as well     
    const int times = 1000;         //The amount of times to test each algorithm
    double times1[times]; 

    //Timepoints for measuring times (elapsed time = end - start)
    chrono::high_resolution_clock::time_point start;
    chrono::high_resolution_clock::time_point end;

    //Prevents number being represented in scientific notation
    cout << fixed; 

    // BUBBLE SORT //
    for (int i = 0; i < times; i++)
    {
        start = chrono::high_resolution_clock::now();  //Start time

        bubbleSort<int>(array, array.length);

        end = chrono::high_resolution_clock::now();  //End time

        times1[i] = chrono::duration_cast<fpseconds>(end - start).count();

        array.genNewData();
    }

    cout << "The average time to sort an array of " << array.length << " elements using bubble sort is: " << average(times1, times) << "s over " << times << " intervals" << endl;

    // EXCHANGE SORT //
    array.genNewData();
    double times2[times];

    for (int i = 0; i < times; i++)
    {
        start = chrono::high_resolution_clock::now();  //Start time

        exchangeSort<int>(array, array.length);

        end = chrono::high_resolution_clock::now();  //End time

        times2[i] = chrono::duration_cast<fpseconds>(end - start).count();

        array.genNewData();
    }

    cout << "The average time to sort an array of " << array.length << " elements using exchange sort is: " << average(times2, times) << "s over " << times << " intervals" << endl;


    // HEAP SORT //
    array.genNewData();
    double times3[times];

    for (int i = 0; i < times; i++)
    {
        start = chrono::high_resolution_clock::now();  //Start time

        heapSort<int>(array, array.length);

        end = chrono::high_resolution_clock::now();  //End time

        times3[i] = chrono::duration_cast<fpseconds>(end - start).count();

        array.genNewData();
    }

    cout << "The average time to sort an array of " << array.length  << " elements using heap sort is: " << average(times3, times) << "s over " << times << " intervals" << endl;



    // INSERTION SORT //
    array.genNewData();
    double times4[times];

    for (int i = 0; i < array.length; i++)
    {
        start = chrono::high_resolution_clock::now();  //Start time

        insertionSort<int>(array, array.length);

        end = chrono::high_resolution_clock::now();  //End time

        times4[i] = chrono::duration_cast<fpseconds>(end - start).count();

        array.genNewData();
    }

    cout << "The average time to sort an array of " << array.length << " elements using insertion sort is: " << average(times4, times) << "s over " << times << " intervals" << endl;

}                                                               
