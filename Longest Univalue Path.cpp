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
    int globalmax = 0;
    int helper(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = helper(root->left);
        int right = helper(root->right);
        int a=0,b=0;
        if(root->left and root->left->val==root->val){
            a=left+1;
        }
        if(root->right and root->right->val==root->val){
            b = right+1;
        }
        globalmax = std::max(globalmax, a + b);
        return std::max(a, b);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(not root){
            return 0;
        }
        helper(root);
        return globalmax;
    }
};