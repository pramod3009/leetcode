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
    vector<string> result;
    void dfs(TreeNode* root,string s){
        if(not root){
            return;
        }
        if(not root->left and not root->right){
            s = s + to_string(root->val);
            result.push_back(s);
            return;
        }
        s = s + to_string(root->val)+"->";
        dfs(root->left,s);
        dfs(root->right,s);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(not root){
            return result;
        }
        string s = "";
        dfs(root,s);
        return result;
    }
};