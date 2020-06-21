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
    int depth;
    int result;
    bool flag;
    void findDepth(TreeNode* root, int d){
        if(root){
            depth = std::max(depth, d);
            findDepth(root->left, d+1);
            findDepth(root->right, d+1);
        }
    }
    void leftMostValue(TreeNode* root, int d){
        if(root and depth==d){
            result = root->val;
            flag = true;
            return;
        }
        if(root){
            if(not flag)
                leftMostValue(root->left, d+1);
            if(not flag)
                leftMostValue(root->right, d+1);
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        findDepth(root,0);
        leftMostValue(root, 0);
        return result;
    }
};