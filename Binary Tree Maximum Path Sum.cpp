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
    int helper(TreeNode* root, int &maxsum){
        if(not root){
            return 0;
        }
        int left = max(0,helper(root->left,maxsum));
        int right = max(0,helper(root->right,maxsum));
        maxsum = max(maxsum, left+right+root->val);
                
        return max(left,right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        helper(root,maxsum);
        return maxsum;
    }
};