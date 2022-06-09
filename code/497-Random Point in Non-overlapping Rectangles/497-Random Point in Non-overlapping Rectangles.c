// You are given an array of non-overlapping axis-aligned rectangles rects where rects[i] = [ai, bi, xi, yi] indicates that (ai, bi) is the bottom-left corner point of the ith rectangle and (xi, yi) is the top-right corner point of the ith rectangle. Design an algorithm to pick a random integer point inside the space covered by one of the given rectangles. A point on the perimeter of a rectangle is included in the space covered by the rectangle.

// Any integer point inside the space covered by one of the given rectangles should be equally likely to be returned.

// Note that an integer point is a point that has integer coordinates.

// Implement the Solution class:

// Solution(int[][] rects) Initializes the object with the given rectangles rects.
// int[] pick() Returns a random integer point [u, v] inside the space covered by one of the given rectangles.
 

// Example 1:


// Input
// ["Solution", "pick", "pick", "pick", "pick", "pick"]
// [[[[-2, -2, 1, 1], [2, 2, 4, 6]]], [], [], [], [], []]
// Output
// [null, [1, -2], [1, -1], [-1, -2], [-2, -2], [0, 0]]

// Explanation
// Solution solution = new Solution([[-2, -2, 1, 1], [2, 2, 4, 6]]);
// solution.pick(); // return [1, -2]
// solution.pick(); // return [1, -1]
// solution.pick(); // return [-1, -2]
// solution.pick(); // return [-2, -2]
// solution.pick(); // return [0, 0]
 

// Constraints:

// 1 <= rects.length <= 100
// rects[i].length == 4
// -10^9 <= ai < xi <= 10^9
// -10^9 <= bi < yi <= 10^9
// xi - ai <= 2000
// yi - bi <= 2000
// All the rectangles do not overlap.
// At most 10^4 calls will be made to pick.




typedef struct {
    int *arr;
    int **rects;
    int rectsSize;
} Solution;


Solution* solutionCreate(int** rects, int rectsSize, int* rectsColSize) {
    srand(time(NULL));
    Solution *obj  = (Solution*)malloc(sizeof(Solution));
    obj->rects = rects;
    obj->rectsSize = rectsSize;
    obj->arr = (int *)malloc(sizeof(int) * (rectsSize + 1));
    memset(obj->arr, 0, sizeof(int) * (rectsSize + 1));
    for (int i = 0; i < rectsSize; i++) {
        obj->arr[i + 1] = obj->arr[i] + (rects[i][2] - rects[i][0] + 1) * \
                                        (rects[i][3] - rects[i][1] + 1);
    }
    return obj;
}

int* solutionPick(Solution* obj, int* retSize) {
    int k = rand() % obj->arr[obj->rectsSize];
    int left = 0, right = obj->rectsSize;
    int rectIndex = 0;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (obj->arr[mid] > k) {
            rectIndex = mid - 1;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    k = k - obj->arr[rectIndex];
    int a = obj->rects[rectIndex][0], b = obj->rects[rectIndex][1];
    int y = obj->rects[rectIndex][3];
    int col = y - b + 1;
    int da = k / col;
    int db = k - col * da;
    int *res = (int *)malloc(sizeof(int) * 2);
    res[0] = a + da;
    res[1] = b + db;
    *retSize = 2;
    return res;
}

void solutionFree(Solution* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(rects, rectsSize, rectsColSize);
 * int* param_1 = solutionPick(obj, retSize);
 
 * solutionFree(obj);
*/