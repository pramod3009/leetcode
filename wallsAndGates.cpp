class Solution {
public:
    vector<int> dirx = {0 ,0, -1, 1};
    vector<int> diry = {1, -1, 0, 0};
    void wallsAndGates(vector<vector<int>>& rooms) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        
        //cout<<"hi";
        for(int i = 0; i < rooms.size(); i++){
            for(int j = 0; j < rooms[0].size(); j++){
                if(rooms[i][j] == 0){
                    q.push({0, {i, j}});
                }
            }
        }
        //cout<<"hi";
        while(!q.empty()){
            int cost = q.top().first;
            int x    = q.top().second.first;
            int y    =  q.top().second.second;
            q.pop();
            //cout<<x<<" "<<y<<" "<<cost<<endl;
            for(int i = 0; i < 4; i++){
                if(x + dirx[i] >=0 and x + dirx[i] < rooms.size() and y + diry[i] >=0 and y + diry[i] < rooms[0].size() and rooms[x + dirx[i]][y + diry[i]] != -1 and cost + 1 < rooms[x + dirx[i]][y + diry[i]]){
                    rooms[x + dirx[i]][y + diry[i]] = cost + 1;
                    q.push({cost + 1, {x + dirx[i], y + diry[i]}});
                }
            }
        }
    }
};
