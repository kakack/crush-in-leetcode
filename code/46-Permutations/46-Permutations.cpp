/*Permutations
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.

用一个visit的向量来保存这个值有没有被访问过，只有当访问过所有值之后才把临时vector塞入res里，总体思路是递归
*/

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        
        vector<vector<int> > res;
        vector<int> solution;
        
        if(num.size()==0)
          return res;
           vector<int> visit(num.size(), 0);
        
        generate(num, 0, visit, solution, res);
        return res;
    }
    
 private:
    void generate(vector<int> &num, int step, vector<int> &visit, vector<int> &solution, vector<vector<int> > &res){
        if(step==num.size())//满了
         {
             res.push_back(solution);
             return ;
         }
         
         for(int i =0; i< num.size(); i++){
             {
                 if(visit[i]==0){
                     visit[i]=1;
                     solution.push_back(num[i]);
                     generate(num,step+1,visit,solution,res);
                     solution.pop_back();
                     visit[i]=0;
                 }
             }
         }
    } 
};


class Solution {
    vector<vector<int>> res;
    void backtrack(int first, vector<int>& nums) {
        int n = nums.size();
        if (first == n) {
            res.push_back(nums);
        } else {
            for (int i = first; i < n; i ++) {
                swap(nums[first], nums[i]);
                backtrack(first + 1, nums);
                swap(nums[first], nums[i]);
            }
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(0, nums);
        return res;
    }
};