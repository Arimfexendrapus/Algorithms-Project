#pragma once

//Swap function
#include "Swap.cpp"
#include <cstddef>

//Exchange sort
template <typename T>
int exchangeSort(T array[], const size_t size, int& swaps)
{

    //compare count
    int compareCount = 0;
    swaps = 0;
    //For every element in the array
    for (size_t i = 0; i < size-1; i++)
    {
        //Compare every element after it to the current element (i), swapping if needed
        for (size_t j = i + 1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                Swap<T>(array[i], array[j]);
                swaps++;
            }
            compareCount++;
        }
    }
    return compareCount;
}
