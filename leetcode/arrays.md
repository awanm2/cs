# Sum problems. 
These are two sum, three sum variations.
## 1. Two Sum
[1. Two Sum](https://leetcode.com/problems/two-sum/)
Use a hashmap to solve this. Since we have to retun the indices hence 

## 15. 3Sum
[15. 3Sum](https://leetcode.com/problems/3sum/)
1. Sort the array.
2. The use three vars i, j, k. 
3. Take i as first one and then from j to k run two sum.
4. Take care of duplicates, skip over duplicates on i and j iteration.

## 16. 3Sum Closest
[16. 3Sum Closest](https://leetcode.com/problems/3sum-closest/)
1. Similar to 3Sum problem.
2. For closest sum use abs to calculate the distance from the sum.


## 167. Two Sum II - Input Array Is Sorted
[167. Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)
1. Keep two pointers. start and end. 
2. if nums[start] + nums[end] == target , yay
3. if nums[start] + nums[end] > target , decrement end
4. if nums[start] + nums[end] <> target , increment start

# Buy-Sell stocks
## 121. Best Time to Buy and Sell Stock
[121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
- Constraints are that the price is positive. 
- There is only one transaction. So we are looking maximum difference between two values.
'''
prices = [7,1,5,3,6,4] 
            L     R 
'''

- Lets make constraints a bit loose and say we allow negative values in the array of the prices. Now what we can do,

- Keep a left pointer and right pointer. 
- Each interation of profile is less than zero , reset left to current right.
- If profit is postive, update max profit. 

Now lets say loss is allowed, so we have a negative number , some how the price went negative.

'''
prices = [7,1,-5,3,6,4] 
'''

So a better way is to do a bit differently 

1. The first value is minPrice.
2. Then on each iteration of loop if  we have new minPrice, update it else calculate the new maxProfit

# Palindrome Problems

## 125. Valid Palindrome
[125. Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)
1. Write your own calls for alphanumeric, tolower etc. 
2. Use two pointers from start and end.

# 1207. Unique Number of Occurrences
[1207. Unique Number of Occurrences](https://leetcode.com/problems/unique-number-of-occurrences/)

1. Count for occurrences using a map.
2. Use a set to check for uniquness.

# 2500. Minimum Average Difference

[2500. Minimum Average Difference](https://leetcode.com/problems/delete-greatest-value-in-each-row/)

Here is the idea. 

1. Sort the grid row by row. Each row should be sorted.
2. Go column by column and find max value of each column. 
3. Add the max value 
# 2256. Minimum Average Difference
[2256. Minimum Average Difference](https://leetcode.com/problems/minimum-average-difference/)
This is a good problem to solve with pre-fix sum.
1. Get the sum of the array.call it right sum. 
2. Then go from left to right updating left sum and updating right sum.
3. *corner case* be careful for the average when there is no value in the right sum, i.e. count for right sum is zero. Then we can have a divide by zero case. 

# 2279. Maximum Bags With Full Capacity of Rocks

[2279. Maximum Bags With Full Capacity of Rocks](https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/)
1. First thought is to build a pair data structure of paris (capacity, rocks), sort based on rocks and then solve greedily with for loop.
2. Second thought, a better one is to make a list of spaces left in the bags data structures and then solve greedily. This uses less space.


# Math,  Logic, Puzzles

## 2244. Minimum Rounds to Complete All Tasks
[2244. Minimum Rounds to Complete All Tasks](https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/
Lets use 8 as an example. We can do task 8 in 4 rounds by grouping 2 tasks. But we can also we do 6 + 2 = 8 which implies we can do this task in two rounds.

* There are three cases - when frequency is 1 then we can return false or -1/
* When frequency is multiple of 3 we are good. 
* When frequency mod 3 is 1 or 2 then this is interesting case.
Look at image below

![image](https://github.com/awanm2/cs/blob/main/leetcode/img/lc2244/lc_2244_a.png)

# Easy Problems
These are straight forward, generally one for loop O(n) kind of problems.

## 724. Find Pivot Index
[724. Find Pivot Index](https://leetcode.com/problems/find-pivot-index/)
Sum the array once and then use it to solve the problem. This is same as [1991. Find the Middle Index in Array](https://leetcode.com/problems/find-the-middle-index-in-array/) 

## 1480. Running Sum of 1d Array
[1480. Running Sum of 1d Array](https://leetcode.com/problems/running-sum-of-1d-array/) Super simple problem.


