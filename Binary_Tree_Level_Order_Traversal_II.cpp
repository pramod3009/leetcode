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
    vector<vector<int>> bfs(vector<vector<int>>& result, TreeNode*root){
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int qsize = q.size();
            vector<int> temp;
            for(int j = 0; j < qsize; j++){
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                    
            }
            result.insert(result.begin(),temp);
        }
        return result;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)
            return result;
        return bfs(result, root);
        
        
    }
};