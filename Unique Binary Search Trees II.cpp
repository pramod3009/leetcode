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
    vector<TreeNode*> generateTreesHelper(int start, int end){
        if(start>end){
            return vector<TreeNode*>(1,NULL);
        }
        vector<TreeNode*> res;
        for(int i = start; i <= end; i++){
            vector<TreeNode*> left = generateTreesHelper(start, i - 1);
            vector<TreeNode*> right = generateTreesHelper(i+1, end);
            for(int j = 0; j < left.size(); j++){
                for(int k = 0; k < right.size();k++){
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(not n){
            return vector<TreeNode*>();
        }
     return generateTreesHelper(1,n);   
    }
};