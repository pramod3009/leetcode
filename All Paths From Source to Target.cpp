class Solution {
public:
    vector<vector<int>> result;
    void dfs(int node,vector<vector<int>>& graph, int n,int  vis[] ,vector<int>path){
        if (vis[node]!=0){
            return;
        }
        vis[node]=1;
        path.push_back(node);
        if(node==n){
            result.push_back(path);
            
        }
        else {
        for(auto i:graph[node]){
            dfs(i,graph,n,vis,path);
        }}
        vis[node] = 0;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        int vis[15] = {0};
        vector<int>path;
        dfs(0, graph, n-1, vis,path);
        return result;
    }
    
};