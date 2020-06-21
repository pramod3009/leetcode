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
    TreeNode* start;
    bool found;
    void find(TreeNode* root, int x){
        if(not root){
            return;
        }
        if(root->val==x){
            found = true;
            start = root;
            return;
        }
        if(not found)
            find(root->left, x);
        if(not found)
            find(root->right,x);
    }
    
    void count(TreeNode* root,int &c){
        if(not root){
            return;
        }
        c++;
        count(root->left,c);
        count(root->right,c);
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        if(not root){
            return false;
        }
        found = false;
        find(root, x);
        int left = 0;
        int right = 0;
        count(start->left,left);
        count(start->right,right);
        int parent = n - (left+right+1);
        return  parent > left+right+1 || left > parent+right+1 || right > parent+left+1;
    }
};