/*
  Author: Ethan Cox
  Date: 9/27/2021
  Compilation Instructions: None
  Function: generates a unique array of X elements of numeric values between the values Y and Z of type T

  Usage examples:
  'Dataset<int,20> array' is an array of 20 random integers, distributed RANDOMly
  'Dataset<int,20,SORTED> array' is an array of 20 random, sorted integers, distributed RANDOMly
  'Dataset<int,20,REVERSE_SORTED> array' is an array of 20 random, sorted integers, distributed RANDOMly
  'Dataset<int,20,FEW_UNIQUE> array' is an array of 20, few-unique integers

  WARNINGS: do not use floating-point numbers. It have not been implemented.
*/

//Header guard
#pragma once

//Native C++ Libraries
#include <iostream>         //Input/output
#include <iomanip>         //Formatting floats
#include <random>         //Random number generators
#include <algorithm>     //Sorting functions
#include <type_traits>  //Type-info for type-guarding

//Native C Libraries
#include <cstddef>     //Contains 'size_t'
using namespace std;


//Different types of distribution
enum Distribution { RANDOM, SORTED, REVERSE_SORTED, FEW_UNIQUE};   //TODO: implement FEW_UNIQUE


//Dataset class contains a smart pointer to an array of random numeric values
template <typename T, size_t size, Distribution distribution = RANDOM>  //Default distribution is 'RANDOM' (generic random dataset)
class Dataset
{
    //Guarding against non-numeric types and arrays of an invalid sizes
    static_assert(is_arithmetic<T>::value, "Dataset class can only be a numeric type (int, float, double...etc)");
    static_assert(size >= 12,"the size of a dataset cannot be less than 12!");

    private:
        T* array;

    public:
        //Public data members
        const size_t length;   //const!

        //Public special methods
        Dataset(T = 1000, T = 0);  //default maximum, minimum
        ~Dataset();

        //Public methods
        T* get();
        void print() const;

        //Operator overloads
        operator T*() const;       //Implicit conversion to pointer (for passing to T[])
        T& operator[](size_t);    //[] Overload for accessing class like 'arr[5] =...'
};

/*
    +----------------------------+
    |   Dataset Implementation   |
    +----------------------------+
*/


// ********** SPECIAL MEMBER FUNCTIONS **********

//Constructor
template <typename T, size_t size, Distribution distribution>
Dataset<T, size, distribution>::Dataset(T max, T min): length(size)   //Initializer list for const data member
{
    //Declare a new array
    array = new T[size];

    //Create + seed Mersenne Twister random number generator
    random_device rd;
    mt19937 RNG(rd());

    //Apply distribution
    uniform_int_distribution<T> dist(min, max);   // TODO: allow for float/double overload via 'if constexpr' conditional compilation

    //Create dataset (separating out FEW_UNIQUE sinces its generation method is ...unique)
    if (distribution == RANDOM or distribution == SORTED or distribution == REVERSE_SORTED)  //Uglier and slower, but more clear.
    {
        //Fill the array with random values
        for(size_t i=0; i < size; i++)
        {
            //Generate a random value between the minimum and maximum
            array[i] = dist(RNG);
        }
    }
    else //if (distribution == FEW_UNIQUE)
    {
        /*
        FEW_UNIQUE Implementation:
        1. Generate a set random set of 6-12 random values (filling the first 6-12 elements of the array)
        2. Use the filled slots to randomly fill the rest of the dataset
        */

        //Apply random distributions
        uniform_int_distribution<T> sampleDist(6,12);      //The amount of random elements to propgate the array with
        uniform_int_distribution<T> selectionDist(0,11);  //Which array element to draw from

        //Random amount of integers (6-12)
        size_t amount = sampleDist(RNG), i = 0;  //sampleDist(RNG);

        //Populate the sample list with a few random values
        for(i; i < amount; i++)
        {
            array[i] = dist(RNG);
        }

        //Use the random sample to propagate the rest of the data
        for(i; i < size; i++)
        {
            //Generate a random value from the sample set
            array[i] = array[selectionDist(RNG) % amount];
        }
    }


    //Sort?
    if (distribution == SORTED)
    {
        //Sort in non-decreasing order (0 -> 1000, with repeats)
        sort(array, array + length, [](size_t i, size_t j) {return i < j;});  //lambda expression
    }

    //Reverse sort?
    if (distribution == REVERSE_SORTED)
    {
        //Sort in non-increasing order (1000 -> 0, with repeats)
        sort(array, array + length, [](size_t i, size_t j) {return i > j;});  //lambda expression
    }
}

//Deconstructor
template <typename T, size_t size, Distribution distribution>
Dataset<T, size, distribution>::~Dataset()
{
    //Automatically free internal array
    delete [] array;
}

// ********** STANDARD METHODS **********

//Return a pointer to the array (not really necessary because of implicit T* conversion)
template <typename T, size_t size, Distribution distribution>
T* Dataset<T, size, distribution>::get()
{
    return array;
}

//Print
template <typename T, size_t size, Distribution distribution>
void Dataset<T, size, distribution>::print() const
{
    //Print float-point numbers with 2 points after the decimal
    cout << fixed << setprecision(2);

    //Print all the values of the array
    for(size_t i=0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

// ********** OPERATOR OVERLOADING **********

//T* Converstion Overload (returns a pointer to the internal array of type T)
template <typename T, size_t size, Distribution distribution>
Dataset<T, size, distribution>::operator T*() const
{
    //The name of the array is a pointer to the first element
    return array;
}

//[] Overload
template <typename T, size_t size, Distribution distribution>
T& Dataset<T, size, distribution>::operator[](size_t index)
{
    return array[index];
}
