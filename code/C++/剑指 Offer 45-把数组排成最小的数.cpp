// 输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

//  

// 示例 1:

// 输入: [10,2]
// 输出: "102"
// 示例 2:

// 输入: [3,30,34,5,9]
// 输出: "3033459"
//  

// 提示:

// 0 < nums.length <= 100
// 说明:

// 输出结果可能非常大，所以你需要返回一个字符串而不是整数
// 拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0


/*
    1.对数组进行排序，排序比较规则是两个元素不同顺序组成的字符串较大的交换到后面
    */ 
    
class Solution {
private:
    void quickSort(vector<string>& strs, int l, int r) {
        if (l >= r) {
            return;
        }
        int i = l, j = r;
        while (i < j) {
            while (strs[j] + strs[l] >= strs[l] + strs[j] && i < j) {
                j --;
            }
            while (strs[i] + strs[l] <= strs[l] + strs[i] &&i < j) {
                i ++;
            }
            swap(strs[i], strs[j]);
        }
        swap(strs[i], strs[l]);
        quickSort(strs, l, i - 1);
        quickSort(strs, i + 1, r);
    }
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        for (auto num : nums) {
            strs.push_back(to_string(num));
        }
        quickSort(strs, 0, strs.size() - 1);
        string res;
        for (auto s: strs) {
            res.append(s);
        }
        return res;
    }
};