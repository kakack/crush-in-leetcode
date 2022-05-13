/**Populating Next Right Pointers in Each Node II 
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

// Given a binary tree

// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.

 

// Example 1:


// Input: root = [1,2,3,4,5,null,7]
// Output: [1,#,2,3,#,4,5,7,#]
// Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
// Example 2:

// Input: root = []
// Output: []
 

// Constraints:

// The number of nodes in the tree is in the range [0, 6000].
// -100 <= Node.val <= 100
 

// Follow-up:

// You may only use constant extra space.
// The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.

class Solution {
public:
    void connect(TreeLinkNode *root) {
        //我日你先人真的需要广度优先搜索啊！妈的一点偷懒都不给啊！跟某一个按层遍历树的那个题一样，先撸出那个题的结论，然后把vector里的东西处理一下
        
        vector<vector<TreeLinkNode*> > nodes;
        if(root==NULL) return;
        
        travel(root, 1, nodes);
    //这里和我自己写的循环是两种一样的处理方式    
    //     for(auto level:nodes){
    //         for(auto iter=level.begin();iter!=prev(level.end());iter++){
    //             (*iter)->next=*next(iter);
    //         }
    //  //       (*prev(level.end()))->next = NULL;
    //     }
    
       for(int i=0;i<nodes.size();i++){
           for(int j=0;j<nodes[i].size()-1;j++){
               nodes[i][j]->next=nodes[i][j+1];
           }
       }
        
        
        
    }
    
    void travel(TreeLinkNode* root, int level, vector<vector<TreeLinkNode*> > &nodes){
        if(root==NULL) return;
        
        if(level>nodes.size())
          nodes.push_back(vector<TreeLinkNode*>());
          
         nodes[level-1].push_back(root);
         travel(root->left, level+1, nodes);
         travel(root->right, level+1, nodes);
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if (!root) {
            return nullptr;
        }
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            Node* last = nullptr;
            for (int i = 0; i < n; i ++) {
                Node* node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
                if (i != 0) {
                    last->next = node;
                }
                last = node;
            }
        }
        return root;
    }
};