class Solution {
public:
    
    void dfs(vector<vector<int>>& rooms, vector<bool> &visited, int node){
        if(visited[node]){
            return;
        }
        visited[node] = true;
        for(auto room:rooms[node]){
            dfs(rooms,visited, room);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        dfs(rooms, visited, 0);
        for(int i = 0; i < rooms.size(); i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
};
