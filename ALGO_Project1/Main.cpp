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
    std::chrono::duration<double, array[10];
    for (int i = 0; i < 100; i++)
    {

    }
    auto start = chrono::high_resolution_clock::now();
    
    //
    //  Insert the code that will be timed
    
    auto end = chrono::high_resolution_clock::now();
    // Store the time difference between start and end
    auto diff = (end - start);



    int array[10];
    randomArray(array, 10, 10);
    exchangeSort(array, 10);
    printArray(array, 10);
    
}
