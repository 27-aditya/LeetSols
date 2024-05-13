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
    vector<int> gettheview(TreeNode* root, vector<int>& arr){
        if(root == NULL)
            return arr;
        
        deque<TreeNode*> q;
        
        q.push_back(root);
        int levelvalue = 0;
        arr.push_back(root->val);
        while(!q.empty()){
            int cnt = q.size();
            for(int i = 0; i < cnt; i++){     
                TreeNode* temp = q.front();
                q.pop_front();
                if(temp->left != NULL){
                    q.push_back(temp->left);
                }
                if(temp->right != NULL){
                    q.push_back(temp->right);
                }
                levelvalue = q.back()->val;
            }
            arr.push_back(levelvalue);
        }
        return arr;
               
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root == NULL)
            return result;
        result = gettheview(root, result);
        result.erase(result.begin()+result.size()-1);
        return result;
    }
};