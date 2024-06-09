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
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return symmetry(root->left, root->right);
    }
private:
    bool symmetry(TreeNode* one, TreeNode* two){
        if(!one && !two)
            return true;
        if(!one || !two)
            return false;
        return (one->val == two->val) && symmetry(one->left, two->right) && symmetry(one->right, two->left); 
    }
};