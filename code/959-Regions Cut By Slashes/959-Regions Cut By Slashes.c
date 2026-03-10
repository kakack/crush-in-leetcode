/*
LeetCode 959 - Regions Cut By Slashes

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
/*
In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a /, \, or blank space.  These characters divide the square into contiguous regions.

(Note that backslash characters are escaped, so a \ is represented as "\\".)

Return the number of regions.



Example 1:

Input:
[
  " /",
  "/ "
]
Output: 2
Explanation: The 2x2 grid is as follows:

Example 2:

Input:
[
  " /",
  "  "
]
Output: 1
Explanation: The 2x2 grid is as follows:

Example 3:

Input:
[
  "\\/",
  "/\\"
]
Output: 4
Explanation: (Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.)
The 2x2 grid is as follows:

Example 4:

Input:
[
  "/\\",
  "\\/"
]
Output: 5
Explanation: (Recall that because \ characters are escaped, "/\\" refers to /\, and "\\/" refers to \/.)
The 2x2 grid is as follows:

Example 5:

Input:
[
  "//",
  "/ "
]
Output: 3
Explanation: The 2x2 grid is as follows:



Note:

1 <= grid.length == grid[0].length <= 30
grid[i][j] is either '/', '\', or ' '.
*/

// 单元格内合并：【0123】，【03】和【12】，【01】和【23】
// 单元格间合并：【左上】，【左下】，【右上】，【右下】


int find(int * f, int x) {
  if (f[x] == x) {
    return x;
  }
  int fa = find(f, f[x]);
  f[x] = fa;
  return fa;
}

void unioned(int * f, int x, int y) {
  int fx = find(f, x);
  int fy = find(f, y);
  f[fx] = fy;
}

int regionsBySlashes(char ** grid, int gridSize){
  int count = 0;
  int n = gridSize;
  int *f = (int*)malloc(sizeof(int) * n * n * 4);
  for (int i = 0; i < n * n * 4; i ++) {
    f[i] = i;
  }
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < n; j ++) {
      int idx = i * n + j;
      if (i < n - 1) {
        int btm = idx + n;
        unioned(f, idx * 4 + 2, btm * 4);
      }
      if ( j < n - 1) {
        int right = idx + 1;
        unioned(f, idx * 4 + 1, right * 4 + 3);
      }
      if (grid[i][j] == '/') {
        unioned(f, idx * 4, idx * 4 + 3);
        unioned(f, idx * 4 + 1, idx * 4 + 2);
      } else if (grid[i][j] == '\\') {
        unioned(f, idx * 4, idx * 4 + 1);
        unioned(f, idx * 4 + 2, idx * 4 + 3);
      } else {
        unioned(f, idx * 4, idx * 4 + 1);
        unioned(f, idx * 4 + 1, idx * 4 + 2);
        unioned(f, idx * 4 + 2, idx * 4 + 3);
      }
    }
  }
  for (int i = 0; i < n * n * 4; i ++) {
    if (find(f, i) == i) {
      count ++;
    }
  }
  free(f);
  return count;
}
