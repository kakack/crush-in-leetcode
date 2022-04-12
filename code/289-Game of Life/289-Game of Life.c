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

const int steps[3] = {-1, 0, 1};
bool judge(int** board, int i, int j, int row, int col) {
    int sum = 0;
    for (int i_ = 0; i_ < 3; i_ ++) {
        for (int j_ = 0; j_ < 3; j_ ++) {
            int ni = i + steps[i_], nj = j + steps[j_];
            if (ni >= 0 && ni < row && nj >= 0 && nj < col) {
                sum += board[ni][nj];
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
void gameOfLife(int** board, int boardSize, int* boardColSize){
    int row = boardSize, col = boardColSize[0];
    int** board_ = (int**)malloc(sizeof(int*) * row);
    for (int i = 0; i < row; i ++) {
        board_[i] = malloc(sizeof(int) * col);
        for (int j = 0; j < col; j ++) {
            board_[i][j] = board[i][j];
        }
    }
    for (int i = 0; i < row; i ++) {
        for (int j = 0; j < col; j ++) {
            if (judge(board_, i, j, row, col)) {
                board[i][j] = 1;
            } else {
                board[i][j] = 0;
            }
        }
    }
}