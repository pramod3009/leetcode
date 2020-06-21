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
    TreeNode* construct(vector<int>& nums, int start, int end){
        if(start > end){
            return NULL;
        }
        int maxindex = max_element(nums.begin() + start,nums.begin() + end +1) - nums.begin();
        TreeNode* root = new TreeNode(nums[maxindex]);
        root->left = construct(nums,start,maxindex - 1);
        root->right = construct(nums,maxindex + 1, end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size()-1);
    }
};