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
    int postorderindex;
    int findindex(int key, int start, int end, vector<int>& inorder){
        for(int i = start;i<=end;i++){
            if(key==inorder[i]){
                return i;
            }
        }
        return -1;
    }
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int inorderstart, int                              inorderend) {
        if(inorderstart > inorderend){
            return NULL;
        }
        TreeNode* node = new TreeNode(postorder[postorderindex--]);
        if(inorderstart==inorderend){
            return node;
        }
        int index = findindex(node->val, inorderstart, inorderend, inorder);
        node->right = helper(inorder,postorder,index+1,inorderend);
        node->left = helper(inorder,postorder,inorderstart,index - 1);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(not inorder.size()){
            return NULL;
        }
        postorderindex = inorder.size()-1;
        return helper(inorder,postorder,0,inorder.size()-1);
        
    }
};