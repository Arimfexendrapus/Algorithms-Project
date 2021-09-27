#pragma once

#include <iostream>

using namespace std;


template <typename T>
void Swap(T& a, T& b) noexcept //Cannot be 'swap' (lowercase) since it's a pre-defined function
{
    T temp(move(a));
    a = move(b);
    b = move(temp);
}
