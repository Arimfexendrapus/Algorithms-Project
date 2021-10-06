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
    const unsigned int arrlen = 100;       //The amount of elements in each array
    const unsigned int times  = 100;      //The amount of times to test each algorithm

    //Datasets
    Dataset<int, arrlen, RANDOM>         randomArr;             //An array of {arrlen} elements, randomly distributed    
    Dataset<int, arrlen, REVERSE_SORTED> reverseSortedArr;     //An array of {arrlen} elements, sorted in reverse order (ex. 1000 -> 0, with repeats)
    Dataset<int, arrlen, NEARLY_SORTED>  nearlySortedArr;     //An array of {arrlen} elements, almost sorted (~10% unsorted)
    Dataset<int, arrlen, FEW_UNIQUE>     fewUniqueArr;       //An array of {arrlen} elements, composed of a few unique values (somewhere between 6-12)

    //Timepoints for measuring times (elapsed time = end - start)
    chrono::high_resolution_clock::time_point start;
    chrono::high_resolution_clock::time_point end;

    //Prevents number being represented in scientific notation
    cout << fixed << setprecision(8)<<right;   //Use 8 decimal places



    // SELECTION SORT //
    AlgoResults selectionRes;
    AlgoResults selectionSwaps;
    AlgoResults selectionCompares;
                                                                                    
    for (int i=0; i < times; i++)
    {
        //Random
        start = chrono::high_resolution_clock::now();                                     //Start time
        selectionCompares.random += selectionSort<int>(randomArr, randomArr.length,selectionSwaps.random);                                 //Call algorithm
        end = chrono::high_resolution_clock::now();                                     //End time
        selectionRes.random += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Reverse sorted
        start = chrono::high_resolution_clock::now();                                      //Start time
        selectionCompares.reverse += selectionSort<int>(reverseSortedArr, reverseSortedArr.length, selectionSwaps.reverse);                    //Call algorithm
        end = chrono::high_resolution_clock::now();                                      //End time
        selectionRes.reverse += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Nearly sorted
        start = chrono::high_resolution_clock::now();                                     //Start time
        selectionCompares.nearly += selectionSort<int>(nearlySortedArr, nearlySortedArr.length, selectionSwaps.nearly);                     //Call algorithm
        end = chrono::high_resolution_clock::now();                                     //End time
        selectionRes.nearly += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Few unique
        start = chrono::high_resolution_clock::now();                                       //Start time
        selectionCompares.fewUnique += selectionSort<int>(fewUniqueArr, fewUniqueArr.length, selectionSwaps.fewUnique);                             //Call algorithm
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
    AlgoResults exchangeSwaps;
    AlgoResults exchangeCompares;

    for (int i=0; i < times; i++)
    {
        //Random
        start = chrono::high_resolution_clock::now();                                    //Start time
        exchangeCompares.random += exchangeSort<int>(randomArr, randomArr.length, exchangeSwaps.random);                                 //Call algorithm
        end = chrono::high_resolution_clock::now();                                    //End time
        exchangeRes.random += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time


        //Reverse sorted
        start = chrono::high_resolution_clock::now();                                     //Start time
        exchangeCompares.reverse += exchangeSort<int>(reverseSortedArr, reverseSortedArr.length, exchangeSwaps.reverse);                    //Call algorithm
        end = chrono::high_resolution_clock::now();                                     //End time
        exchangeRes.reverse += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Nearly sorted
        start = chrono::high_resolution_clock::now();                                    //Start time
        exchangeCompares.nearly += exchangeSort<int>(nearlySortedArr, nearlySortedArr.length, exchangeSwaps.nearly);                     //Call algorithm
        end = chrono::high_resolution_clock::now();                                    //End time
        exchangeRes.nearly += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Few unique
        start = chrono::high_resolution_clock::now();                                      //Start time
        exchangeCompares.fewUnique += exchangeSort<int>(fewUniqueArr, fewUniqueArr.length, exchangeSwaps.fewUnique);                             //Call algorithm
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
    AlgoResults bubbleCompares;

    for (int i=0; i < times; i++)
    {
        //Random data
        start = chrono::high_resolution_clock::now();                                     //Start time
        bubbleCompares.random += bubbleSort<int>(randomArr, randomArr.length);                                    //Call algorithm
        end = chrono::high_resolution_clock::now();                                     //End time
        bubbleRes.random += chrono::duration_cast<fpsecond>(end - start).count();      //Get elapsed time

        //Reverse sorted
        start = chrono::high_resolution_clock::now();                                     //Start time
        bubbleCompares.reverse += bubbleSort<int>(reverseSortedArr, reverseSortedArr.length);                      //Call algorithm
        end = chrono::high_resolution_clock::now();                                     //End time
        bubbleRes.reverse += chrono::duration_cast<fpsecond>(end - start).count();     //Get elapsed time

        //Nearly sorted
        start = chrono::high_resolution_clock::now();                                     //Start time
        bubbleCompares.nearly += bubbleSort<int>(nearlySortedArr, nearlySortedArr.length);                        //Call algorithm
        end = chrono::high_resolution_clock::now();                                     //End time
        bubbleRes.nearly += chrono::duration_cast<fpsecond>(end - start).count();      //Get elapsed time

        //Few unique
        start = chrono::high_resolution_clock::now();                                     //Start time
        bubbleCompares.fewUnique += bubbleSort<int>(fewUniqueArr, fewUniqueArr.length);                              //Call algorithm
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
    AlgoResults insertionCompares;

    for (int i=0; i < times; i++)
    {
        //Random
        start = chrono::high_resolution_clock::now();                                     //Start time
        insertionCompares.random += insertionSort<int>(randomArr, randomArr.length);                                 //Call algorithm
        end = chrono::high_resolution_clock::now();                                     //End time
        insertionRes.random += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Reverse sorted
        start = chrono::high_resolution_clock::now();                                      //Start time
        insertionCompares.reverse += insertionSort<int>(reverseSortedArr, reverseSortedArr.length);                    //Call algorithm
        end = chrono::high_resolution_clock::now();                                      //End time
        insertionRes.reverse += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Nearly sorted 
        start = chrono::high_resolution_clock::now();                                     //Start time
        insertionCompares.nearly += insertionSort<int>(nearlySortedArr, nearlySortedArr.length);                     //Call algorithm
        end = chrono::high_resolution_clock::now();                                     //End time
        insertionRes.nearly += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Few unique
        start = chrono::high_resolution_clock::now();                                        //Start time
        insertionCompares.fewUnique += insertionSort<int>(fewUniqueArr, fewUniqueArr.length);                              //Call algorithm
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
    AlgoResults mergeCompares;

    for (int i=0; i < times; i++)
    {
        //Random 
        start = chrono::high_resolution_clock::now();                                 //Start time
        mergeSort<int>(randomArr, 0, randomArr.length-1,mergeCompares.random);                            //Call algorithm
        end = chrono::high_resolution_clock::now();                                 //End time
        mergeRes.random += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Reverse sorted
        start = chrono::high_resolution_clock::now();                                  //Start time
        mergeSort<int>(reverseSortedArr, 0, reverseSortedArr.length-1, mergeCompares.reverse);               //Call algorithm
        end = chrono::high_resolution_clock::now();                                  //End time
        mergeRes.reverse += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Nearly sorted
        start = chrono::high_resolution_clock::now();                                 //Start time
        mergeSort<int>(nearlySortedArr, 0, nearlySortedArr.length-1, mergeCompares.nearly);                //Call algorithm
        end = chrono::high_resolution_clock::now();                                 //End time
        mergeRes.nearly += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Few unique
        start = chrono::high_resolution_clock::now();                                    //Start time
        mergeSort<int>(fewUniqueArr, 0, fewUniqueArr.length-1, mergeCompares.fewUnique);                         //Call algorithm
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
    AlgoResults quickCompares;

    for (int i=0; i < times; i++)
    {
        //Random 
        start = chrono::high_resolution_clock::now();                                 //Start time
        quickSort<int>(randomArr, 0, randomArr.length-1, quickCompares.random);                            //Call algorithm
        end = chrono::high_resolution_clock::now();                                 //End time
        quickRes.random += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        
        //Reverse sorted
        start = chrono::high_resolution_clock::now();                                  //Start time
        quickSort<int>(reverseSortedArr, 0, reverseSortedArr.length-1, quickCompares.reverse);               //Call algorithm
        end = chrono::high_resolution_clock::now();                                  //End time
        quickRes.reverse += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Nearly sorted
        start = chrono::high_resolution_clock::now();                                 //Start time
        quickSort<int>(nearlySortedArr, 0, nearlySortedArr.length-1, quickCompares.nearly);                //Call algorithm
        end = chrono::high_resolution_clock::now();                                 //End time
        quickRes.nearly += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Few unique
        start = chrono::high_resolution_clock::now();                                    //Start time
        quickSort<int>(fewUniqueArr, 0, fewUniqueArr.length-1, quickCompares.fewUnique);                         //Call algorithm
        end = chrono::high_resolution_clock::now();                                    //End time
        quickRes.fewUnique += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Generate new data
        randomArr.genNewData();
        reverseSortedArr.genNewData();
        nearlySortedArr.genNewData();
        fewUniqueArr.genNewData();
        
    }


    // HEAP SORT //
    AlgoResults heapRes;
    AlgoResults heapCompares;

    for (int i=0; i < times; i++)
    {
        //Random 
        start = chrono::high_resolution_clock::now();                                //Start time
        heapSort<int>(randomArr, randomArr.length, heapCompares.random);                                 //Call algorithm
        end = chrono::high_resolution_clock::now();                                //End time              
        heapRes.random += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Reverse sorted
        start = chrono::high_resolution_clock::now();                                 //Start time
        heapSort<int>(reverseSortedArr, reverseSortedArr.length, heapCompares.reverse);                    //Call algorithm
        end = chrono::high_resolution_clock::now();                                 //End time
        heapRes.reverse += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Nearly sorted
        start = chrono::high_resolution_clock::now();                                //Start time
        heapSort<int>(nearlySortedArr, nearlySortedArr.length, heapCompares.nearly);                     //Call algorithm
        end = chrono::high_resolution_clock::now();                                //End time
        heapRes.nearly += chrono::duration_cast<fpsecond>(end - start).count();   //Get elapsed time

        //Few unique
        start = chrono::high_resolution_clock::now();                                   //Start time
        heapSort<int>(fewUniqueArr, fewUniqueArr.length, heapCompares.fewUnique);                              //Call algorithm
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

    // COUNT AVERAGES
    avg(selectionCompares, times);
    avg(exchangeCompares, times);
    avg(insertionCompares, times);
    avg(mergeCompares, times);
    avg(quickCompares, times);
    avg(mergeCompares, times);

    // SWAP AVERAGES

    avg(exchangeSwaps, times);
    avg(selectionSwaps, times);


    // RESULTS //
    int w = 20;  //w(idth)
    //Headers
    cout << "Length of Arrays: " << arrlen << '\n';
    cout << "Number of Trials: " << times << "\n\n";

    cout << "Algorithm sort times:" << setw(18) << "Random " << setw(w) << "Reverse Sorted " << setw(w) << "Nearly Sorted " << setw(w) << "Few Unique\n";
    cout << "==========\n";

    //Average times of each algorithm for each dataset
    /*          Algorithm                        Random Dataset                  Reverse Sorted Dataset              Nearly Sorted Dataset                 Few Unique Dataset        */
    cout << "Selection Sort: "  << setw(22) << selectionRes.random << "s" << setw(w-1) << selectionRes.reverse << "s" << setw(w-1) << selectionRes.nearly << "s" << setw(w-1) << selectionRes.fewUnique << "s" << '\n';
    cout << "Exchange Sort: "   << setw(23) << exchangeRes.random  << "s" << setw(w-1) << exchangeRes.reverse  << "s" << setw(w-1) << exchangeRes.nearly  << "s" << setw(w-1) << exchangeRes.fewUnique  << "s" << '\n';
    cout << "Bubble Sort: "     << setw(25) << bubbleRes.random    << "s" << setw(w-1) << bubbleRes.reverse    << "s" << setw(w-1) << bubbleRes.nearly    << "s" << setw(w-1) << bubbleRes.fewUnique    << "s" << '\n';
    cout << "Insertion Sort: "  << setw(22) << insertionRes.random << "s" << setw(w-1) << insertionRes.reverse << "s" << setw(w-1) << insertionRes.nearly << "s" << setw(w-1) << insertionRes.fewUnique << "s" << '\n';
    cout << "Merge Sort: "      << setw(26) << mergeRes.random     << "s" << setw(w-1) << mergeRes.reverse     << "s" << setw(w-1) << mergeRes.nearly     << "s" << setw(w-1) << mergeRes.fewUnique     << "s" << '\n';
    cout << "Quick Sort: "      << setw(26) << quickRes.random     << "s" << setw(w-1) << quickRes.reverse     << "s" << setw(w-1) << quickRes.nearly     << "s" << setw(w-1) << quickRes.fewUnique     << "s" << '\n';
    cout << "Heap Sort: "       << setw(27) << heapRes.random      << "s" << setw(w-1) << heapRes.reverse      << "s" << setw(w-1) << heapRes.nearly      << "s" << setw(w-1) << heapRes.fewUnique      << "s" << '\n';

    // compares

    cout << fixed << setprecision(2)<<right;
    cout << "\n\n\nAlgorithm compares:" << setw(w) << "Random " << setw(w) << "Reverse Sorted " << setw(w) << "Nearly Sorted " << setw(w) << "Few Unique\n";
    cout << "==========\n";

    //Average times of each algorithm for each dataset
    /*          Algorithm                        Random Dataset                  Reverse Sorted Dataset              Nearly Sorted Dataset                 Few Unique Dataset        */
    cout << "Selection Sort: "  << setw(22) << selectionCompares.random << setw(w) << selectionCompares.reverse << setw(w) << selectionCompares.nearly << setw(w) << selectionCompares.fewUnique << '\n';
    cout << "Exchange Sort: "   << setw(23) << exchangeCompares.random  << setw(w) << exchangeCompares.reverse  << setw(w) << exchangeCompares.nearly  << setw(w) << exchangeCompares.fewUnique  << '\n';
    cout << "Bubble Sort: "     << setw(25) << bubbleCompares.random    << setw(w) << bubbleCompares.reverse    << setw(w) << bubbleCompares.nearly    << setw(w) << bubbleCompares.fewUnique    << '\n';
    cout << "Insertion Sort: "  << setw(22) << insertionCompares.random << setw(w) << insertionCompares.reverse << setw(w) << insertionCompares.nearly << setw(w) << insertionCompares.fewUnique << '\n';
    cout << "Merge Sort: "      << setw(26) << mergeCompares.random     << setw(w) << mergeCompares.reverse     << setw(w) << mergeCompares.nearly     << setw(w) << mergeCompares.fewUnique     << '\n';
    cout << "Quick Sort: "      << setw(26) << quickCompares.random     << setw(w) << quickCompares.reverse     << setw(w) << quickCompares.nearly     << setw(w) << quickCompares.fewUnique     << '\n';
    cout << "Heap Sort: "       << setw(27) << heapCompares.random      << setw(w) << heapCompares.reverse      << setw(w) << heapCompares.nearly      << setw(w) << heapCompares.fewUnique      << '\n';
    

    //swaps 
    cout << fixed << setprecision(2) << right;
    cout << "\n\n\nAlgorithm swaps:" << setw(23) << "Random " << setw(w) << "Reverse Sorted " << setw(w) << "Nearly Sorted " << setw(w) << "Few Unique\n";
    cout << "==========\n";

    //Average times of each algorithm for each dataset
    /*          Algorithm                        Random Dataset                  Reverse Sorted Dataset              Nearly Sorted Dataset                 Few Unique Dataset        */
    cout << "Selection Sort: " << setw(22) << selectionSwaps.random << setw(w) << selectionSwaps.reverse << setw(w) << selectionSwaps.nearly << setw(w) << selectionSwaps.fewUnique << '\n';
    cout << "Exchange Sort: " << setw(23) << exchangeSwaps.random << setw(w) << exchangeSwaps.reverse << setw(w) << exchangeSwaps.nearly << setw(w) << exchangeSwaps.fewUnique << '\n';

    return 0;
}          

