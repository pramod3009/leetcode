class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        if(grid[0][0]){
            res += 4;
        }
        for(int i = 1; i < grid.size(); i++){
            if(grid[i][0]){
                if(grid[i-1][0]){
                    res += 2;
                } else {
                    res += 4;
                }
            }
        }
        
        for(int j = 1; j < grid[0].size(); j++){
            if(grid[0][j]){
                if(grid[0][j - 1]){
                    res += 2;
                } else {
                    res += 4;
                }
            }
        }
        for(int i = 1; i < grid.size(); i++){
            for(int j = 1; j < grid[0].size(); j++){
                if(!grid[i][j] or (grid[i-1][j] and grid[i][j-1])){
                    continue;
                } else if(grid[i-1][j] or grid[i][j-1]){
                    res += 2;
                }  else {
                    res += 4;
                }
            }
        }
        return res;
    }
};
