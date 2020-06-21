class Solution {
public:
    bool found;
    bool abort;
    int n;
    int m;
    bool dfs(int i,int j,vector<vector<char>>& board, string word,vector<vector<int>> &visited,int index){
        
        if(index==word.length()){
            found =true;
            return found;
        }
        if(i<0 or j<0 or i>=n or j>=m or board[i][j]!=word[index] or visited[i][j]==1){
            return false;
        }
        visited[i][j]=1;
        
        bool res=dfs(i-1,j,board,word,visited,index+1)||dfs(i+1,j,board,word,visited,index+1)||
               dfs(i,j-1,board,word,visited,index+1)||dfs(i,j+1,board,word,visited,index+1);
        visited[i][j]=0;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    vector<vector<int>> visited(n, vector<int> (m, 0));
                    dfs(i,j,board,word,visited,0);
                    if(found){
                        return found;
                    }
                }
            }
        }
        return false;
    }
}; 