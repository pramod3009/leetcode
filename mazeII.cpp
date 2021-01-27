class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<int> dirx = {0, 0 , -1, 1};
        vector<int> diry = {1, -1, 0 , 0};
        vector<vector<bool>> vis(maze.size(), vector<bool> (maze[0].size(), false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        
        q.push({0, start[0], start[1]});
       
        while(!q.empty()){
            auto s = q.top();
            q.pop();
            vis[s[1]][s[2]] = true;
            if(s[1] == destination[0] and s[2] == destination[1]){
                return s[0];
            }
            for(int i = 0; i < 4; i++){
                int x = s[1] + dirx[i];
                int y = s[2] + diry[i];
                int count = 0;
                while(x >= 0 and y >= 0 and x < maze.size() and y < maze[0].size() 
                      and maze[x][y] != 1){
                    x += dirx[i];
                    y += diry[i];
                    count++;
                }
                
                x = x - dirx[i];
                y = y - diry[i];
                
                
                if(vis[x][y]){
                    continue;
                }
                q.push({count + s[0], x, y});
            }
        }
        return -1;
    }
};
