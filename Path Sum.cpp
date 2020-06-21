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
    bool helper(TreeNode* root, int sum){
        if(root){
            sum-=root->val;
            cout<<root->val<<" "<<sum<<endl;
            if(not root->left and not root->right){
                if(sum==0)
                    return true;
                else
                    return false;
            }
                return helper(root->left,sum) || helper(root->right,sum);
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(not root){
            return false;
        }
        return helper(root,sum);
    }
};