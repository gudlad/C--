**_[C]()ontainers_**

- Data structures that can store object of almost any type [template based classes]
- Each container has member functions
  [ some are specific to container, others are available to all containers]
- Each container has an associated header file
  #include <container_type>

In C++, container classes like `std::vector`, `std::list`, `std::set`, and others, are designed to manage collections of elements. When you add elements to these containers, they often make copies of the elements being added. This behavior has several implications:

1. **Ownership and Lifetimes** : The container takes ownership of the copied elements. This means that the container is responsible for the memory management of these elements, including their destruction when they are removed from the container or when the container itself is destroyed.
2. **Value Semantics** : Containers in C++ generally follow value semantics. This means that when you add an element to the container, a copy of the element is made, and any subsequent modifications to the original element do not affect the copy stored in the container.

#include `<vector>`
#include `<iostream>`

int main() {
std::vector`<int>` myVector;

    int originalValue = 42;
    myVector.push_back(originalValue);

    // Modifying the original value does not affect the value in the vector
    originalValue = 99;

    std::cout << "Original value: " << originalValue << std::endl;
    std::cout << "Value in vector: " << myVector[0] << std::endl;

    return 0;

}
