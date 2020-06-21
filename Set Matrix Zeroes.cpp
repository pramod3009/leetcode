class Solution {
public:
    int MODIFIED = -1000000;
    void helper(int row,int col, vector<vector<int>>& matrix, int nrows, int ncols){
        
            for(int i = 0; i < ncols; i++) {
                if(matrix[row][i]!=0)
                    matrix[row][i] = MODIFIED;
            }
        
      
            for(int i = 0;i < nrows;i++){
                if(matrix[i][col]!=0)
                    matrix[i][col] = MODIFIED;
            }
      
        
        
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int nrows = matrix.size();
        if(not nrows)
            return;
        int ncols = matrix[0].size();
        if(not ncols)
            return;
        for(int i = 0;i < nrows;i++){
            for(int j = 0;j < ncols;j++){
                if(matrix[i][j]==0){
                    helper(i, j, matrix, nrows, ncols);
                }
            }
        }
        for(int i = 0;i < nrows;i++){
            for(int j = 0;j < ncols;j++){
                if(matrix[i][j]==MODIFIED){
                    matrix[i][j] = 0;
                }
            }
        }
        
    }
};