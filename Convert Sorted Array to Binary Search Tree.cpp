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
    TreeNode* helper(vector<int>& nums,int left,int right){
        if(left > right){
            return NULL;
        }
        if(left == right){
            TreeNode* temp = new TreeNode(nums[left]);
            return temp;
        }
        int mid = (left + right)/2;
        TreeNode *temp = new TreeNode(nums[mid]);
        temp->left = helper(nums, left, mid - 1);
        temp->right = helper(nums,mid+1,right);
        return temp;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (not nums.size()){
            return NULL;
        }
        return helper(nums,0,nums.size()-1);
    }
};