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
    void helper(TreeNode* root, int localdepth,int &depth){
        if(root){
            localdepth+=1;
            if(not root->left and not root->right){
                depth = std::min(depth,localdepth);
            }if(root->left){
                helper(root->left,localdepth,depth);
            } if(root->right){
                helper(root->right,localdepth,depth);
            }
        }
    }
    int minDepth(TreeNode* root) {
        if(not root){
            return 0;
        }
        int depth = INT_MAX;
        helper(root,0,depth);
        return depth;
    }
};