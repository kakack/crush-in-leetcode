// Given an array of points on the X-Y plane points where points[i] = [xi, yi], return the area of the largest triangle that can be formed by any three different points. Answers within 10-5 of the actual answer will be accepted.

 

// Example 1:


// Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
// Output: 2.00000
// Explanation: The five points are shown in the above figure. The red triangle is the largest.
// Example 2:

// Input: points = [[1,0],[0,0],[0,1]]
// Output: 0.50000
 

// Constraints:

// 3 <= points.length <= 50
// -50 <= xi, yi <= 50
// All the given points are unique.

double triangleArea(int x1, int y1, int x2, int y2, int x3, int y3) {
    return 0.5 * abs(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2);
}

double largestTriangleArea(int** points, int pointsSize, int* pointsColSize){
    double res = 0.0;
    for (int i = 0; i < pointsSize - 2; i ++) {
        for (int j = i + 1; j < pointsSize - 1; j ++) {
            for (int k = j + 1; k < pointsSize; k ++) {
                res = fmax(res, triangleArea(points[i][0], points[i][1], points[j][0], points[j][1], points[k][0], points[k][1]));
            }
        }
    }
    return res;
}