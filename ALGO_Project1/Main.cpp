/*

Name : Tyler Felts, Ethan Cox, Drew Faust, Connor Bass
Date : 09-27/2021
Class : Algorithms



Description : Algorithms Project

Target grade : A

*/




#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <cstdlib>
#include <ctime>

#include "Bubble_Sort.h"
#include "Exchange_Sort.h"
#include "Insertion_Sort.h"
#include "Merge_Sort.h"
#include "Quick_Sort.h"
#include "Selection_Sort.h"
#include "Swap.h"
#include "Dataset.hpp"





using namespace std;

void fillArray(int myArray[], int arraySize)
{
    srand(time(0));
    for (int i = 0; i < arraySize; i++)
    {
        int numRand = rand() % 100;
        myArray[i] = numRand;
    }
}










