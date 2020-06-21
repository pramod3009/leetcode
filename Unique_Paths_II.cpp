class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(!obstacleGrid.size() or !obstacleGrid[0].size()){
            return 0;
        }
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<unsigned int>> vec(n, vector<unsigned int>(m, 0));
        
        if (obstacleGrid[0][0] == 1){
            vec[0][0] = 0;
        } else {
            vec[0][0]=1;
        }
        for(int i = 1;i < n;i++){
            if (obstacleGrid[i][0] == 1 || vec[i-1][0]==0){
                vec[i][0] = 0;
            } else {
                vec[i][0] = 1;
            }
        }
        for(int i = 1;i < m;i++){
            if (obstacleGrid[0][i] == 1 || vec[0][i-1]==0){
                vec[0][i] = 0;
            } else {
                vec[0][i] = 1;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(obstacleGrid[i][j]==1){
                    vec[i][j] = 0;
                } else {
                    vec[i][j] = vec[i-1][j] + vec[i][j-1];
                }
            }
        }
        return vec[n-1][m-1];
        
    }
};