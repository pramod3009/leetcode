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
    int depth_x;
    int depth_y;
    TreeNode* parent_x;
    TreeNode* parent_y;
    void helper(TreeNode* root, TreeNode* parent, int x,int y, int depth){
        if(root){
            if(root->val == x){
                depth_x = depth;
                parent_x = parent;
            }
            if(root->val == y){
                depth_y = depth;
                parent_y = parent;
            }
            helper(root->left, root, x,y,depth+1);
            helper(root->right, root, x,y,depth+1);
        }
    }
    bool isCousins(TreeNode* root, int x, int y) {
        helper(root,NULL, x, y, 0);
        return depth_x==depth_y and parent_x!=parent_y;
    }
};