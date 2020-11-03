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
    unordered_map<TreeNode*, TreeNode*> ctop;
    vector<TreeNode*> leaves;
    int count = 0;
    unordered_set<TreeNode*> s;
    
    void populateparent(TreeNode* child, TreeNode* parent){
        if(!child){
            return;
        }
        ctop[child] = parent;
        if(!child->left and !child->right){
            leaves.push_back(child);        
            return;
        }
        populateparent(child->left, child);
        populateparent(child->right, child);
    }
    
    void dfs(TreeNode* leaf,TreeNode* originalleaf, int d){
        
        if(s.find(leaf) != s.end() or d < 0){
            return;
        }
        s.insert(leaf);
        if(d >= 0 and !leaf->right and !leaf->left and leaf != originalleaf){
            cout<<leaf->val<<endl;
            count++;
            return;
        }
        if(leaf->left){
            dfs(leaf->left, originalleaf, d - 1);
        }
        if(leaf->right){
            dfs(leaf->right, originalleaf, d - 1);
        }
        if(ctop[leaf]){
            dfs(ctop[leaf], originalleaf, d - 1);
        }
        
    }
    
    int countPairs(TreeNode* root, int distance) {
        populateparent(root,NULL);
        for(const auto leaf : leaves){
            dfs(leaf,leaf, distance);
            s.clear();
        }
        return count/2;
    }
};
