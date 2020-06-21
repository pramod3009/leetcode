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
    int helper(TreeNode* root){
        if(not root){
            return 0;
        }
        return max(helper(root->left),helper(root->right)) + 1;
        
    }
    bool isBalanced(TreeNode* root) {
        if(not root){
            return 1;
        }
        int left = helper(root->left);
        int right = helper(root->right);
        return abs(left-right)<=1 and isBalanced(root->left) and isBalanced(root->right);
    }
};