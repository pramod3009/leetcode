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
    vector<double> result;
    void bfs(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            long long int sum = 0;
            for(int i = 0;i<size;i++){
                TreeNode* node =q.front();
                q.pop();
                sum+=node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            result.push_back(double(sum)/size);
        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        if(not root){
            return result;
        }
        bfs(root);
        return result;
    }
};