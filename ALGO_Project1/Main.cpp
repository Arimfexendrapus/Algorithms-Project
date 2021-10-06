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

//Algorithm Implementations (all the sorts!)
#include "SelectionSort.cpp"
#include "ExchangeSort.cpp"
#include "BubbleSort.cpp"
#include "InsertionSort.cpp"
#include "MergeSort.cpp"
#include "QuickSort.cpp"
#include "HeapSort.cpp"

//Supporting files
#include "Dataset.hpp"    //'Dataset' class is a wrapper around an array with randomly generated data
#include "Swap.cpp"      //Swapping function

using fpsecond = chrono::duration<double, ratio<1,1>>;   //Floating-point seconds, up to ~15 decimal places
using namespace std;                                    //Standard namespace, no external libraries

//Struct for saving algorithm results
struct AlgoResults
{
    //Total time taken for each algorithm (over all {const int times} times)
    double random    = 0;
    double reverse   = 0;
    double fewUnique = 0;
    double nearly    = 0;
};

//Averaging function -- sets the results of each algorithm to the average time by dividing by the amount of times
void avg(AlgoResults& totals, const size_t size)
{
    totals.random     /= size;
    totals.reverse    /= size;
    totals.fewUnique  /= size;
    totals.nearly     /= size;
}



// DRIVER CODE //
int main()
{
    //Constants
    const unsigned int arrlen = 1000;       //The amount of elements in each array
    const unsigned int times  = 1000;      //The amount of times to test each algorithm

    //Datasets
    Dataset<int, arrlen, RANDOM>         randomArr;             //An array of {arrlen} elements, randomly distributed    
    Dataset<int, arrlen, REVERSE_SORTED> reverseSortedArr;     //An array of {arrlen} elements, sorted in reverse order (ex. 1000 -> 0, with repeats)
    Dataset<int, arrlen, NEARLY_SORTED>  nearlySortedArr;     //An array of {arrlen} elements, almost sorted (~10% unsorted)
    Dataset<int, arrlen, FEW_UNIQUE>     fewUniqueArr;       //An array of {arrlen} elements, composed of a few unique values (somewhere between 6-12)

    //Timepoints for measuring times (elapsed time = end - start)
    chrono::high_resolution_clock::time_point start;
    chrono::high_resolution_clock::time_point end;

    //Prevents number being represented in scientific notation
    cout << fixed << setprecision(8);   //Use 8 decimal places



    // SELECTION SORT //
    AlgoResults selectionRes;
                                                                                    
    for (int i=0; i < times; i++)
    {
        //Random
        start = chrono::high_resolution_clock::now();                                     //Start time
        selectionSort<int>(randomArr, randomArr.length);                                 //Call algorithm
        end = chrono::high_resolution_clock::now();                                     //End time
        selectionRes.random += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Reverse sorted
        start = chrono::high_resolution_clock::now();                                      //Start time
        selectionSort<int>(reverseSortedArr, reverseSortedArr.length);                    //Call algorithm
        end = chrono::high_resolution_clock::now();                                      //End time
        selectionRes.reverse += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Nearly sorted
        start = chrono::high_resolution_clock::now();                                     //Start time
        selectionSort<int>(nearlySortedArr, nearlySortedArr.length);                     //Call algorithm
        end = chrono::high_resolution_clock::now();                                     //End time
        selectionRes.nearly += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Few unique
        start = chrono::high_resolution_clock::now();                                       //Start time
        selectionSort<int>(fewUniqueArr, fewUniqueArr.length);                             //Call algorithm
        end = chrono::high_resolution_clock::now();                                       //End time
        selectionRes.fewUnique += chrono::duration_cast<fpsecond>(end - start).count();  //Get elapsed time

        //Generate new data
        randomArr.genNewData();
        reverseSortedArr.genNewData();
        nearlySortedArr.genNewData();
        fewUniqueArr.genNewData();
    }


    // EXCHANGE SORT //
    AlgoResults exchangeRes;

    for (int i=0; i < times; i++)
    {
        //Random
        start = chrono::high_resolution_clock::now();                                    //Start time
        exchangeSort<int>(randomArr, randomArr.length);                                 //Call algorithm
        end = chrono::high_resolution_clock::now();                                    //End time
        exchangeRes.random += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Reverse sorted
        start = chrono::high_resolution_clock::now();                                     //Start time
        exchangeSort<int>(reverseSortedArr, reverseSortedArr.length);                    //Call algorithm
        end = chrono::high_resolution_clock::now();                                     //End time
        exchangeRes.reverse += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Nearly sorted
        start = chrono::high_resolution_clock::now();                                    //Start time
        exchangeSort<int>(nearlySortedArr, nearlySortedArr.length);                     //Call algorithm
        end = chrono::high_resolution_clock::now();                                    //End time
        exchangeRes.nearly += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Few unique
        start = chrono::high_resolution_clock::now();                                      //Start time
        exchangeSort<int>(fewUniqueArr, fewUniqueArr.length);                             //Call algorithm
        end = chrono::high_resolution_clock::now();                                      //End time
        exchangeRes.fewUnique += chrono::duration_cast<fpsecond>(end - start).count();  //Get elapsed time

        //Generate new data
        randomArr.genNewData();
        reverseSortedArr.genNewData();
        nearlySortedArr.genNewData();
        fewUniqueArr.genNewData();
    }


    // BUBBLE SORT //
    AlgoResults bubbleRes;

    for (int i=0; i < times; i++)
    {
        //Random data
        start = chrono::high_resolution_clock::now();                                     //Start time
        bubbleSort<int>(randomArr, randomArr.length);                                    //Call algorithm
        end = chrono::high_resolution_clock::now();                                     //End time
        bubbleRes.random += chrono::duration_cast<fpsecond>(end - start).count();      //Get elapsed time

        //Reverse sorted
        start = chrono::high_resolution_clock::now();                                     //Start time
        bubbleSort<int>(reverseSortedArr, reverseSortedArr.length);                      //Call algorithm
        end = chrono::high_resolution_clock::now();                                     //End time
        bubbleRes.reverse += chrono::duration_cast<fpsecond>(end - start).count();     //Get elapsed time

        //Nearly sorted
        start = chrono::high_resolution_clock::now();                                     //Start time
        bubbleSort<int>(nearlySortedArr, nearlySortedArr.length);                        //Call algorithm
        end = chrono::high_resolution_clock::now();                                     //End time
        bubbleRes.nearly += chrono::duration_cast<fpsecond>(end - start).count();      //Get elapsed time

        //Few unique
        start = chrono::high_resolution_clock::now();                                     //Start time
        bubbleSort<int>(fewUniqueArr, fewUniqueArr.length);                              //Call algorithm
        end = chrono::high_resolution_clock::now();                                     //End time
        bubbleRes.fewUnique += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Generate new data
        randomArr.genNewData();
        reverseSortedArr.genNewData();
        nearlySortedArr.genNewData();
        fewUniqueArr.genNewData();
    }


    // INSERTION SORT //
    AlgoResults insertionRes;

    for (int i=0; i < times; i++)
    {
        //Random
        start = chrono::high_resolution_clock::now();                                     //Start time
        insertionSort<int>(randomArr, randomArr.length);                                 //Call algorithm
        end = chrono::high_resolution_clock::now();                                     //End time
        insertionRes.random += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Reverse sorted
        start = chrono::high_resolution_clock::now();                                      //Start time
        insertionSort<int>(reverseSortedArr, reverseSortedArr.length);                    //Call algorithm
        end = chrono::high_resolution_clock::now();                                      //End time
        insertionRes.reverse += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Nearly sorted 
        start = chrono::high_resolution_clock::now();                                     //Start time
        insertionSort<int>(nearlySortedArr, nearlySortedArr.length);                     //Call algorithm
        end = chrono::high_resolution_clock::now();                                     //End time
        insertionRes.nearly += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Few unique
        start = chrono::high_resolution_clock::now();                                        //Start time
        insertionSort<int>(fewUniqueArr, fewUniqueArr.length);                              //Call algorithm
        end = chrono::high_resolution_clock::now();                                        //End time
        insertionRes.fewUnique += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Generate new data
        randomArr.genNewData();
        reverseSortedArr.genNewData();
        nearlySortedArr.genNewData();
        fewUniqueArr.genNewData();
    }
           

    // MERGE SORT //
    AlgoResults mergeRes;

    for (int i=0; i < times; i++)
    {
        //Random 
        start = chrono::high_resolution_clock::now();                                 //Start time
        mergeSort<int>(randomArr, 0, randomArr.length-1);                            //Call algorithm
        end = chrono::high_resolution_clock::now();                                 //End time
        mergeRes.random += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Reverse sorted
        start = chrono::high_resolution_clock::now();                                  //Start time
        mergeSort<int>(reverseSortedArr, 0, reverseSortedArr.length-1);               //Call algorithm
        end = chrono::high_resolution_clock::now();                                  //End time
        mergeRes.reverse += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Nearly sorted
        start = chrono::high_resolution_clock::now();                                 //Start time
        mergeSort<int>(nearlySortedArr, 0, nearlySortedArr.length-1);                //Call algorithm
        end = chrono::high_resolution_clock::now();                                 //End time
        mergeRes.nearly += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Few unique
        start = chrono::high_resolution_clock::now();                                    //Start time
        mergeSort<int>(fewUniqueArr, 0, fewUniqueArr.length-1);                         //Call algorithm
        end = chrono::high_resolution_clock::now();                                    //End time
        mergeRes.fewUnique += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Generate new data
        randomArr.genNewData();
        reverseSortedArr.genNewData();
        nearlySortedArr.genNewData();
        fewUniqueArr.genNewData();
    }


    // QUICK SORT //
    AlgoResults quickRes;

    for (int i=0; i < times; i++)
    {
        //Random 
        start = chrono::high_resolution_clock::now();                                 //Start time
        quickSort<int>(randomArr, 0, randomArr.length-1);                            //Call algorithm
        end = chrono::high_resolution_clock::now();                                 //End time
        quickRes.random += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        /*
        //Reverse sorted
        start = chrono::high_resolution_clock::now();                                  //Start time
        quickSort<int>(reverseSortedArr, 0, reverseSortedArr.length-1);               //Call algorithm
        end = chrono::high_resolution_clock::now();                                  //End time
        quickRes.reverse += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Nearly sorted
        start = chrono::high_resolution_clock::now();                                 //Start time
        quickSort<int>(nearlySortedArr, 0, nearlySortedArr.length-1);                //Call algorithm
        end = chrono::high_resolution_clock::now();                                 //End time
        quickRes.nearly += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Few unique
        start = chrono::high_resolution_clock::now();                                    //Start time
        quickSort<int>(fewUniqueArr, 0, fewUniqueArr.length-1);                         //Call algorithm
        end = chrono::high_resolution_clock::now();                                    //End time
        quickRes.fewUnique += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Generate new data
        randomArr.genNewData();
        reverseSortedArr.genNewData();
        nearlySortedArr.genNewData();
        fewUniqueArr.genNewData();
        */
    }


    // HEAP SORT //
    AlgoResults heapRes;

    for (int i=0; i < times; i++)
    {
        //Random 
        start = chrono::high_resolution_clock::now();                                //Start time
        heapSort<int>(randomArr, randomArr.length);                                 //Call algorithm
        end = chrono::high_resolution_clock::now();                                //End time              
        heapRes.random += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Reverse sorted
        start = chrono::high_resolution_clock::now();                                 //Start time
        heapSort<int>(reverseSortedArr, reverseSortedArr.length);                    //Call algorithm
        end = chrono::high_resolution_clock::now();                                 //End time
        heapRes.reverse += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Nearly sorted
        start = chrono::high_resolution_clock::now();                                //Start time
        heapSort<int>(nearlySortedArr, nearlySortedArr.length);                     //Call algorithm
        end = chrono::high_resolution_clock::now();                                //End time
        heapRes.nearly += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Few unique
        start = chrono::high_resolution_clock::now();                                   //Start time
        heapSort<int>(fewUniqueArr, fewUniqueArr.length);                              //Call algorithm
        end = chrono::high_resolution_clock::now();                                   //End time
        heapRes.fewUnique += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Generate new data
        randomArr.genNewData();
        reverseSortedArr.genNewData();
        nearlySortedArr.genNewData();
        fewUniqueArr.genNewData();
    }




    // CALCULATIONS //
    avg(selectionRes, times);
    avg(exchangeRes, times);
    avg(bubbleRes, times);
    avg(insertionRes, times);
    avg(mergeRes, times);
    avg(quickRes, times);
    avg(heapRes, times);



    // RESULTS //
    const unsigned int w = 17;  //w(idth)

    //Headers
    cout << "Length of Arrays: " << arrlen << '\n';
    cout << "Number of Trials: " << times << "\n\n";

    cout << "Algorithm:" << setw(w) << "Random " << setw(w) << "Reverse Sorted " << setw(w) << "Nearly Sorted " << setw(w) << "Few Unique\n";
    cout << "==============\n";

    //Average times of each algorithm for each dataset
    /*          Algorithm                        Random Dataset                  Reverse Sorted Dataset              Nearly Sorted Dataset                 Few Unique Dataset        */
    cout << "Selection Sort: "  << setw(20) << selectionRes.random << setw(20) << selectionRes.reverse << setw(20) << selectionRes.nearly << setw(20) << selectionRes.fewUnique << '\n';
    cout << "Exchange Sort: "   << setw(20) << exchangeRes.random  << setw(20) << exchangeRes.reverse  << setw(20) << exchangeRes.nearly  << setw(20) << exchangeRes.fewUnique << '\n';
    cout << "Bubble Sort: "     << setw(20) << bubbleRes.random    << setw(20) << bubbleRes.reverse    << setw(20) << bubbleRes.nearly    << setw(20) << bubbleRes.fewUnique << '\n';
    cout << "Insertion Sort: "  << setw(20) << insertionRes.random << setw(20) << insertionRes.reverse << setw(20) << insertionRes.nearly << setw(20) << insertionRes.fewUnique << '\n';
    cout << "Merge Sort: "      << setw(20) << mergeRes.random     << setw(20) << mergeRes.reverse     << setw(20) << mergeRes.nearly     << setw(20) << mergeRes.fewUnique << '\n';
    cout << "Quick Sort: "      << setw(20) << quickRes.random     << setw(20) << quickRes.reverse     << setw(20) << quickRes.nearly     << setw(20) << quickRes.fewUnique << '\n';
    cout << "Heap Sort: "       << setw(20) << heapRes.random      << setw(20) << heapRes.reverse      << setw(20) << heapRes.nearly      << setw(20) << heapRes.fewUnique << '\n';
    
    return 0;
}          

