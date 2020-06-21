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
    string answer;
    void helper(TreeNode* root){
        if(root){
            answer+=std::to_string(root->val);
            if(root->left){
                answer+="(";
                helper(root->left);
                answer+=")";
            }
            if(!root->left and root->right){
                answer+="()";
            }
            if(root->right){
                answer+="(";
                helper(root->right);
                answer+=")";
            }
        }
    }
    string tree2str(TreeNode* t) {
        helper(t);
        return answer;
    }
};