/*
  Author: Ethan Cox
  Date: 9/27/2021
  Compilation Instructions: None
  Function:
  
  Usage examples:
  'Dataset<int,20> array' is an array of 20 random integers, distributed uniformly
  'Dataset<int,20,SORTED> array' is an array of 20 random, sorted integers, distributed uniformly
  'Dataset<int,20,REVERSE_SORTED> array' is an array of 20 random, sorted integers, distributed uniformly
  'Dataset<int,20,FEW_UNIQUE> array' is an array of 20, few-unique integers
  
  WARNINGS: do not use floating-point numbers or the FEW_UNIQUE distribution. They have not been implemented.
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
enum Distribution { UNIFORM, SORTED, REVERSE_SORTED, FEW_UNIQUE};   //TODO: implement FEW_UNIQUE


//Dataset class contains a smart pointer to an array of random numeric values
template <typename T, size_t size, Distribution distribution = UNIFORM>  //Default distribution is 'UNIFORM' (generic random dataset)
class Dataset
{
    //Type-guarding against non-numeric types
    static_assert(is_arithmetic<T>::value, "Dataset class can only be a numeric type (int, float, double...etc)");

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
    if (distribution == UNIFORM or distribution == SORTED or distribution == REVERSE_SORTED)  //Uglier, but gets the point across
    {
        //Fill the array with random values
        for(size_t i=0; i < size; i++)
        {
            //Generate a random value between the minimum and maximum
            array[i] = dist(RNG);
        }
    }


    //Sort? 
    if (distribution == SORTED)
    {
        //Sort in non-decreasing order (0 -> 1000, with repeats)
        sort(array, array + length, [](size_t i, size_t j) {return i < j;});   //lambda expression
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
