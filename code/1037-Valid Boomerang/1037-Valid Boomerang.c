/*
LeetCode 1037 - Valid Boomerang

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
Given an array points where points[i] = [xi, yi] represents a point on the X-Y plane, return true if these points are a boomerang.

// A boomerang is a set of three points that are all distinct and not in a straight line.



// Example 1:

// Input: points = [[1,1],[2,3],[3,2]]
// Output: true
// Example 2:

// Input: points = [[1,1],[2,2],[3,3]]
// Output: false


// Constraints:

// points.length == 3
// points[i].length == 2
// 0 <= xi, yi <= 100
// 向量叉乘，不在一条直线上


bool isBoomerang(int** points, int pointsSize, int* pointsColSize){
    int v1[2] = {points[1][0] - points[0][0], points[1][1] - points[0][1]};
    int v2[2] = {points[2][0] - points[1][0], points[2][1] - points[1][1]};
    return v1[0] * v2[1] - v1[1] * v2[0] != 0;
}
