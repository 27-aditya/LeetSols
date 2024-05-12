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
    void inorder(TreeNode* root, vector<int>& inorderv){
        if(root == NULL)
            return;
        inorder(root->left, inorderv);
        inorderv.push_back(root->val);
        inorder(root->right, inorderv);
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> inordera;
        inorder(root, inordera);
        int n = inordera.size();
        for(int i = 0; i < n-1; i++){
            if(inordera[i] >= inordera[i+1])
                return false;
        }
        return true;
    }
};