/*

Name : Tyler Felts, Ethan Cox, Drew Faust, Connor Bass
Date : 09-27/2021
Class : Algorithms



Description : Algorithms Project

Target grade : A

*/




#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <cstdlib>
#include <chrono>
#include <ctime>

#include "Bubble_Sort.hpp"
#include "Exchange_Sort.hpp"
#include "Insertion_Sort.hpp"
#include "Merge_Sort.hpp"
#include "Random_Array.hpp"
//#include "Quick_Sort.hpp"
#include "Selection_Sort.hpp"
#include "Swap.hpp"
#include "Dataset.hpp"
#include "Nearly_Sorted_Array.hpp"
#include "Print_Array.hpp"
#include "Heap_Sort.hpp"
#include "Many_Duplicates_Array.hpp"
#include "Reverse_Array.hpp"
#include "Reverse_Exchange_Sort.hpp"









using namespace std;

int main()
{
    //testing bubble sort

    int array[1000];
    randomArray(array, 1000, 1000);
    double times[1000];

    for (int i = 0; i < 1000; i++)
    {
        using fpseconds = chrono::duration<double, ratio<1, 1>>;   //Floating-point seconds
        chrono::steady_clock::time_point start = chrono::steady_clock::now();  //Start time

        bubbleSort(array, 1000);

        chrono::steady_clock::time_point end = chrono::steady_clock::now();  //End time

        cout << fixed;   //Prevents number being represented in scientific notation
        times[i] = chrono::duration_cast<fpseconds>(end - start).count();

        randomArray(array, 1000, 1000);
    }

    double sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        sum = times[i] + sum;
    }
    double average = sum / 1000;
    cout << "the average time to sort an array of 1000 elements using bubble sort is: " << average <<" over 1000 intervals" <<endl;


    //testing exchange sort


    randomArray(array, 1000, 1000);
    double times2[1000];

    for (int i = 0; i < 1000; i++)
    {
        using fpseconds = chrono::duration<double, ratio<1, 1>>;   //Floating-point seconds
        chrono::steady_clock::time_point start = chrono::steady_clock::now();  //Start time

        exchangeSort(array, 1000);

        chrono::steady_clock::time_point end = chrono::steady_clock::now();  //End time

        cout << fixed;   //Prevents number being represented in scientific notation
        times2[i] = chrono::duration_cast<fpseconds>(end - start).count();

        randomArray(array, 1000, 1000);
    }

    sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        sum = times2[i] + sum;
    }
    average = sum / 1000;
    cout << "the average time to sort an array of 1000 elements using exchange sort is: " << average << " over 1000 intervals" << endl;


    //testing heap sort


    randomArray(array, 1000, 1000);
    double times3[1000];

    for (int i = 0; i < 1000; i++)
    {
        using fpseconds = chrono::duration<double, ratio<1, 1>>;   //Floating-point seconds
        chrono::steady_clock::time_point start = chrono::steady_clock::now();  //Start time

        heapSort(array, 1000);

        chrono::steady_clock::time_point end = chrono::steady_clock::now();  //End time

        cout << fixed;   //Prevents number being represented in scientific notation
        times3[i] = chrono::duration_cast<fpseconds>(end - start).count();

        randomArray(array, 1000, 1000);
    }

    sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        sum = times3[i] + sum;
    }
    average = sum / 1000;
    cout << "the average time to sort an array of 1000 elements using heap sort is: " << average << " over 1000 intervals" << endl;

    //testing insertion sort

    randomArray(array, 1000, 1000);
    double times4[1000];

    for (int i = 0; i < 1000; i++)
    {
        using fpseconds = chrono::duration<double, ratio<1, 1>>;   //Floating-point seconds
        chrono::steady_clock::time_point start = chrono::steady_clock::now();  //Start time

        insertionSort(array, 1000);

        chrono::steady_clock::time_point end = chrono::steady_clock::now();  //End time

        cout << fixed;   //Prevents number being represented in scientific notation
        times4[i] = chrono::duration_cast<fpseconds>(end - start).count();

        randomArray(array, 1000, 1000);
    }

    sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        sum = times4[i] + sum;
    }
    average = sum / 1000;
    cout << "the average time to sort an array of 1000 elements using insertion sort is: " << average << " over 1000 intervals" << endl;

}
