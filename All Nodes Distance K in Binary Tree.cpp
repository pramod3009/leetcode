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
    map<TreeNode*,TreeNode*> nodeP;
    vector<int> result;
    
    void dfs(TreeNode* node, TreeNode* parent){
        if(node){
            nodeP[node] = parent;
            dfs(node->left, node);
            dfs(node->right, node);
        }
    }
    
    void bfs(TreeNode* target, int k){
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        while(not q.empty() and k){
            int size = q.size();
            for(int i = 0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                visited.insert(node);
                if(node->left and visited.find(node->left)==visited.end()){
                    q.push(node->left);
                }
                if(node->right and visited.find(node->right)==visited.end()){
                    q.push(node->right);
                }
                if(nodeP.find(node)!=nodeP.end() and nodeP[node] and visited.find(nodeP[node])==visited.end()){
                    q.push(nodeP[node]);
                }
            }
            k--;
        }
        while(not q.empty()){
            TreeNode* node = q.front();
            q.pop();
            result.push_back(node->val);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        
        if(not root or not target){
            return result;
        }
        
        dfs(root,NULL);
        bfs(target, K);
        return result;
    }
};