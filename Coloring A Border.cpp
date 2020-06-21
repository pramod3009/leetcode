class Solution {
public:
    int square_colour;
    int n;
    int m;
    
    void helper(vector<vector<int>>& grid,vector<vector<int> > &vis, int i, int j, int color){
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j]!=square_colour or vis[i][j]==1){
            return;
        }
        grid[i][j] = INT_MAX;
        vis[i][j]=1;
        helper(grid,vis,i-1,j,color);
        helper(grid,vis,i+1,j,color);
        helper(grid,vis,i,j-1,color);
        helper(grid,vis,i,j+1,color);
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        square_colour = grid[r0][c0];
        n = grid.size();
        m = grid[0].size();
        vector<vector<int> > vis( n , vector<int> (m, 0));
        vector<vector<int> > temp = grid;
        helper(temp,vis,r0, c0, color);
        		

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(i == 0 || j == 0 || i == n - 1 || j == m - 1) {
					if(temp[i][j] == INT_MAX)
						grid[i][j] = color;
				} else {
					if((temp[i][j]) == INT_MAX and 
					   ((temp[i - 1][j] != INT_MAX) || (temp[i + 1][j] != INT_MAX) ||
						(temp[i][j - 1] != INT_MAX) || (temp[i][j + 1] != INT_MAX)))
						grid[i][j] = color;
				}
			}
		}

		return grid;
    }
};