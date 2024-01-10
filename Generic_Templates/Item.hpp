#ifndef _ITEM_HEADER_
#define _ITEM_HEADER_

// Template classes are typically completely contained in header files
// So, we would have the template class in Item.hpp and no Item.cpp file used

template <typename T>
class Item
{
private:
    std::string name;
    T value;

public:
    Item(std::string name, T value) : name{name}, value{value}
    {
    }
    std::string get_name() const
    {
        return name;
    }
    T get_value() const
    {
        return value;
    }
};

template <typename T, typename U>
struct my_pair
{
    T first;
    U second;
};

#endif