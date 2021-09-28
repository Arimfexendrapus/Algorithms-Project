#pragma once

#include <iostream>

using namespace std;


//Exchange sort
template <typename T>
void nearlySortedArray(T array[], const size_t size, const size_t range)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        int numRand = rand() % range;
        array[i] = numRand;
    }
    //For every element in the array
    for (size_t i = 0; i < size - (size / 10); i++)
    {
        //Compare every element after it to the current element (i), swapping if needed
        for (size_t j = i + 1; j < size; j++)
        {
            if (array[i] < array[j])
                Swap<T>(array[i], array[j]);
        }
    }
}
