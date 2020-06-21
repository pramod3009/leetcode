class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int  n = grid.size();
        int m = grid[0].size();
        int d[n][m] = {0};
        d[0][0] = grid[0][0];
        for(int i=1;i<n;i++){
            d[i][0]=d[i-1][0]+grid[i][0];
        }
        
        for(int i = 1;i < m;i++){
            d[0][i] = d[0][i-1]+grid[0][i]; 
        }
        for(int i=1; i < n; i++){
            for(int j=1;j<m;j++){
                //cout<<grid[i][j]<<d[i][j-1]<<d[i-1][j]<<endl;
                d[i][j] = grid[i][j] + min(d[i][j-1],d[i-1][j]);
            }
        }
        return d[n-1][m-1];    
    }
};