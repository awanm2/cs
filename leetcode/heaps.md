# Heaps Notes

# C++ priority_queue
[C++ priority queue](https://en.cppreference.com/w/cpp/container/priority_queue) provides constant time lookup for the largest (by default) element. 

|Operation| Complexity|
|---------|-----------|
| lookup (largest element)  |Constant|
| insertion/deletion  |logarithmic|


# 1962. Remove Stones to Minimize the Total
[1962. Remove Stones to Minimize the Total](https://leetcode.com/problems/remove-stones-to-minimize-the-total/)
Use a priority queue, pop largest element, make it half, put it back on to priority queue and do it K times. Then sum all the elements in priority queue for the result.
Solved in C++. 

Space complexity is O(n) because we are building the heap.
Time complexity is O( (n+k) log n).

:pushpin: : sovle in Python :snake:

# 2208. Minimum Operations to Halve Array Sum

[2208. Minimum Operations to Halve Array Sum] https://leetcode.com/problems/minimum-operations-to-halve-array-sum/
* Use a priority queue. However the *tricky* part is to recognize that we are halving the sum so 5/2 is 2.5 so the priority queue should be a double type. 
* The other part is to know when to stop counting.

