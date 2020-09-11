class Solution {
public:
    vector<bool> result;
    bool dfs(int n, vector<int> graph[], vector<bool> &vis, int start, int end){
        if(start == end){
            return true;
        }
        vis[start] = true;
        for(const auto &node : graph[start]){
            if(!vis[node]){
                if(dfs(n, graph, vis, node, end)){
                    return true;
                }
            }
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> graph[n];
        vector<bool> vis(n, false);
        for(const auto &edge : prerequisites){
            graph[edge[0]].push_back(edge[1]);
        }
        for(const auto &edge : queries){
            for(int i = 0; i < n; i++){
                vis[i] = false;
            }
            result.push_back(dfs(n, graph, vis, edge[0], edge[1]));
        }
        return result;
    }
};
