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
    void helper(TreeNode* root, int dir, int localmax){
        if(root){
            globalmax = std::max(globalmax,localmax);
            if(dir==0){
                helper(root->left, 1, localmax+1);
                helper(root->right, 0, 1);
            } else {
                helper(root->left, 1, 1);
                helper(root->right, 0, localmax+1);
            }
        }
    }
    int longestZigZag(TreeNode* root) {
        if(not root or not (root->left or root->right)){
            return 0;
        }
        helper(root->left, 1, 1);
        helper(root->right, 0, 1);
        return globalmax;
    }
}; 