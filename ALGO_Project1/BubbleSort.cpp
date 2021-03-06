#pragma once

//Swap function
#include "Swap.cpp"

//Contains 'size_t'
#include <cstddef>

//Bubble sort
template <typename T>
double bubbleSort(T array[], const size_t size)
{
    double compares = 0;
    bool notSorted = true;
    
        //For each element in array
        for (int i = 0; i < size && notSorted; i++)
        {
            //Set not sorted to false
            notSorted = false;
            //Loop over each element in the array from the beginning
            for (int j = 0; j < size - i - 1; j++)
            {
                //Checks if sorted AND swaps if not
                if (array[j] > array[j + 1])
                {
                    notSorted = true;
                    Swap<T>(array[j], array[j + 1]);
                }
                compares++;
            }
        }
        return compares;
    
}

