#pragma once

#include <iostream>
#include "Swap.cpp"

using namespace std;


//Exchange sort
template <typename T>
void reverseExchangeSort(T array[], const size_t size)
{
    //For every element in the array
    for (size_t i = 0; i < size-1; i++)
    {
        //Compare every element after it to the current element (i), swapping if needed
        for (size_t j = i + 1; j < size; j++)
        {
            if (array[i] < array[j])
                Swap<T>(array[i], array[j]);
        }
    }
}
