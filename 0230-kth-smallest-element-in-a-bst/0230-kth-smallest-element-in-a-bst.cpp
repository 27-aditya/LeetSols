/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private: 
    void inorder(TreeNode* root, vector<int>& vec){
        if(root == NULL)
            return;
    
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vinorder;
        inorder(root, vinorder);
        return vinorder[k-1];
    }
};