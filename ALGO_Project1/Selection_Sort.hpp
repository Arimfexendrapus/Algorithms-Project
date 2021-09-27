#pragma once

#include <iostream>

using namespace std;


//Selection sort
template <typename T>
void selectionSort(T array[], const size_t size)
{
    //To keep track of the smallest number in the array
    size_t min;

    //For every element in the array
    for (size_t i = 0; i < size - 1; ++i)
    {
        //Set the 'smallest' number to the current index
        min = i;

        //Starting at the current index, iterate over the rest of the indices until the array is exhausted
        for (size_t j = i + 1; j < size; ++j)
        {
            //If you come across a smaller number while iterating, set it to the smallest number
            if (array[j] < array[min])
                min = j;
        }

        //Swap the current index with the smallest number found
        Swap<T>(array[i], array[min]);
    }

}

