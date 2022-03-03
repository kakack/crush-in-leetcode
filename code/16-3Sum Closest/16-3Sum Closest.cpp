
/*
3Sum Closest 
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

这题跟3Sum类似，其实不算多难的题目，只不过是涉及到vector一些巧妙的计算，关于容器和迭代器的内容确实需要好好看一下

然后这里的主要思路就是先排序，然后夹逼定理来做
*/

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(),num.end());
        int n = num.size();
        int best=1e7;

        auto update = [&](int cur) {
            if (abs(cur - target) < abs(best - target)) {
                best = cur;
            }
        };

        for (int i = 0; i < n; i ++) {
            if (i > 0 && num[i] == num[i - 1]) {
                continue;
            }
            int j = i + 1, k = n - 1; // j从前往后，k从后往前
            while (j < k) {
                int s = num[i] + num[j] + num[k];
                if (s == target) {
                    return target;
                }
                update(s);
                if (s > target) {
                    int k0 = k - 1; // k往左边走一点
                    while (j < k0 && num[k0] == num[k]) {
                        k0 --;
                    } // 从右往左去掉所有重复值
                    k = k0;
                } else {
                    int j0 = j + 1;
                    while (j0 < k && num[j] == num[j0]) {
                        j0 ++;
                    }
                    j = j0;
                }
            }
        }
        return best;
    }
};


class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int ans,min=INT_MAX;
        if(num.size()<3) return ans;
        sort(num.begin(),num.end());
        
        
          for (auto a = num.begin(); a != prev(num.end(), 2);a = upper_bound(a, prev(num.end(), 2), *a)){
              auto b = next(a);
              auto c = prev(num.end());
              
              while(b<c){
                  int sum=*a+*b+*c;
                  int distance=abs(target-sum);
                  
                  if(distance<min){
                      ans=sum;
                      min=distance;
                  }
                  
                  if(sum<target)
                     b++;
                  else
                     c--;
              }
          }
        return ans;
    }
};