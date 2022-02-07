// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

// Example 1:

// Input: rowIndex = 3
// Output: [1,3,3,1]
// Example 2:

// Input: rowIndex = 0
// Output: [1]
// Example 3:

// Input: rowIndex = 1
// Output: [1,1]
 

// Constraints:

// 0 <= rowIndex <= 33
 

// Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?

// C^m_n = C^(m-1)_n * (n - m + 1)/m



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    int *res = malloc(sizeof(int) * (rowIndex + 1));
    *returnSize = rowIndex + 1;
    res[0] = 1;
    for (int i = 1; i <= rowIndex; i ++) {
        res[i] = 1LL * res[i - 1] * (rowIndex - i + 1) / i;
    }
    return res;
}