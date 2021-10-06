#pragma once

//Swap function
#include "Swap.cpp"
#include <cstddef>
#include <algorithm>

//Bubble sort
template <typename T>
void bubbleSort(T array[], const size_t size)
{

    bool notSorted = true;
    int i, j, temp;
    while (notSorted)
    {
        for (i = 0; i < size; i++)
        {
            notSorted = false;
            for (j = 0; j < size - i - 1; j++)
            {
                if (array[j] > array[j + 1])
                {
                    notSorted = true;
                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }










    /*
    //For each element in the array
    for (size_t i = 0; i < size-1; ++i)
    {
        notSorted = false;
        //Loop over each element in the array (starting at the beginning!)
        for (size_t j = 0; j < size; ++j)
        {

            //If you following element is smaller than the current, swap them
            if (array[j] > array[j + 1])
            {
                Swap<T>(array[j], array[j + 1]);
            }
        }
    }
    */
}

