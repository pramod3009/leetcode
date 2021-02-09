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
    string preorder(TreeNode *s, bool left){
        if(s == NULL){
            if(left){
                return "lnull";
            } else {
                return "rnull";
            }
        }
        return "#" + to_string(s->val) + " " + preorder(s->left, true) + " " + preorder(s->right, false);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        string t1 = preorder(s, true);
        string t2 = preorder(t, true);
        return t1.find(t2) != std::string::npos ? 1 : 0;
    }
};
