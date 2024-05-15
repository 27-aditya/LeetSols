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
    int dfs(TreeNode* root, int& maxSum){
        if(root == NULL)
            return 0;

        int left = max(dfs(root->left, maxSum), 0);
        int right = max(dfs(root->right, maxSum), 0);

        int currMax = root->val+left+right;
        maxSum = max(currMax, maxSum);

        return root->val + max(left, right);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }
};