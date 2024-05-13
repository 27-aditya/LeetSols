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
    void getc(TreeNode* root, int& cnt, int max){
        if(root == NULL)
            return;
        if(root->val >= max){
            cnt++;
            max = root->val;
        }
        getc(root->left, cnt, max);
        getc(root->right, cnt, max);
    }
public:
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        int max = root->val;
        getc(root, cnt, max);
        return cnt;   
    }
};