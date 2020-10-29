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
    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        return 1 + max(height(root->left), height(root->right));
    }
    TreeNode* lcs(TreeNode* root, int h){
        if(!root or h==1){
            return root;
        }
        TreeNode* left = lcs(root->left, h - 1);
        TreeNode* right = lcs(root->right, h - 1);
        if(left and right){
            return root;
        }
        return left ? left : right;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int h = height(root);
        return lcs(root, h);
    }
};
