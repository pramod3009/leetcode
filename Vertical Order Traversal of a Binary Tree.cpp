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
    map<int,map<int,set<int>>> m;
    vector<vector<int>> result;
    void helper(TreeNode* root, int x,int y){
        if(root){
            m[x][y].insert(root->val);
            
            helper(root->left,x - 1, y + 1);
            helper(root->right,x + 1, y +1);
            
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        helper(root, 0, 0);
        for(auto it1 : m){
            vector<int> temp;
            for(auto it2 : it1.second){
                for(auto it3:it2.second)
               temp.push_back(it3); 
            }
            result.push_back(temp);
        }
        return result;
    }
};