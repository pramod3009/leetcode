class Solution {
public:
    typedef pair<int, int> pii;
    int minimumCost(int n, vector<vector<int>>& connections) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 1});
        unordered_map<int, vector<pii>> graph;
        
        for(auto conn : connections){
            graph[conn[0]].push_back({conn[1], conn[2]});
            graph[conn[1]].push_back({conn[0], conn[2]});
        }
        unordered_set<int> s;
   
        int result = 0;
     
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int node = p.second;
            int cost = p.first;
            if(s.find(node)!=s.end()){
                continue;
            }
            result += cost;
            s.insert(node);
            for(auto neighbor : graph[node]){
                int nextnode = neighbor.first;
                int nextcost = neighbor.second;
                if(s.find(nextnode)!=s.end()){
                    continue;
                }
                pq.push({nextcost, nextnode});
                
            }
        }
        return s.size() == n ? result : -1;
    }
};
