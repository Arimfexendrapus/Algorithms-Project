#pragma once

//Swap function
#include "Swap.cpp"
#include <cstddef>

//Exchange sort
template <typename T>
double exchangeSort(T array[], const size_t size, double& swaps)
{

    //compare count
    double compareCount = 0;
    //sorted bool
    bool notSorted = true;
    //For every element in the array
    for (size_t i = 0; i < size-1 && notSorted; i++)
    {
        //set flag false
        notSorted = false;
        //Compare every element after it to the current element (i), swapping if needed
        for (size_t j = i + 1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                //mark as not sorted if not sorted
                notSorted = true;
                Swap<T>(array[i], array[j]);
                swaps++;
            }
            compareCount++;
        }
    }
    return compareCount;
}
