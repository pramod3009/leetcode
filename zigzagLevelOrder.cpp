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
    vector<vector<int>> result;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root){
            return result;
        }
        deque<TreeNode*> q;
        bool dir = false;
        q.push_back(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            while(size--){
                if(!dir){
                    TreeNode* num = q.front();
                    q.pop_front();
                    temp.push_back(num->val);
                    if(num->left){
                        q.push_back(num->left);
                    }
                    if(num->right){
                        q.push_back(num->right);
                    }
                } else {
                    TreeNode* num = q.back();
                    q.pop_back();
                    temp.push_back(num->val);
                    if(num->right){
                        q.push_front(num->right);
                    }
                    if(num->left){
                        q.push_front(num->left);
                    }
                }
            }
            dir = !dir;
            result.push_back(temp);
        }
        return result;
        
    }
};
