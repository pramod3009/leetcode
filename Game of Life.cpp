class Solution {
public:
    vector<int>row = {-1,-1,-1,0,0,1,1,1};
    vector<int>col = {-1,0,+1,-1,1,-1,0,1};
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        if(not n){
            return;
        }
        int m = board[0].size();
        if(not m){
            return;
        }
        int copy[n][m];
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                copy[i][j] = board[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int neighbours = 0;
                for(int k=0;k<8;k++){
                    if(i+row[k]>=0 and i+row[k]<n and j+col[k]>=0 and j+col[k]<m and board[i+row[k]][j+col[k]]){
                        neighbours++;
                    }
                }
                if(board[i][j] and (neighbours<2 or neighbours>3)){
                    copy[i][j] = 0;
                } else if(!board[i][j] and neighbours==3){
                    copy[i][j] = 1;
                }
            }
        }
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j] = copy[i][j];
            }
        }
    }
};