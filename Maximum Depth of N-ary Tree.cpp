/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int depth;
    void helper(Node* root, int ldepth){
        if(root){
            depth = std::max(depth, ldepth);
            for(int i = 0;i<root->children.size();i++){
                helper(root->children[i], ldepth+1);
            }
        }
    }
    int maxDepth(Node* root) {
        depth = 0;
        helper(root, 1);
        return depth;
    }
};