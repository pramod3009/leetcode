class Solution {
public:
    void dfs(vector<vector<int>> &grid, int i , int j, string &temp, string dir){
        if(i < 0 or i >= grid.size() or j < 0 or j >= grid[0].size() or !grid[i][j] ){
            return;
        }
        grid[i][j] = 0;
        temp += dir;
        dfs(grid, i - 1, j, temp, "u");
        dfs(grid, i + 1, j, temp, "d");
        dfs(grid, i, j - 1, temp, "l");
        dfs(grid, i, j + 1, temp, "r");
        temp += "b";
        
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        set<string> result;
        for(int i = 0 ; i< grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]){
                    string temp;
                    dfs(grid, i , j, temp, "o");
                    result.insert(temp);
                }
            }
        }
        return result.size();
    }
};
