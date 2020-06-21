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
    int helper(TreeNode* root, int sum){
        int count = 0;
        if(root->val==sum){
            count++;
        }
        if(root->left){
            count+=helper(root->left,sum - root->val);
        }
        if(root->right){
            count+=helper(root->right,sum - root->val);
        }
        return count;
    }
    int pathSum(TreeNode* root, int sum) {
        if(not root)
            return 0;
        return helper(root,sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
    }
};