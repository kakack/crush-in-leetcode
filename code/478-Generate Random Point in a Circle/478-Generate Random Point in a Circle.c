/*
LeetCode 478 - Generate Random Point in a Circle

解题步骤（自动整理）
1. 定义状态（dp[i] 或 dp[i][j]）来表示子问题的最优解/可行性
2. 写出状态转移方程，并处理边界初始化
3. 按依赖顺序递推（必要时滚动数组优化空间），得到最终答案
*/

// Given the radius and the position of the center of a circle, implement the function randPoint which generates a uniform random point inside the circle.

// Implement the Solution class:

// Solution(double radius, double x_center, double y_center) initializes the object with the radius of the circle radius and the position of the center (x_center, y_center).
// randPoint() returns a random point inside the circle. A point on the circumference of the circle is considered to be in the circle. The answer is returned as an array [x, y].


// Example 1:

// Input
// ["Solution", "randPoint", "randPoint", "randPoint"]
// [[1.0, 0.0, 0.0], [], [], []]
// Output
// [null, [-0.02493, -0.38077], [0.82314, 0.38945], [0.36572, 0.17248]]

// Explanation
// Solution solution = new Solution(1.0, 0.0, 0.0);
// solution.randPoint(); // return [-0.02493, -0.38077]
// solution.randPoint(); // return [0.82314, 0.38945]
// solution.randPoint(); // return [0.36572, 0.17248]


// Constraints:

// 0 < radius <= 10^8
// -10^7 <= x_center, y_center <= 10^7
// At most 3 * 10^4 calls will be made to randPoint.

typedef struct {
    double radius;
    double x_center;
    double y_center;
} Solution;


Solution* solutionCreate(double radius, double x_center, double y_center) {
    srand((unsigned)time(NULL));
    Solution *obj = (Solution *)malloc(sizeof(Solution));
    obj->radius = radius;
    obj->x_center = x_center;
    obj->y_center = y_center;
    return obj;
}

double* solutionRandPoint(Solution* obj, int* retSize) {
    double r = obj->radius;
    double *res = (double *)malloc(sizeof(double) * 2);
    while (true) {
        double x = (double)rand() / RAND_MAX * (2 * r) - r;
        double y = (double)rand() / RAND_MAX * (2 * r) - r;
        if (x * x + y * y <= r * r) {
            res[0] = x + obj->x_center;
            res[1] = y + obj->y_center;
            *retSize = 2;
            return res;
        }
    }
}

void solutionFree(Solution* obj) {
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(radius, x_center, y_center);
 * double* param_1 = solutionRandPoint(obj, retSize);

 * solutionFree(obj);
*/
