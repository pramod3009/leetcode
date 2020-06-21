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
    int bfs(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        int maxWidth = 1;
        int lastval = 0;
        while(!q.empty()){
            int size = q.size();
            int head = q.front()->val;
            for(int  i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    node->left->val = 2*(node->val - head) + 1;
                    lastval = node->left->val;
                    q.push(node->left);
                }
                if(node->right){
                    node->right->val = 2*(node->val - head) + 2;
                    lastval = node->right->val;
                    q.push(node->right);
                }
            }
            if(!q.empty()){
                maxWidth = std::max(maxWidth, lastval - q.front()->val + 1);
            }
        }
        return maxWidth;
    }
    int widthOfBinaryTree(TreeNode* root) {
        if(not root){
            return 0;
        }
        return bfs(root);
    }
};