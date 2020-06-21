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
    int count = 0;
    
    void helper(TreeNode* root){
        if(not root){
            return;
        }
        count+=1;
        helper(root->left);
        helper(root->right);
    }
    int countNodes(TreeNode* root) {
        helper(root);
        return count;
    }
};