# **_What is STL?_**

- A library of powerful, reusable, adaptable, generic classes and functions.
- Implemented using C++ templates.
- Impletements common data structures and algorithms.
- known time and size complexity.
- fast and type safe

## _Elements of the STL_

1. **Containers:**
   Collections of objects or primitive types.
   [ Array, Vector, deque, stack ,set, map etc..]
2. **Algorithms: (60)**
   Functions for processing sequences of elements from containers.
   [ find,max, count, accumulate,sort etc ..]
3. **Iterators**:
   Generate sequences of element from containers.
   [ forward, reverse, by value, by reference, constant etc.]

---

## **_Types of Containers._**

**1. Sequence containers:**

maintain the sequence in which elements inserted.

_ex:_ array , vector, list, forward_list, deque

_**2. Associate container:**_

Associative containers in the C++ STL are data structures that provide fast retrieval of data based on keys. Unlike sequence containers (such as vectors or lists) that organize elements in a linear manner, associative containers use keys to organize and access their elements efficiently.

The key feature of associative containers is that they maintain a sorted order based on the keys, allowing for quick lookups and searches.

_ex:_ set,mutli set, map, multi map

**3. Container adapters**

variations of other containers

this category doesn't support iterators, so can't be used with STL algorithms.

_ex:_ stack, queue, priority queue.

---

## **_Types of Iterators:_**

**Input Iterators** - from the container to the program.

**Output iterators** - from the program to the container.

**Forward iterators** - navigate one item at a time in one direction.

**Bi-directional iterators** - navigate one item at a time both directions.

**Random access iterators** - directly access a container item.

---

## Types of Algorithms:

Non-modifying and modifying algorithms.
