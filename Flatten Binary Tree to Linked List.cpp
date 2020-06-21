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
    TreeNode* helper(TreeNode* root){
        if(root){
            TreeNode *left = helper(root->left);
            TreeNode *right = helper(root->right);
           
            if(left){
                TreeNode* temp = left;
                while(temp and temp->right){
                    temp = temp->right;
                }
                temp->right = root->right;
                root->right = root->left;
                root->left = NULL;
               
            }
             return root;
        }
        return NULL;
    }
    void flatten(TreeNode* root) {
        helper(root);
        
    }
};