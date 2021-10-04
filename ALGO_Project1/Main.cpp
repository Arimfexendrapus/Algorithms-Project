/*
Name : Tyler Felts, Ethan Cox, Drew Faust, Connor Bass
Date : 09-27/2021
Class : Algorithms

Description : Algorithms Project
Target grade : A
*/

#include <iostream>
#include <chrono>
#include <algorithm>     //the cardinal sin in an algorithms class (sorry lol)

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

//Simple averaging function
long double avg(double total, const size_t size)
{
    return total / size;
}

//Struct for saving algorithm results
struct AlgoResults
{
    //Total time taken for each algorithm (over all {const int times} times)
    double random       = 0;
    double sorted       = 0;
    double reversed     = 0;
    double fewUnique    = 0;
    double nearlySorted = 0;
};



// DRIVER CODE //
int main()
{
    //Delcarations 
    Dataset<int,1000> array;         //A class wrapper around an array - added some convenience methods as well     
    const int times = 1000;         //The amount of times to test each algorithm

    //Timepoints for measuring times (elapsed time = end - start)
    chrono::high_resolution_clock::time_point start;
    chrono::high_resolution_clock::time_point end;

    //Prevents number being represented in scientific notation
    cout << fixed; 

    // BUBBLE SORT //
    AlgoResults bubbleRes;

    for (int i = 0; i < times; i++)
    {
        start = chrono::high_resolution_clock::now();  //Start time

        bubbleSort<int>(array, array.length);

        end = chrono::high_resolution_clock::now();  //End time

        bubbleRes.random += chrono::duration_cast<fpseconds>(end - start).count();

        array.genNewData();
    }

    cout << "The average time to sort an array of " << array.length << " elements using bubble sort is: " << avg(bubbleRes.random, times) << "s over " << times << " intervals" << endl;

    // EXCHANGE SORT //
    array.genNewData();
    AlgoResults exchangeRes;

    for (int i = 0; i < times; i++)
    {
        start = chrono::high_resolution_clock::now();  //Start time

        exchangeSort<int>(array, array.length);

        end = chrono::high_resolution_clock::now();  //End time

        exchangeRes.random += chrono::duration_cast<fpseconds>(end - start).count();

        array.genNewData();
    }

    cout << "The average time to sort an array of " << array.length << " elements using exchange sort is: " << avg(exchangeRes.random, times) << "s over " << times << " intervals" << endl;


    // HEAP SORT //
    array.genNewData();
    AlgoResults heapRes;

    for (int i = 0; i < times; i++)
    {
        start = chrono::high_resolution_clock::now();  //Start time

        heapSort<int>(array, array.length);

        end = chrono::high_resolution_clock::now();  //End time

        heapRes.random += chrono::duration_cast<fpseconds>(end - start).count();

        array.genNewData();
    }

    cout << "The average time to sort an array of " << array.length  << " elements using heap sort is: " << avg(heapRes.random, times) << "s over " << times << " intervals" << endl;



    // INSERTION SORT //
    array.genNewData();
    AlgoResults insertionRes;

    for (int i = 0; i < array.length; i++)
    {
        start = chrono::high_resolution_clock::now();  //Start time

        insertionSort<int>(array, array.length);

        end = chrono::high_resolution_clock::now();  //End time

        insertionRes.random += chrono::duration_cast<fpseconds>(end - start).count();

        array.genNewData();
    }

    cout << "The average time to sort an array of " << array.length << " elements using insertion sort is: " << avg(insertionRes.random, times) << "s over " << times << " intervals" << endl;

    return 0;
}          

