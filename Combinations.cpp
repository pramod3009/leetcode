class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void helper(int n,int k,int index = 0){
        if(k==0){
            result.push_back(path);
            return;
        }
        for(int i=index+1;i<=n;i++){
            path.push_back(i);
            helper(n,k-1,i);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        helper(n,k);
        return result;
    }
};