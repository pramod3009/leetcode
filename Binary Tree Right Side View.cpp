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
    void helper(TreeNode* root, vector<int>&nums,int currlevel,int &level){
        if(root){
            if(currlevel>level){
                level = currlevel;
                nums.push_back(root->val);
            }
            helper(root->right,nums,currlevel+1,level);
            helper(root->left,nums,currlevel+1,level);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> nums;
        int level = 0;
        helper(root,nums,1,level);
        return nums;
    }
};