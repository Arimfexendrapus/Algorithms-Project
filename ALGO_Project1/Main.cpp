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
#include "Random_Array.hpp"
//#include "Selection_Sort.hpp"
#include "Swap.hpp"
#include "Dataset.hpp"
#include "Nearly_Sorted_Array.hpp"
#include "Print_Array.hpp"







using namespace std;

int main()
{
    int array[2];
    randomArray(array, 2, 2);
    exchangeSort(array, 2);
    printArray(array, 2);
    
}
