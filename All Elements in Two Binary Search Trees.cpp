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
    vector<int> tree1;
    vector<int> tree2;
    vector<int> result;
    
    void traverseTree1(TreeNode* root1){
        if(root1){
           traverseTree1(root1->left);
            tree1.push_back(root1->val);
            cout<<root1->val<<" ";
            traverseTree1(root1->right);
        }
    }
    
    void traverseTree2(TreeNode* root2){
        if(root2){
           traverseTree2(root2->left);
            tree2.push_back(root2->val);
            traverseTree2(root2->right);
        }
    }
    
    void mergeTrees(){
        int n1 = tree1.size();
        int n2 = tree2.size();
        int i = 0,j = 0;
        
        while(i < n1 and j < n2){
            if(tree1[i]<=tree2[j]){
                result.push_back(tree1[i]);
                i++;
            } else {
                result.push_back(tree2[j]);
                j++;
            }
        }
        while(i < n1){
            result.push_back(tree1[i]);
            i++;
        }
        while(j < n2){
            result.push_back(tree2[j]);
            j++;
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        traverseTree1(root1);
        traverseTree2(root2);
        int n = tree1.size();
        // for(int i;i<n;i++){
        //     cout<<tree1[i]<< " ";
        // }
        //  cout<<endl;
        // for(auto i:tree2){
        //     cout<<i<<" ";
        // }
       
        mergeTrees();
        return result;
    }
};