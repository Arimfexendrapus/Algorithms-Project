#pragma once

//Swap function
#include "Swap.cpp"

//Declare a pivot point -- put all smaller values before it and all larger values after it
template <typename T>
void partition(T array[], const size_t low, const size_t high, size_t& pivotpoint)
{
    //Pivotitem = given element, j = given index
    T pivotitem = array[low];
    size_t j = low;

    //Iterate over all the following elements
    for(size_t i=low+1; i <= high; i++)
    {
        //If the current element is less than the pivotitem
        if (array[i] < pivotitem)
        {
            //Increment j and swap the elements
            j++;
            Swap<T>(array[i], array[j]);
        }
    }

    //Move pivotitem to pivotpoint
    pivotpoint = j;
    Swap<T>(array[low], array[pivotpoint]);
}


//Quicksort
template <typename T>
void quickSort(T array[], const size_t low, const size_t high)
{
    size_t pivotpoint;

    if (low < high)  //Stop sorting
    {
        //Sort the array into left and right halves
        partition<T>(array, low, high, pivotpoint);   //pivotpoint passed by reference!

        //Sort the left half
        quickSort<T>(array, low, pivotpoint-1);

        //Sort the right half
        quickSort<T>(array, pivotpoint+1, high);
    }
}
