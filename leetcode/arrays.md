# Sum problems. 
These are two sum, three sum variations.
## 1. Two Sum
[1. Two Sum](https://leetcode.com/problems/two-sum/)
Use a hashmap to solve this. Since we have to retun the indices hence 
# 1207. Unique Number of Occurrences
[1207. Unique Number of Occurrences](https://leetcode.com/problems/unique-number-of-occurrences/)

1. Count for occurrences using a map.
2. Use a set to check for uniquness.

# 2256. Minimum Average Difference
[2256. Minimum Average Difference](https://leetcode.com/problems/minimum-average-difference/)
This is a good problem to solve with pre-fix sum.
1. Get the sum of the array.call it right sum. 
2. Then go from left to right updating left sum and updating right sum.
3. *corne case* be careful for the average when there is no value in the right sum, i.e. count for right sum is zero. Then we can have a divide by zero case. 