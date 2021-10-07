#pragma once
#include <cstddef>


//Merge
template <typename T>
void merge(T array[], const size_t l, const size_t m, const size_t r, double& compares)
{
    //Declare three iterators (to span across for loops)
    size_t i, j, k;

    //Size of left and right sub-arrays
    size_t size_left = m - l + 1, size_right = r - m;

    
    //Declare the two sub arrays
    int* left = new int[size_left];
    int* right = new int[size_right];

    //T left[size_left], right[size_right];

    //Copy array[l...mid] into left[l..length]
    for (i = 0; i < size_left; i++)
        left[i] = array[l + i];

    //Copy array[mid+1..r] into right[1..length]
    for (j = 0; j < size_right; j++)
        right[j] = array[m + 1 + j];

    //Reset the counters
    i = 0; j = 0; k = l;

    //Merge temp arrays (left + right) into the to real array
    while (i < size_left and j < size_right)
    {
        //Select an element from the left or right subarray
        if (left[i] <= right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }

        //Proceed to the next element
        k++;
        compares++;
    }

    //Copy elements from the new sorted array into the main array
    while (i < size_left)
    {
        array[k] = left[i];
        i++;
        k++;
    }
    while (j < size_right)
    {
        array[k] = right[j];
        j++;
        k++;
    }
    delete left;
    delete right;
}


//Merge sort
template <typename T>
void mergeSort(T array[], const size_t l, const size_t r, double& compares)
{
    if (l < r)   // if (size > 1)
    {
        //Calculate the midpoint
        size_t m = l + (r - l) / 2;

        //Sort first and second arrays
        mergeSort<T>(array, l, m,compares);
        mergeSort<T>(array, m + 1, r,compares);

        //Merge
        merge<T>(array, l, m, r,compares);
    }
}
