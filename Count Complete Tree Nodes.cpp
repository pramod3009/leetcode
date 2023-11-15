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
    int count = 0;
    
    void helper(TreeNode* root){
        if(not root){
            return;
        }
        count+=1;
        helper(root->left);
        helper(root->right);
    }
    int countNodes(TreeNode* root) {
        helper(root);
        return count;
    }
};


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
 #include <math.h>

class Solution {
public:
    int d = 0;

    int computeDepth(TreeNode* node) {
        int d = 0;
        while(node->left != NULL) {
            node = node->left;
            ++d;
        }
        return d;
    }

    bool exists(int idx, int d, TreeNode* node) {
        int left = 0, right = pow(2, d) - 1;
        int pivot;

        for(int i = 0; i < d; i++) {
            pivot = left + (right - left)/2;
            if(idx <= pivot) {
                node = node->left;
                right = pivot;
            } else {
                node = node->right;
                left = pivot + 1;
            }
        }
        return node != NULL;
    }

    int countNodes(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int d = computeDepth(root);
        if(d == 0) {
            return 1;
        }
        int left = 1;
        int right = pow(2, d) - 1;
        int pivot;
        while(left <= right) {
            pivot = left + (right - left)/2;
            if(exists(pivot, d, root)) {
                left = pivot + 1;
            } else {
                right = pivot - 1;
            }
        }

        return pow(2, d) - 1 + left;    
    }
};
