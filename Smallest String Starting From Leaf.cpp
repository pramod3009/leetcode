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
    string result;
    void dfs(TreeNode* root, string s){
        if(not root){
            return;
        }
        if(not root->left and not root->right){
            char temp = char('a'+root->val);
            s.insert(0,1,temp);
            if(result==""){
                result = s;
            } else {
                result = min(result,s);
            }
            return;
        }
        char temp = char('a'+root->val);
        s.insert(0,1,temp);
        dfs(root->left, s);
        dfs(root->right, s);
    }
    string smallestFromLeaf(TreeNode* root) {
        if(not root){
            return result;
        }
        result = "";
        string s = "";
        cout<<char('a'+2);
        dfs(root,s);
        return result;
    }
};