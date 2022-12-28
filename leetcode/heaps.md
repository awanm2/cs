# Heaps Notes

# C++ priority_queue
[C++ priority queue] (https://en.cppreference.com/w/cpp/container/priority_queue) provides constant time lookup for the largest (by default) element. 

|Operation| Complexity|
|---------|-----------|
| lookup (largest element)  |Constant|
| insertion/deletion  |logarithmic|


# 1962. Remove Stones to Minimize the Total
[1962. Remove Stones to Minimize the Total](https://leetcode.com/problems/remove-stones-to-minimize-the-total/)
Use a priority queue, pop largest element, make it half, put it back on to priority queue and do it K times. Then sum the array for the result.
Solved in C++. 

Space complexity is O(n) because we are building the heap.
Time complexity is O( (n+k) log n).

:pushpin: : sovle in Python :snake: