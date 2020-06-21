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
    map<TreeNode*,int> m;
    int rob(TreeNode* root) {
        if(not root){
            return 0;
        }
        if(m.find(root)!=m.end()){
            return m[root];
        }
        int val = 0;
        if(root->left){
            val+=rob(root->left->left)+rob(root->left->right);
        }
        if(root->right){
            val+=rob(root->right->left) + rob(root->right->right);
        }
        m[root] = max(root->val + val,rob(root->left)+rob(root->right));
        return m[root];
    }
};