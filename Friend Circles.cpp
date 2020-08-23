class Solution {
public:
    void dfs(vector<vector<int>>& m, int i, int j){
        if(i < 0 or i==m.size() or j < 0 or j==m.size() or m[i][j]!=1){
            return;
        }
        m[i][j] = 0;
        for(int k = 0; k < m.size(); k++){
            dfs(m, j, k);
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(M[i][j]){
                    dfs(M, i , j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
