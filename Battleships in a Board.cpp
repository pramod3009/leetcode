class Solution {
public:
    int res;
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i<0 or j<0 or i >= board.size() or j >= board[0].size() or board[i][j]!='X'){
            return;
        }
        board[i][j] = '.';
        dfs(board,i-1,j);
        dfs(board,i+1,j);
        dfs(board,i,j-1);
        dfs(board,i,j+1);
    }
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        if(not n){
            return 0;
        }
        int m = board[0].size();
        if(not m){
            return 0;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j]=='X'){
                    dfs(board, i, j);
                    res++;
                }
                
            }
        }
        return res;
    }
};