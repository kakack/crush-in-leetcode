/*
In an infinite binary tree where every node has two children, the nodes are labelled in row order.

In the odd numbered rows (ie., the first, third, fifth,...), the labelling is left to right, while in the even numbered rows (second, fourth, sixth,...), the labelling is right to left.



Given the label of a node in this tree, return the labels in the path from the root of the tree to the node with that label.



Example 1:

Input: label = 14
Output: [1,3,4,14]
Example 2:

Input: label = 26
Output: [1,2,6,10,26]


Constraints:

1 <= label <= 10^6
*/

class Solution {
public:
    vector<int> ans{1};

    void dfs(int label, int k) {
        if (k == 1) {
            return;
        }
        int tmp = label - (1 << (k - 1));
        tmp >>= 1;
        tmp = (1 << (k - 1)) - tmp - 1;
        dfs(tmp, k - 1);
        ans.push_back(label);
    }

    vector<int> pathInZigZagTree(int label) {
        int k = 0, tmp = label;
        while (tmp) {
            tmp >>= 1;
            k++;
        }
        dfs(label, k);
        return ans;
    }
};