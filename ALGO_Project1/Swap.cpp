#pragma once

template <typename T>
void Swap(T& a, T& b) //Cannot be 'swap' (lowercase) since it's a pre-defined function
{
    T temp = a;
    a = b;
    b = temp;
}
