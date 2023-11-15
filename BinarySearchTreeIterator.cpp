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
class BSTIterator {
public:
    stack<TreeNode*> s;

    BSTIterator(TreeNode* root) {
        s.push(root);
        pushLeftMostNodesOnStack(root);
    }

    void pushLeftMostNodesOnStack(TreeNode* root) {
        while(root->left) {
            s.push(root->left);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* node = s.top();
        s.pop();
        if(node->right) {
            s.push(node->right);
            pushLeftMostNodesOnStack(node->right);
        }

        return node->val;
    }
    
    bool hasNext() {
        return not s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
