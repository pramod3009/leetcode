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
    int result;
    void helper(TreeNode* root, bool left_child){
        if(not root){
            return;
        }
        if(!root->left and !root->right and left_child){
            result+=root->val;
            return;
        }
        helper(root->left,true);
        helper(root->right,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(not root or (!root->left and !root->right)){
            return 0;
        }
        helper(root, false);
        return result;
    }
};