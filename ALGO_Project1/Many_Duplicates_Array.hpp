#pragma once

#include <iostream>

using namespace std;

//Insertion sort
template <typename T>
void fillArray(T myArray[], int arraySize)
{
    srand(time(0));
    for (int i = 0; i < arraySize; i++)
    {
        int numRand = rand() % arraySize/5;
        myArray[i] = numRand;
    }
}
