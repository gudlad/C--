#ifndef _ARRAY_TEMPLATE_CLASS
#define _ARRAY_TEMPLATE_CLASS
#include <iostream>

template <typename T, int N> //! non type-template parameter
class Array
{
    int size{N};
    T values[N]; // memory allocated at stack so need to mention the size with the help of non type template argument.
                 // also it can't be values[size] as size is determined at run time so need constant.

    friend std::ostream &operator<<(std::ostream &os, const Array<T, N> &arr)
    {
        // This version is specific to the template parameter N. It assumes that the size of the array is part of the type information and must be specified during the instantiation of the Array class. This is useful when you want to enforce that the size is known at compile time and is part of the type.
        os << "[";
        for (const auto &val : arr.values)
            os
                << val << ",";
        os << "]" << std::endl;
        return os;
    }

public:
    Array() = default;
    Array(T init_val) // initialize all the array elements.
    {
        for (auto &i : values)
            i = init_val;
    }
    void fill(T val)
    {
        for (auto &i : values)
            i = val;
    }
    int get_size() const
    {
        return size;
    }

    // overloaded subscript operator for easy use
    T &operator[](int index) // nums.operator[](0)
    {
        return values[index];
    }
};
#endif