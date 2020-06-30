class Solution {
public:
    map<int,vector<pair<int,bool>>> graph;
    
    void createGraph(vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges){
        for(int i = 0;i < red_edges.size(); i++){
            graph[red_edges[i][0]].push_back({red_edges[i][1], true});
        }
        for(int i = 0;i < blue_edges.size(); i++){
            graph[blue_edges[i][0]].push_back({blue_edges[i][1], false});
        }
    }
    
    void bfs(vector<int> &result, int n){
        
        
        int visited[n][2];
        memset(visited,-1,sizeof visited);
        visited[0][0] = 0;
        visited[0][1] = 0;
        queue<pair<int,int>> q;
        q.push({0,0});
        q.push({0,1});
        while(!q.empty()){
            int size = q.size();
            for(int j = 0; j < size; j++){
                pair<int,int> p = q.front();
                q.pop();
                
                
                for(auto child : graph[p.first]){
                    if(visited[child.first][child.second]==-1 and child.second!=p.second){
                        q.push(child);
                        visited[child.first][child.second] = visited[p.first][p.second] + 1;
                    }

                }
            }
        }
        for(auto i : visited){
            min(i[0],i[1])==-1? result.push_back(max(i[0],i[1])):result.push_back(min(i[0],i[1]));
        }
        
    }
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        createGraph(red_edges, blue_edges);
        vector<int> result;
        bfs(result, n);
        return result;
    }
};
