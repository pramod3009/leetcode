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
    void helper(TreeNode* root,int &count, int k, int &element){
        if(not root){
            return;
        }
        helper(root->left,count,k,element);
        count+=1;
        if(count==k){
            element = root->val;
        }
        helper(root->right,count,k,element);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int element = 0;
        helper(root, count, k,element);
        return element;
    }
};