/*
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

Return the maximum number of envelopes can you Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.



Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Example 2:

Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1


Constraints:

1 <= envelopes.length <= 5000
envelopes[i].length == 2
1 <= wi, hi <= 10^4
*/

int cmp(int** a, int** b) {
    return (*a)[0] == (*b)[0] ? (*b)[1] - (*a)[1] : (*a)[0] - (*b)[0];
}

int lower_bound(int* arr, int arrSize, int val) {
    int left = 0, right = arrSize - 1;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (val < arr[mid]) {
            right = mid - 1;
        } else if (val > arr[mid]) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    if (arr[left] >= val) {
        return left;
    }
    return -1;
}

int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize) {
    if (envelopesSize == 0) {
        return 0;
    }

    qsort(envelopes, envelopesSize, sizeof(int*), cmp);

    int n = envelopesSize;
    int f[n], fSize = 0;
    f[fSize++] = envelopes[0][1];
    for (int i = 1; i < n; ++i) {
        int num = envelopes[i][1];
        if (num > f[fSize - 1]) {
            f[fSize++] = num;
        } else {
            f[lower_bound(f, fSize, num)] = num;
        }
    }
    return fSize;
}


// int cmp(const int ** a, const int ** b) {
//     if ((*a)[0] == (*b)[0]) {
//         return (*b)[1] - (*a)[1];
//     } else {
//         return  (*a)[0] - (*b)[0];
//     }
// }

// int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize){
//     if (envelopesSize == 0) {
//         return 0;
//     }

//     int n = envelopesSize;
//     qsort(envelopes, envelopesSize, sizeof(int *), cmp);
    
//     int f[n];
//     for (int i = 0; i < n; i ++) {
//         f[i] = 1;
//     }
//     int res = 1;
//     for (int i = 1; i < n; i ++) {
//         for (int j = 0; j < i; j ++) {
//             if (envelopes[j][1] < envelopes[i][1]) {
//                 f[i] = fmax(f[i], f[j] + 1);
//             }
//         }
//         res = fmax(res, f[i]);
//     }
//     return res;
// }