// # According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

// # Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

// # 1. Any live cell with fewer than two live neighbors dies, as if caused by under-population.
// # 2. Any live cell with two or three live neighbors lives on to the next generation.
// # 3. Any live cell with more than three live neighbors dies, as if by over-population..
// # 4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
// # Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

// # Example:

// # Input:
// # [
// #   [0,1,0],
// #   [0,0,1],
// #   [1,1,1],
// #   [0,0,0]
// # ]
// # Output:
// # [
// #   [0,0,0],
// #   [1,0,1],
// #   [0,1,1],
// #   [0,1,0]
// # ]
// # Follow up:

// # Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
// # In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?


class Solution {
private:
    const int steps[3] = {-1, 0, 1};
    bool judge(vector<vector<int>> board, int i, int j, int row, int col) {
        int sum = 0;
        for (int step_i: steps) {
            for (int step_j: steps) {
                if (i + step_i >= 0 && i + step_i < row && j + step_j >= 0 && j + step_j < col) {
                    sum += board[i + step_i][j + step_j];
                } 
            }
        }
        sum -= board[i][j];
        if (board[i][j] == 1 && (sum == 2 || sum == 3)) {
            return true;
        } else if (board[i][j] == 0 && sum == 3) {
            return true;
        } else {
            return false;
        }
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size(), col = board[0].size();
        vector<vector<int>> board_(row, vector<int>(col, 0));
        for (int i = 0; i < row; i ++) {
            for (int j  = 0; j < col; j ++) {
                board_[i][j] = board[i][j];
            }
        }
        for (int i = 0; i < row; i ++) {
            for (int j  = 0; j < col; j ++) {
                if (judge(board_, i, j, row, col)) {
                    board[i][j] = 1;
                } else {
                    board[i][j] = 0;
                }
            }
        }
    }
};