#pragma once

#include <iostream>

using namespace std;

//Insertion sort

void randomArray(int myArray[], int arraySize, int range)
{
    srand(time(0));
    for (int i = 0; i < arraySize; i++)
    {
        int numRand = rand() % range;
        myArray[i] = numRand;
    }
}

