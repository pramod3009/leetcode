/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    TreeNode* root;
    unordered_set<int> s;
    void recover(TreeNode* node,TreeNode* parent,int left){
        if(not node){
            return;
        }
        if(left){
            node->val = parent->val*2 + 1;
        }else{
            node->val = parent->val*2 + 2;
        }
        s.insert(node->val);
        recover(node->left,node,1);
        recover(node->right,node,0);
    }
    FindElements(TreeNode* root):root(root) {
        if(not root){
            return;
        }
        root->val = 0;
        s.insert(0);
        recover(root->left,root,1);
        recover(root->right,root,0);
    }
    
    bool find(int target) {
        if(s.find(target)!=s.end()){
            return true;
        }else{
            return false;
        }
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */