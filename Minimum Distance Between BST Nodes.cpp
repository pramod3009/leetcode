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
    int min = INT_MAX;
    int prev = INT_MIN;
    void helper(TreeNode* root){
        if(root){
            helper(root->left);
            if(prev!=INT_MIN){
                min = std::min(min, root->val - prev);
            }
            prev = root->val;
            helper(root->right);
        }
    }
    int minDiffInBST(TreeNode* root) {
        if(not root){
            return 0;
        }
        helper(root);
        return min;
    }
};