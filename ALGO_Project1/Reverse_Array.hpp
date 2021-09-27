#pragma once

#include <iostream>

#include "Reverse_Exchange_Sort.hpp"
#include "Random_Array.hpp"

using namespace std;


void reverse_sorted_array(int array[], int size, int range)
{
    randomArray(array, size, range);
    reverseExchangeSort(array, size);
}