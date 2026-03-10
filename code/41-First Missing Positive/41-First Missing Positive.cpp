/*
LeetCode 41 - First Missing Positive

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
/*
First Missing Positive

Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

*/


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i ++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for (int i = 0; i < n; i ++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};

// class Solution {
// public:
//     int firstMissingPositive(int A[], int n) {
//         int i =0, max=0,j=0;
//      int flag=0;
//      int missingPositive=0;
//      for(i=0;i<n;i++)
//      {
//          if(A[i]>max)
//              max = A[i];
//      }
//      if(max==1)
//          return 2;
//      for(i=1;i<max;i++)
//      {
//          for(j=0;j<n;j++)
//              {
//                  flag=0;
//                 if(A[j]==i)
//                     {
//                     flag=1;
//                     break;
//                     }
//              }
//          if(flag!=1)
//              return i;

//      }

//      return max+1;

//     }
// };
