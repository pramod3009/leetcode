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
    double result = -1;
    int lcount;
    int rcount;
    double maximumAverageSubtree(TreeNode* root) {
        dfs(root);
        return result;
        
    }
    
    pair<long, long> dfs(TreeNode* root){
        if(!root){
            return {0, 0};
        }
        auto leftp = dfs(root->left);
        auto rightp = dfs(root->right);
        long nodecount = leftp.second + rightp.second + 1;
        long sum = leftp.first + rightp.first + root->val;
        result = max(result, double(sum)/ nodecount);
        return {sum, nodecount};
    }
};
