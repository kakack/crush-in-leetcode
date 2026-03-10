/*
LeetCode 31 - Next Permutation

解题步骤（自动整理）
1. 定义状态（dp[i] 或 dp[i][j]）来表示子问题的最优解/可行性
2. 写出状态转移方程，并处理边界初始化
3. 按依赖顺序递推（必要时滚动数组优化空间），得到最终答案
*/
/*
Next Permutation
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

他喵的早这么说不就可以了么

http://www.cnblogs.com/dragonpig/archive/2010/01/21/1653680.html

http://fisherlei.blogspot.com/2012/12/leetcode-next-permutation.html
*/

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int i,j,len=num.size();
	//bool flg=true;

	for (i=len-2;i>=0;i--) {
		if(num[i+1]>num[i]){
		//	flg=false;
			for (j=len-1;j>=i;j--) {
				if(num[j]>num[i])
				  break;
			}
			swap(num[i],num[j]);
			reverse(num.begin()+i+1,num.end());
			return ;
		}
    }
    reverse(num.begin(),num.end());
	return ;
    }
};
