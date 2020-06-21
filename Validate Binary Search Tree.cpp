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
    void helpers(TreeNode* root, vector<int>&nums){
        if(root){
            helpers(root->left,nums);
            nums.push_back(root->val);
            helpers(root->right,nums);
        }
    }
    bool isValidBST(TreeNode* root) {
       vector<int> nums;
       helpers(root,nums);
       for(int i=1;i<nums.size();i++){
           if(nums[i]<=nums[i-1]){
               return false;
           }
       } 
      return true;  
    }
};