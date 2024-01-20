# Adapter Conatainers:

**_1 . Stack:_**

- LIFO data structure
- Implemented as an adapter over other STL container
- Can be implemented as a vector,list or deque
- All operations occur on one end of stack(top)
- NO iterators are supported.

2. **_Queue_**

- FIFO data structure.
- implemented over list,deque
- elements are pushed at the back and popped from the front
- No iterators supported.

**_3. Priority Queue_**

- Allows insertions and removal of elements in order from the front of the container
- elements are stored internally as a vector by default
- Elements are inserted in priority order ( Largest value will always be at the front )
- No iterators are supported.
