class Solution {
public:
    vector<int>x = {1, 1, 1, -1, -1, -1, 0, 0};
    vector<int>y = {1, -1, 0, 1, -1, 0, 1, -1};
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> ans = M;
        for(int i = 0;i < M.size(); i++){
            for(int j = 0;j<M[0].size();j++){
                int elems = 1;
                long long int sum = M[i][j];
                for(int k = 0;k<8;k++){
                    if(i + y[k] >= 0 and y[k] + i < M.size() and j + x[k] >= 0 and j + x[k] < M[0].size()){
                        sum+=M[i+y[k]][j+x[k]];
                        elems+=1;
                    }
                }
                ans[i][j] = floor(sum/elems);
            }
        }
        return ans;
    }
};