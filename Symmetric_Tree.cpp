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
    bool isSymmetricCheck(TreeNode* root1, TreeNode* root2){
        if(!root1 and !root2)
            return true;
        if((!root1 and root2) or (root1 and !root2))
            return false;
        if(root1->val == root2->val){
            return isSymmetricCheck(root1->left, root2->right) && isSymmetricCheck(root1->right, root2->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return isSymmetricCheck(root->left,root->right);
    }
};