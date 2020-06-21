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
    int helper(TreeNode* root,int &maxdiameter){
      if(not root){
          return 0;
      }
        int l = helper(root->left,maxdiameter);
        int r = helper(root->right,maxdiameter);
        maxdiameter = max(l+r,  maxdiameter);
        return max(l,r)+1;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxdiameter = INT_MIN;
        if(not root){
            return 0;
        }
        if(!root->left and !root->right){
            return 0;
        }
        if(root){
            helper(root,maxdiameter);
        }
        return (maxdiameter==INT_MIN)?0:maxdiameter;
        
    }
};