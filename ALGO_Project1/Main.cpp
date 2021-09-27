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

#include "Bubble_Sort.hpp"
#include "Exchange_Sort.hpp"
#include "Insertion_Sort.hpp"
#include "Merge_Sort.hpp"
#include "Quick_Sort.hpp"
#include "Selection_Sort.hpp"
#include "Swap.hpp"
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










