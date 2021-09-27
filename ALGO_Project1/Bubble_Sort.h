#pragma once

#include <iostream>

using namespace std;

//Bubble sort
template <typename T>
void bubbleSort(T array[], const size_t size)
{
    //For each element in the array
    for (size_t i = 0; i < size - 1; ++i)
    {
        //Loop over each element in the array (starting at the beginning!)
        for (size_t j = 0; j < size; ++j)
        {
            //If you following element is smaller than the current, swap them
            if (array[j] > array[j + 1])
                Swap<T>(array[j], array[j + 1]);
        }
    }
}

