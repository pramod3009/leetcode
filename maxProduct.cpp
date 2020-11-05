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
    long totalsum = 0;
    long result = INT_MIN;
    int mod = 1000000007;
    void calculate_total_sum(TreeNode* root){
        if(root){
            totalsum =  (totalsum + root->val) ;
            calculate_total_sum(root->left);
            calculate_total_sum(root->right);
        }
    }
    long helper(TreeNode* root){
        if(!root){
            return 0;
        }
        long left = helper(root->left);
        long right = helper(root->right);
        
        long templeft = ((totalsum - left)* left);
        long tempright = ((totalsum - right) * right);
        
        result = max(max(result, templeft), tempright);
        return (left + right + root->val); 
    }
    int maxProduct(TreeNode* root) {
        calculate_total_sum(root);
        helper(root);
        return result % mod;
    }
};
