
/*Permutations II 

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > result;
        unordered_map<int, int> exist;
        
        if(num.size() == 0)
          return result;
        
        if(num.size() == 1){
            
            result.push_back(num);
            return result;
        }
        
        
        //DFS
        
        int length = num.size();
        
        for(int i=length-1;i>=0;i--){
            vector<vector<int> > nextPer;
            vector<int> temp(num);
            int curNum = num[i];
            if(exist.find(curNum) != exist.end()) {
                continue;
            }
            
            else {
                exist[curNum] = 1;
            }
            
            temp.erase(temp.begin() + i);
            nextPer = permuteUnique(temp);//这条好屌, 从temp中获取所有不重复的permution
            for(int j = 0;j<nextPer.size();j++){
                nextPer[j].push_back(curNum);
                vector<int> temp_result = nextPer[j];
                result.push_back(temp_result);
            }
         }
         
         return result;
    }
};


class Solution {
    vector<int> vis;

public:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, int idx, vector<int>& perm) {
        if (idx == nums.size()) {
            ans.emplace_back(perm);
            return;
        }
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
                continue;
            }
            perm.emplace_back(nums[i]);
            vis[i] = 1;
            backtrack(nums, ans, idx + 1, perm);
            vis[i] = 0;
            perm.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> perm;
        vis.resize(nums.size());
        sort(nums.begin(), nums.end());
        backtrack(nums, ans, 0, perm);
        return ans;
    }
};
