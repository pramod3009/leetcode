/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int p ; 

int find(vector<int>& inorder , int val , int st , int en)
{
    int ind = -1;
    for(int i = st ; i<= en; ++i){
        if(inorder[i] == val){
            ind = i ; 
            break;
        }
    }
    return ind; 
}

TreeNode* solve(vector<int> &inorder , vector<int> &preorder , int i , int j )
{
    if(i > j ) return NULL;
    TreeNode* node = new TreeNode(preorder[p++]);
    if(i == j) return node; 
    int in = find(inorder , node->val , i , j); 
    node->left = solve(inorder , preorder , i , in - 1) ; 
    node->right = solve(inorder , preorder , in + 1 , j ) ; 
    return node; 
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        p = 0;
        if(inorder.empty() == true) return NULL;
        return solve(inorder , preorder , 0 , inorder.size() - 1); 
    }
};