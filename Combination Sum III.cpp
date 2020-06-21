class Solution {
public:
    vector<vector<int>> result;
    vector<int>path;
    void helper(int k, int n,int index=0){
        if(k==0 and n==0){
            result.push_back(path);
            return;
        }
        if(k==0){
            return;
        }
        for(int i=index+1;i<=9;i++){
            if(n-i<0){
                return;
            }
            path.push_back(i);
            helper(k-1,n-i,i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        helper(k,n);
        return result;
    }
};