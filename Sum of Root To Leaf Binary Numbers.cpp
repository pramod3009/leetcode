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
    int result = 0;
    void helper(TreeNode* root, string number){
        if(root){
            number += to_string(root->val);
            if(!root->left and !root->right){
                int temp = stoi(number, 0, 2);
                result+=temp;
            }
            helper(root->left,number);
            helper(root->right,number);
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        if(not root){
            return 0;
        }
        helper(root,"");
        return result;
    }
};