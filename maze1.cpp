class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<int> dirx = {0, 0 , -1, 1};
        vector<int> diry = {1, -1, 0 , 0};
        queue<vector<int>> q;
        q.push({start[0], start[1]});
        maze[start[0]][start[1]] = 2;
        while(!q.empty()){
            auto s = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int x = s[0] + dirx[i];
                int y = s[1] + diry[i];
                while(x >= 0 and y >= 0 and x < maze.size() and y < maze[0].size() 
                      and maze[x][y] != 1){
                    x += dirx[i];
                    y += diry[i];
                }
                
                x = x - dirx[i];
                y = y - diry[i];
                
                if(x == destination[0] and y==destination[1]){
                    return true;
                }
                
                if(maze[x][y] != 2){
                    q.push({x, y});
                    
                    maze[x][y] = 2;    
                }
            }
        }
        return false;
    }
};
