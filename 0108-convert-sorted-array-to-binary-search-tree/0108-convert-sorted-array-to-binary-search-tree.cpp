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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        TreeNode* root = buildtree(nums, 0, n-1);
        return root;
    }
private:
    TreeNode* buildtree(vector<int>&nums, int start, int end){
        if(start > end)
            return NULL;
        int index = (start+end)/2;
        TreeNode* root = new TreeNode(nums[index]);
        root->left = buildtree(nums, start, index-1);
        root->right = buildtree(nums, index+1, end);
        return root;
    }
};