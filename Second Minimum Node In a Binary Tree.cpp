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
    int first = INT_MAX;
    long second = LONG_MAX;
    void dfs(TreeNode* root){
        if(root){
            if(first < root->val and root->val<second){
                second = root->val;
            } else if(root->val==first){
                dfs(root->left);
                dfs(root->right);
            }
        }
    }
    int findSecondMinimumValue(TreeNode* root) {
        first = root->val;
        
        dfs(root);
        return second==LONG_MAX?-1:second;
    }
};