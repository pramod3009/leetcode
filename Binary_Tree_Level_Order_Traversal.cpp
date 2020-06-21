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
    vector<vector<int>> levelOrder(TreeNode* root) {
       
        return bfs(root);     
    }
    vector<vector<int>> bfs(TreeNode* root){
        std::vector<vector<int>> result;
        if (!root)
            return result;
        std::queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()){
            int qsize = queue.size();
            std::vector<int> temp;
            for(int i=0;i<qsize;i++){
                TreeNode* node = queue.front();
                queue.pop();
                temp.push_back(node->val);
                if(node->left)
                    queue.push(node->left);
                if(node->right)
                    queue.push(node->right);
                    
            }
            result.push_back(temp);
        }
      return result;  
    }
};