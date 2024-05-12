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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)
            return result;

        deque<TreeNode*> q;
        
        q.push_back(root);
        
        while(!q.empty()){
            int cnt = q.size();
            vector<int>levelarray;
            for(int i = 0; i < cnt; i++){     
                TreeNode* temp = q.front();
                q.pop_front();
                levelarray.push_back(temp->val);
                if(temp->left != NULL){
                    q.push_back(temp->left);
                }
                if(temp->right != NULL){
                    q.push_back(temp->right);
                }
            }
            result.push_back(levelarray);
        }
        return result;
    }
};