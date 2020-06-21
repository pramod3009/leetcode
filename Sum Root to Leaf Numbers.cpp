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
    void helper(TreeNode* root,vector<string>&nums,string &s){
       
         s = s + to_string(root->val);
         if(not root->left && not root->right){
             cout<<s<<endl;
             nums.push_back(s);
             s.pop_back();
             return;
         }
         if (root->left){helper(root->left,nums,s);}
         if (root->right){helper(root->right,nums,s);}
         s.pop_back();     
    }
    int sumNumbers(TreeNode* root) {
        if(not root){
            return 0;
        }
        vector<string> nums;
        string s="";
        helper(root,nums,s);
        int result = 0;
        for(int i=0;i<nums.size();i++){
            result+=stoi(nums[i]);
        }
        return result;
    }
};