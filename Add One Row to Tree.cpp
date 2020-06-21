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
    void helper(TreeNode* root, int v, int d,int current_depth){
        if(root){
            if(current_depth==d-1){
                TreeNode* left_child = new TreeNode(v, root->left, NULL);
                TreeNode* right_child = new TreeNode(v, NULL, root->right);
                root->left = left_child;
                root->right = right_child;
                return;
            }
            helper(root->left, v, d, current_depth+1);
            helper(root->right, v, d, current_depth+1);
        }
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        
        if(!root){
            return NULL;
        }
        if(d==1){
            return new TreeNode(v,root,NULL);
        }
        helper(root, v, d, 1);
        return root;
        
    }
};
