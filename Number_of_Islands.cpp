class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0)
            return 0;
        int m =grid[0].size();
        if (m==0)
            return 0;
        int count = 0;
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            if(grid[i][j]=='1')  
                count+=dfs(grid,i,j,n,m) ;
          }  
        }
        return count;
    }
    int dfs(vector<vector<char>>& grid, int i, int j,int n,int m){
        if(i<0 || i==n || j<0 || j==m || grid[i][j]=='0')
            return 0;
        grid[i][j] = '0';
        dfs(grid,i+1,j,n,m);
        dfs(grid,i-1,j,n,m);
        dfs(grid,i,j-1,n,m);
        dfs(grid,i,j+1,n,m);
        return 1;
    }
};