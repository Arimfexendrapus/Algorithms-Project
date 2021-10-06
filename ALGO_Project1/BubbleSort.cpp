#pragma once

//Swap function
#include "Swap.cpp"
#include <cstddef>

//Bubble sort
template <typename T>
double bubbleSort(T array[], const size_t size)
{
    double compares = 0;
    //For each element in the array
    for (size_t i = 0; i < size-1; ++i)
    {
        //Loop over each element in the array (starting at the beginning!)
        for (size_t j = 0; j < size; ++j)
        {
            //If you following element is smaller than the current, swap them
            if (array[j] > array[j + 1])
            {
                Swap<T>(array[j], array[j + 1]);
            }
            compares++;
                
        }
    }
    return compares;
}

