// You are given an array of people, people, which are the attributes of some people in a queue (not necessarily in order). Each people[i] = [hi, ki] represents the ith person of height hi with exactly ki other people in front who have a height greater than or equal to hi.

// Reconstruct and return the queue that is represented by the input array people. The returned queue should be formatted as an array queue, where queue[j] = [hj, kj] is the attributes of the jth person in the queue (queue[0] is the person at the front of the queue).

 

// Example 1:

// Input: people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
// Output: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
// Explanation:
// Person 0 has height 5 with no other people taller or the same height in front.
// Person 1 has height 7 with no other people taller or the same height in front.
// Person 2 has height 5 with two persons taller or the same height in front, which is person 0 and 1.
// Person 3 has height 6 with one person taller or the same height in front, which is person 1.
// Person 4 has height 4 with four people taller or the same height in front, which are people 0, 1, 2, and 3.
// Person 5 has height 7 with one person taller or the same height in front, which is person 1.
// Hence [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] is the reconstructed queue.
// Example 2:

// Input: people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
// Output: [[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]
 

// Constraints:

// 1 <= people.length <= 2000
// 0 <= hi <= 10^6
// 0 <= ki < people.length
// It is guaranteed that the queue can be reconstructed.

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void* _a, const void* _b) {
    int *a = *(int**)_a, *b = *(int**)_b;
    return a[0] == b[0] ? b[1] - a[1] : a[0] - b[0];
}

int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes){
    qsort(people, peopleSize, sizeof(int*), cmp);
    int ** res = (int**)malloc(sizeof(int*) * peopleSize);
    *returnSize = peopleSize;
    *returnColumnSizes = (int*)malloc(sizeof(int) * peopleSize);
    memset(*returnColumnSizes, 0, sizeof(int) * peopleSize);
    for (int i = 0; i < peopleSize; i ++) {
        int space = people[i][1] + 1;
        for (int j = 0; j < people; j ++) {
            if ((*returnColumnSizes)[j] == 0) {
                space --;
                if (!space) {
                    (*returnColumnSizes)[j] = 2;
                    res[j] = malloc(sizeof(int) * 2);
                    res[j][0] = people[i][0];
                    res[j][1] = people[i][1];
                    break;
                }
            }
        }
    }
    return res;
}