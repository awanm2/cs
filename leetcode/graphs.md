
# 886. Possible Bipartition

[886. Possible Bipartition](https://leetcode.com/problems/possible-bipartition/)

. The problem is asking if the graph can be divided into two halves.
. Bipartite graph - graph that can be spilt into two halves.
. Basically color the graph into two colors. Three color is hard (i think it is NP problem).
. Two color-able is solvable. 
. Use BFS to solve it.
# 1971. Find if Path Exists in Graph
[1971. Find if Path Exists in Graph](https://leetcode.com/problems/find-if-path-exists-in-graph/)
1. Build the graph using adjacency list. Note this is a bi-directional (undirected ) graph.
2. Do a DFS starting from source to destination. if a destination is found during DFS well all is well and return true else return false.
3. Time Complexity - worst case O(n+m) - n is vertices and m is size of edge list.
4. Since this is recursive or using a stack so  it will be O(n*m)


# Dynamic Programming

## 55. Jump Game

[55. Jump Game](https://leetcode.com/problems/jump-game/)
This is a DAG problem. Look at following picture.

![A path from first node to last](https://github.com/awanm2/cs/blob/main/leetcode/img/lc55/lc_55_a.png)
![A path doesnot exist from first node to last](https://github.com/awanm2/cs/blob/main/leetcode/img/lc55/lc_55_b.png)

* What is the farthest distance we can go from current index. 
* On each node calculate the max index we can reach. Update the max index if a new calculated node we can reach is greater then max index i.e. i + nums[i] > maxIndex.
* At any point, if we find i less than maxIndex, that means we cannot rach the last node.
  
