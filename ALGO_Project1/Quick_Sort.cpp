#pragma once

#include <iostream>

using namespace std;

//
void partition(index low, index high, index& pivotpoint)
{
    index i, j;
    keytype pivotitem;

    pivotitem = S[low];
    j = low;

    for (i = low + 1; i <= high; i++)
    {
        if (S[i] < pivotitem)
        {
            j++;
            swap(S[i], S[j]);
        }
    }

    pivotpoint = j;
    swap(S[low], S[pivotpoint]);
}


//Quicksort
void quicksort(index low, index high)
{
    index pivotpoint;

    if (high > low)
    {
        partition(low, high, pivotpoint);
        quicksort(low, pivotpoint - 1);
        quicksort(pivotpoint + 1, high);
    }
}
