class Solution {
public:
    vector<string> result;
    void dfs(map<string,vector<string>> &graph, string airport){
        for(int i = 0; i < graph[airport].size(); i++){
            string temp = graph[airport][i];
            graph[airport].erase(graph[airport].begin() + i);
            i--;
            dfs(graph, temp);
        }
        result.push_back(airport);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,vector<string>> graph;
        
        for(int i = 0; i < tickets.size();i++){
            graph[tickets[i][0]].push_back(tickets[i][1]);
           
        }
        for(auto x=graph.begin();x!=graph.end();x++)
          sort(x->second.begin(),x->second.end());
        dfs(graph, "JFK");
        reverse(result.begin(), result.end());
        return result;
    }
};
