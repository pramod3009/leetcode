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
    int answer;
    void helper(TreeNode* root, int treemax, int treemin){
        if(not root){
            return;
        }
        treemax = max(treemax,root->val);
        treemin = min(treemin,root->val);
        answer = max(answer, treemax - treemin);
        helper(root->left, treemax, treemin);
        helper(root->right, treemax, treemin);
    }
    int maxAncestorDiff(TreeNode* root) {
        helper(root, INT_MIN, INT_MAX);
        return answer;
    }
};