class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int n = board.size();
        if(not n){
            return 0; 
        }
        int m = board[0].size();
        if (not m){
            return 0;
        }
        int rooki,rookj;
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='R'){
                    rooki = i;
                    rookj = j;
                    break;
                }
            }
        }
        int count = 0;
        for(int i = rooki;i<n;i++){
            if(board[i][rookj]=='p'){
                count+=1;
                break;
            }
            if(board[i][rookj]=='B'){
                break;
            }
        }
        
        for(int i = rooki;i>=0;i--){
            if(board[i][rookj]=='p'){
                count+=1;
                break;
            }
            if(board[i][rookj]=='B'){
                break;
            }
        }
        
        for(int j = rookj;j<m;j++){
            if(board[rooki][j]=='p'){
                count+=1;
                break;
            }
            if(board[rooki][j]=='B'){
                break;
            }
        }
        
         for(int j = rookj;j>=0;j--){
            if(board[rooki][j]=='p'){
                count+=1;
                break;
            }
            if(board[rooki][j]=='B'){
                break;
            }
        }
        return count;
    }
};