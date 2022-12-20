# 496. Next Greater Element I

[496. Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/)

This problem can be solved using a stack. 

Lets take nums = [1,3,4,2]
1. We only put numbers on the stack if they are ***monotonically decreasing***. 
2. We push 1. Then comes 3, we cannot push it to stack since 3 > 1 not less than 1. So we pop 1 from stack. However we also record that 3 is next greater element for 1. 
3. And we do this for rest of the elements in the array.
