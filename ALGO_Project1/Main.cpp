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

#include "Bubble_Sort.cpp"
#include "Exchange_Sort.cpp"
#include "Insertion_Sort.cpp"
#include "Merge_Sort.cpp"
//#include "Quick_Sort.cpp"
#include "Selection_Sort.cpp"
#include "Swap.cpp"
#include "Dataset.hpp"
#include "Nearly_Sorted_Array.cpp"
#include "Print_Array.cpp"
#include "Heap_Sort.cpp"
#include "Many_Duplicates_Array.cpp"
#include "Reverse_Exchange_Sort.cpp"

using namespace std;
using fpseconds = chrono::duration<double, ratio<1, 1>>;   //Floating-point seconds

int main()
{
    //testing bubble sort
    Dataset<int,1000,RANDOM> array;

    double times[array.length];

    for (int i = 0; i < array.length; i++)
    {
        chrono::steady_clock::time_point start = chrono::steady_clock::now();  //Start time

        bubbleSort<int>(array, array.length);

        chrono::steady_clock::time_point end = chrono::steady_clock::now();  //End time

        cout << fixed;   //Prevents number being represented in scientific notation
        times[i] = chrono::duration_cast<fpseconds>(end - start).count();

        array.genNewData();
    }

    double sum = 0;
    for (int i = 0; i < array.length; i++)
    {
        sum = times[i] + sum;
    }
    double average = sum / array.length;
    cout << "the average time to sort an array of 1000 elements using bubble sort is: " << average <<" over " << array.length << " intervals" <<endl;


    //testing exchange sort


    array.genNewData();
    double times2[array.length];

    for (int i = 0; i < array.length; i++)
    {
        chrono::steady_clock::time_point start = chrono::steady_clock::now();  //Start time

        exchangeSort<int>(array, array.length);

        chrono::steady_clock::time_point end = chrono::steady_clock::now();  //End time

        cout << fixed;   //Prevents number being represented in scientific notation
        times2[i] = chrono::duration_cast<fpseconds>(end - start).count();

        array.genNewData();
    }

    average = sum / array.length;
    cout << "the average time to sort an array of 1000 elements using exchange sort is: " << average << " over " << array.length << " intervals" << endl;


    //testing heap sort


    array.genNewData();
    double times3[array.length];

    for (int i = 0; i < array.length; i++)
    {
        chrono::steady_clock::time_point start = chrono::steady_clock::now();  //Start time

        heapSort<int>(array, array.length);

        chrono::steady_clock::time_point end = chrono::steady_clock::now();  //End time

        cout << fixed;   //Prevents number being represented in scientific notation
        times3[i] = chrono::duration_cast<fpseconds>(end - start).count();

        array.genNewData();
    }

    sum = 0;
    for (int i = 0; i < array.length; i++)
    {
        sum = times3[i] + sum;
    }
    average = sum / array.length;
    cout << "the average time to sort an array of 1000 elements using heap sort is: " << average << " over " << array.length << " intervals" << endl;

    //testing insertion sort

    array.genNewData();
    double times4[array.length];

    for (int i = 0; i < array.length; i++)
    {
        chrono::steady_clock::time_point start = chrono::steady_clock::now();  //Start time

        insertionSort<int>(array, array.length);

        chrono::steady_clock::time_point end = chrono::steady_clock::now();  //End time

        cout << fixed;   //Prevents number being represented in scientific notation
        times4[i] = chrono::duration_cast<fpseconds>(end - start).count();

        array.genNewData();
    }

    sum = 0;
    for (int i = 0; i < array.length; i++)
    {
        sum = times4[i] + sum;
    }
    average = sum / array.length;
    cout << "the average time to sort an array of 1000 elements using insertion sort is: " << average << " over " << array.length << " intervals" << endl;

}
