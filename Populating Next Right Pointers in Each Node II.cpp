/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void bfs(Node* root){
        if(not root){
            return ;
        }
        queue<Node*> tree_queue;
        tree_queue.push(root);
        
        while(not tree_queue.empty()){
            int size = tree_queue.size();
            for(int i = 0; i < size-1; i++){
                Node* node = tree_queue.front();
                tree_queue.pop();
                node->next = tree_queue.front();
                if(node->left){
                    tree_queue.push(node->left);
                }
                if(node->right){
                    tree_queue.push(node->right);
                }
            }
            Node * node = tree_queue.front();
            tree_queue.pop();
            node->next = NULL;
            if(node->left){
                    tree_queue.push(node->left);
                }
                if(node->right){
                    tree_queue.push(node->right);
                }
            
        }
    }
    Node* connect(Node* root) {
        bfs(root);
        return root;
    }
};