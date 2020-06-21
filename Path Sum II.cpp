/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode*root,vector<vector<int>> &result, vector<int>&path,int sum){
        if(not root->left and not root->right and sum-root->val==0){
            path.push_back(root->val);
            result.push_back(path);
            path.pop_back();
            return;
        }
        cout<<root->val<<" "<<sum<<endl;
        path.push_back(root->val);
        if(root->left){
            helper(root->left,result,path,sum-root->val);
        }
        if(root->right){
            helper(root->right,result,path,sum-root->val);
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        if(not root){
            return result;
        }
        vector<int> path;
        helper(root,result,path,sum);
        return result;
    }
};