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
    int minDiff;
    TreeNode *prev;
    void helper(TreeNode *root){
        if(root){
           helper(root->left);
            if(prev!=NULL){
                minDiff= std::min(root->val - prev->val, minDiff);
            }
            prev = root;
            helper(root->right);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        prev = NULL;
        minDiff = INT_MAX;
        helper(root);
        return minDiff;
    }
};