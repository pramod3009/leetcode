class Solution {
public:
    bool result = true;
    map<int, vector<int>> graph;
    void dfs(int node, int parent, vector<bool> &visited){
        if(visited[node]){
            result = false;
            return;
        }
        visited[node] = true;
        for(auto enemy :  graph[node]){
            if(enemy != parent){
                dfs(enemy, node, visited);
            }
            
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        
        for(auto &edge  : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        dfs(0, -1, visited);
        
        for(auto v : visited){
            if(!v){
                return false;
            }
        }
        
        return result;
    }
};
