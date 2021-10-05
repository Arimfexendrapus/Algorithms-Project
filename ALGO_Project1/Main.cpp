/*
Name : Tyler Felts, Ethan Cox, Drew Faust, Connor Bass
Date : 09-27/2021
Class : Algorithms

Description : Algorithms Project
Target grade : A

Compilation Instructions: g++ Main.cpp
*/

//Native C++ Libraries
#include <iostream>
#include <iomanip>
#include <chrono>
#include <algorithm>     //the cardinal sin in an algorithms class (sorry lol)

//Algorithm Implementations
#include "ExchangeSort.cpp"
#include "SelectionSort.cpp"
#include "BubbleSort.cpp"
#include "InsertionSort.cpp"
#include "MergeSort.cpp"
#include "QuickSort.cpp"
#include "Swap.cpp"
#include "Dataset.hpp"
#include "HeapSort.cpp"
#include "ReverseExchangeSort.cpp"

using namespace std;
using fpseconds = chrono::duration<double, ratio<1,1>>;   //Floating-point seconds

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

//Averaging function -- sets the results of each algorithm to the average time by dividing by the amount of times
void avg(AlgoResults& totals, const size_t size)
{
    totals.random        /= size;
    /*
    totals.sorted        /= size;
    totals.reversed      /= size;
    totals.fewUnique     /= size;
    totals.nearlySorted  /= size;
    */
}



// DRIVER CODE //
int main()
{
    //Constants
    const unsigned int arrLength = 1000;       //The amount of elements in each array
    const unsigned int times  = 1000;         //The amount of times to test each algorithm

    //Datasets
    Dataset<int, arrLength, RANDOM>         randomArr;             //An array of {arrLength} elements, randomly distributed    
    Dataset<int, arrLength, REVERSE_SORTED> reverSortedArr;       //An array of {arrLength} elements, sorted in reverse order (ex. 1000 -> 0, with repeats)
    Dataset<int, arrLength, NEARLY_SORTED>  nearlySortedArr;     //An array of {arrLength} elements, almost sorted (~10% unsorted)
    Dataset<int, arrLength, FEW_UNIQUE>     fewUniqueArr;       //An array of {arrLength} elements, composed of a few unique values (somewhere between 6-12)

    //Timepoints for measuring times (elapsed time = end - start)
    chrono::high_resolution_clock::time_point start;
    chrono::high_resolution_clock::time_point end;

    //Prevents number being represented in scientific notation
    cout << fixed; 



    // BUBBLE SORT //
    AlgoResults bubbleRes;

    for (int i = 0; i < times; i++)
    {
        //Random data
        start = chrono::high_resolution_clock::now();    //Start time
        bubbleSort<int>(randomArr, randomArr.length);   //
        end = chrono::high_resolution_clock::now();    //End time

        bubbleRes.random += chrono::duration_cast<fpseconds>(end - start).count();



        randomArr.genNewData();
    }


    // EXCHANGE SORT //
    AlgoResults exchangeRes;

    for (int i = 0; i < times; i++)
    {
        start = chrono::high_resolution_clock::now();  //Start time

        exchangeSort<int>(randomArr, randomArr.length);

        end = chrono::high_resolution_clock::now();  //End time

        exchangeRes.random += chrono::duration_cast<fpseconds>(end - start).count();

        randomArr.genNewData();
    }



    // HEAP SORT //
    AlgoResults heapRes;

    for (int i = 0; i < times; i++)
    {
        start = chrono::high_resolution_clock::now();  //Start time

        heapSort<int>(randomArr, randomArr.length);

        end = chrono::high_resolution_clock::now();  //End time

        heapRes.random += chrono::duration_cast<fpseconds>(end - start).count();

        randomArr.genNewData();
    }


    // INSERTION SORT //
    AlgoResults insertionRes;

    for (int i = 0; i < times; i++)
    {
        start = chrono::high_resolution_clock::now();  //Start time

        insertionSort<int>(randomArr, randomArr.length);

        end = chrono::high_resolution_clock::now();  //End time

        insertionRes.random += chrono::duration_cast<fpseconds>(end - start).count();

        randomArr.genNewData();
    }



    // CALCULATIONS //
    avg(exchangeRes, times);
    avg(bubbleRes, times);
    avg(insertionRes, times);
    avg(heapRes, times);



    // RESULTS //
    const unsigned int w = 20;  //w(idth)

    //Headers
    cout << "Length of Arrays: " << arrLength << '\n';
    cout << "Number of Trials: " << times << "\n\n";

    cout << "Average Times:" << setw(w) << "Random " << setw(w) << "Reverse Sorted " << setw(w) << "Nearly Sorted " << setw(w) << "Few Unique\n";
    cout << "==============\n";

    //Average times of each algorithm for each dataset
    cout << "Exchange Sort: "  << setw(20) << exchangeRes.random  << '\n';
    cout << "Bubble Sort: "    << setw(20) << bubbleRes.random    << '\n';
    cout << "Insertion Sort: " << setw(20) << insertionRes.random << '\n';
    cout << "Heap Sort: "      << setw(20) << heapRes.random      << '\n';

    return 0;
}          

