// Given the root of an n-ary tree, return the postorder traversal of its nodes' values.

// Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

 

// Example 1:


// Input: root = [1,null,3,2,4,null,5,6]
// Output: [5,6,3,2,4,1]
// Example 2:


// Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
// Output: [2,6,14,11,7,3,12,8,4,13,9,10,5,1]
 

// Constraints:

// The number of nodes in the tree is in the range [0, 10^4].
// 0 <= Node.val <= 10^4
// The height of the n-ary tree is less than or equal to 1000.

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    // dfs
    void dfs(Node* node, vector<int>* res) {
        if (node != nullptr) {
            for (auto n: node->children) {
                dfs(n, res);
            }
            res->push_back(node->val);
        }
    }
    vector<int> postorder(Node* root) {
        vector<int> res;
        dfs(root, &res);
        return res;
    }

    // bfs
    vector<int> postorder(Node* root) {
        vector<int> res;
        stack<Node *> stk;
        if (root == nullptr){
            return res;
        }
        unordered_map<Node *, int> cnt;
        Node * node = root;
        while (!stk.empty() || node != nullptr) {
            while (node != nullptr) {
                stk.push(node);
                if (node->children.size() > 0) {
                    cnt[node] = 0;
                    node = node->children[0];
                } else {
                    node = nullptr;
                }
            }
            node = stk.top();
            int index = cnt.count(node) ? (cnt[node] + 1) : 0;
            if (index < node->children.size()) {
                cnt[node] = index;
                node = node->children[index];
            } else {
                res.push_back(node->val);
                stk.pop();
                cnt.erase(node);
                node = nullptr;
            }
        }
        return res;
    }
};