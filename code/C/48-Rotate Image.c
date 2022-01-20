/*
Rotate Image 
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

就是先按照副对角线对称交换，然后按照水平中线对称交换

因为恰好是90°的关系所以计算比较方便，可以展开成逆时针90°，那就先按照主对角线对称交换
*/

void swap(int* a, int* b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize - i; j ++) {
            swap(&(matrix[i][j]), &(matrix[matrixSize - j - 1][matrixSize - i - 1]));
            // 二维数组直接计算地址方法
            // swap(*(matrix + i) + j, *(matrix + matrixSize - j - 1) + matrixSize - i - 1);
        }
    }
    for (int i = 0; i < matrixSize / 2; i ++) {
        for (int j = 0; j < matrixSize; j ++) {
            swap(&(matrix[i][j]), &(matrix[matrixSize - i - 1][j]));
            // swap(*(matrix + i) + j, *(matrix + matrixSize - i - 1) + j);
        }
    }
}
