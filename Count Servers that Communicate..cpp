class Solution {
public:
    map<int,int> row_map;
    map<int,int> col_map;
    int rows;
    int cols;
    int result;
    int countServers(vector<vector<int>>& grid) {
        if(!grid.size() or !grid[0].size()){
            return 0;
        }
        rows = grid.size();
        cols = grid[0].size();
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]==1){
                    row_map[i]++;
                    col_map[j]++;
                }
            }
        }
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] and (row_map[i] - 1 > 0 or col_map[j] - 1 > 0)){
                    result++;
                }
            }
        }
        return result;
    }
};
