class Solution {
public:
    
    class node{
        public:
        int x;
        int y;
        node(int X,int Y){
            x=X;
            y=Y;
        }
    };
    void bfs(vector<vector<int>>& grid, queue<node> &q){
        int row = grid.size();
        int col = grid[0].size();
        int d = 1;
        cout<<q.size();
        while(!q.empty()){
            int size = q.size();
            for(int k = 0;k<size;k++){
                node n = q.front();
                q.pop();
                int  i = n.x;
                int  j = n.y;
                if(i-1>=0 and grid[i-1][j]==0){
                    grid[i-1][j] = d;
                    q.push(node(i-1,j));
                }
                if(i+1<row and grid[i+1][j]==0){
                    grid[i+1][j] = d;
                    q.push(node(i+1,j));
                }
                if(j-1>=0 and grid[i][j-1]==0){
                    grid[i][j-1] = d;
                    q.push(node(i,j-1));
                }
                if(j+1<col and grid[i][j+1]==0){
                    grid[i][j+1] = d;
                    q.push(node(i,j+1));
                }
            }
            d++;
        }
    }
    int maxDistance(vector<vector<int>>& grid) {
        if(not grid.size() or not grid[0].size()){
            return -1;
        }
        queue<node> q;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    grid[i][j] = -1;
                    q.push(node(i,j));
                }
            }
        }
        bfs(grid,q);
        int maxd = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                maxd = max(maxd,grid[i][j]);
                cout<<grid[i][j];
            }
            cout<<endl;
        }
        if(not maxd){
            maxd = -1;
        }
        return maxd;
    }
};