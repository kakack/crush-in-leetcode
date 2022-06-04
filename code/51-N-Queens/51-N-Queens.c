// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

// Example 1:


// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
// Example 2:

// Input: n = 1
// Output: [["Q"]]
 

// Constraints:

// 1 <= n <= 9

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int solutionsSize;

char** generateBoard(int* queens, int n) {
    char** board = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++) {
        board[i] = (char*)malloc(sizeof(char) * (n + 1));
        for (int j = 0; j < n; j++) board[i][j] = '.';
        board[i][queens[i]] = 'Q', board[i][n] = 0;
    }
    return board;
}

void backtrack(char*** solutions, int* queens, int n, int row, int* columns, int* diagonals1, int* diagonals2) {
    if (row == n) {
        char** board = generateBoard(queens, n);
        solutions[solutionsSize++] = board;
    } else {
        for (int i = 0; i < n; i++) {
            if (columns[i]) {
                continue;
            }
            int diagonal1 = row - i + n - 1;
            if (diagonals1[diagonal1]) {
                continue;
            }
            int diagonal2 = row + i;
            if (diagonals2[diagonal2]) {
                continue;
            }
            queens[row] = i;
            columns[i] = true;
            diagonals1[diagonal1] = true;
            diagonals2[diagonal2] = true;
            backtrack(solutions, queens, n, row + 1, columns, diagonals1, diagonals2);
            queens[row] = -1;
            columns[i] = false;
            diagonals1[diagonal1] = false;
            diagonals2[diagonal2] = false;
        }
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    char*** solutions = malloc(sizeof(char**) * 501);
    solutionsSize = 0;
    int queens[n];
    int columns[n];
    int diagonals1[n + n];
    int diagonals2[n + n];
    memset(queens, -1, sizeof(queens));
    memset(columns, 0, sizeof(columns));
    memset(diagonals1, 0, sizeof(diagonals1));
    memset(diagonals2, 0, sizeof(diagonals2));
    backtrack(solutions, queens, n, 0, columns, diagonals1, diagonals2);
    *returnSize = solutionsSize;
    *returnColumnSizes = malloc(sizeof(int*) * solutionsSize);
    for (int i = 0; i < solutionsSize; i++) {
        (*returnColumnSizes)[i] = n;
    }
    return solutions;
}
