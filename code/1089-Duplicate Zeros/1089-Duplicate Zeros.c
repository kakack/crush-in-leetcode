// Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.

// Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.

 

// Example 1:

// Input: arr = [1,0,2,3,0,4,5,0]
// Output: [1,0,0,2,3,0,0,4]
// Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
// Example 2:

// Input: arr = [1,2,3]
// Output: [1,2,3]
// Explanation: After calling your function, the input array is modified to: [1,2,3]
 

// Constraints:

// 1 <= arr.length <= 10^4
// 0 <= arr[i] <= 9



void duplicateZeros(int* arr, int arrSize){
    int j = arrSize - 1, top = 0, i = -1;
    while (top < arrSize) {
        i ++;
        if (arr[i] != 0) {
            top ++;
        } else {
            top += 2;
        }
    }
    if (top == arrSize + 1) {
        arr[j] = 0;
        j --;
        i --;
    }
    while (j >= 0) {
        arr[j] = arr[i];
        j --;
        if (! arr[i]) {
            arr[j] = arr[i];
            j --;
        }
        i --;
    }
}