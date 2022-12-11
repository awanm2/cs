# 872. Leaf-Similar Trees
[872. Leaf-Similar Trees](https://leetcode.com/problems/leaf-similar-trees/)
Maintain two lists and the compare them.

# 938. Range Sum of BST
[938. Range Sum of BST](https://leetcode.com/problems/range-sum-of-bst/)

This problems is walking the binary BST but with in certain range. 


The left subtree of a node contains only nodes with keys lesser than the node’s key.
The right subtree of a node contains only nodes with keys greater than the node’s key.
The left and right subtree each must also be a binary search tree.

# Revisit/Resolve  these

## 1026. Maximum Difference Between Node and Ancestor

[1026. Maximum Difference Between Node and Ancestor](https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/)
If we can keep track of maximum and mimimum value then we can keep track of the 

The idea here is as following
1. We can init two variables as currentMax and currentMin.
2. We can calculate two diffs with node value - currentMax and node value - currentMin. Max of this and saved result can be max difference.
3. Update currentMax and current Min from 
4. Using the node value, we can keep two variables, currentMax and currentMin.
5. We can calculate recursively on left and right side of the tree.

## 1339. Maximum Product of Splitted Binary Tree
[1339. Maximum Product of Splitted Binary Tree](https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/)

The idea here
1. Get the sum of the tree. This is O(n)
2. Now at any node - get sum of its , say left sub-tree. That gives a sum - call it SumA. From total sum subtract this , call it SumB.
3. Then calculate the product and take a max. traverse the tree with this approach. This is also O(n), where n is the number of nodes.
4. Because we are using a big stack so space complexity is also O(n).