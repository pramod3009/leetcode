class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        if(not n){
            return true;
        }
        if(n==1){
            return leftChild[0]==-1 and rightChild[0]==-1;
        }
        vector<int> nodeParent(n+1,INT_MAX);
        int visited = 0;
        for(int i = 0; i < n; i++){
            if((leftChild[i]!=-1 and nodeParent[leftChild[i]]!=INT_MAX) or (rightChild[i]!=-1 and nodeParent[rightChild[i]]!=INT_MAX)){
                return false;
            }
            if(leftChild[i]!=-1){
                nodeParent[leftChild[i]] = i;
                visited++;
            }
            if(rightChild[i]!=-1){
               nodeParent[rightChild[i]] = i;
                visited++;
            }
            
        }
        if (visited != n-1) return false;
        for (int i=0; i<n; i++){
            if (nodeParent[i]==INT_MAX){
                return leftChild[i] >= 0 || rightChild[i] >= 0;
            }
        }
        return false;
    }
};
