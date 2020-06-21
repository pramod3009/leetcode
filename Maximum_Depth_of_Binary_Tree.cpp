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
    void helper(TreeNode* root, int cdepth, int &maxdepth){
        maxdepth = std::max(maxdepth, cdepth);
        if(root->left){
            helper(root->left, cdepth+1,maxdepth);
        }
        if(root->right){
            helper(root->right,cdepth+1,maxdepth);
        }
    }
    int maxDepth(TreeNode* root) {
        int maxdepth = INT_MIN;
        if (root){
            helper(root,1,maxdepth);
            return maxdepth;
        }
        return 0;
    }
};