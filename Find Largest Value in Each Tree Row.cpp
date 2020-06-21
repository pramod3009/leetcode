#include <queue>
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
    void bfs(vector<int>& result, TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(not q.empty()){
            int size = q.size();
            int maxnum = INT_MIN;
            while(size--){
                 TreeNode* node = q.front();
                 q.pop();
                 maxnum = max(maxnum, node->val); 
                 if(node->left){
                     q.push(node->left);
                 }
                 if(node->right){
                     q.push(node->right);
                 }
            }
           result.push_back(maxnum);   
            
        }
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if(not root){
            return result;
        }
        bfs( result,root);
        return result;
    }
};