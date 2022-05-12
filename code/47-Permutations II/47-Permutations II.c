
/*Permutations II 

Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.


Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10

*/



/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int *vis;

int cmp(void* a, void* b) {
    return *(int*)a - *(int*)b;
}

void backtrack(int* nums, int numSize, int** ans, int* ansSize, int idx, int* perm) {
    if (idx == numSize) {
        int *tmp = malloc(sizeof(int) * numSize);
        memcpy(tmp, perm, sizeof(int) * numSize);
        ans[(*ansSize) ++] = tmp;
        return;
    }
    for (int i = 0; i < numSize; i ++) {
        if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
            continue;
        }
        perm[idx] = nums[i];
        vis[i] = 1;
        backtrack(nums, numSize, ans, ansSize, idx + 1, perm);
        vis[i] = 0;
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int** ans = malloc(sizeof(int*) * 2001);
    int* perm = malloc(sizeof(int) * 2001);
    vis = malloc(sizeof(int) * numsSize);
    memset(vis, 0, sizeof(int) * numsSize);
    qsort(nums, numsSize, sizeof(int), cmp);
    *returnSize = 0;
    backtrack(nums, numsSize, ans, returnSize, 0, perm);
    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    return ans;
}