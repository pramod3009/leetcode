class Solution {
public:
    vector<int> result;
    bool dfs(vector<vector<int>>& graph, vector<int>& v, int vertex){
        if(v[vertex] != 0){
            return v[vertex]==1;
        }
        v[vertex] = 2;
        
        for(const auto &n : graph[vertex]){
            if(!dfs(graph, v, n)){
                return false;
            }
        }
        v[vertex] = 1;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0);
        for(int i = 0; i < n; i++){
            if(dfs(graph, visited, i)){
                result.push_back(i);
            }
        }
        return result;
    }
};
