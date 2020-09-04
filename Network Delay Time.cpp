class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<pair<int,int>> graph[N + 1];
        for(const auto &e : times){
            graph[e[0]].push_back({e[1],e[2]});
        }
        priority_queue<pair<int,int>>q;
        q.push({0,K});
        
        vector<int> dist(N + 1, INT_MAX);
        dist[K] = 0;
        while(!q.empty()){
            auto p = q.top();
            int node = p.second;
            int val = p.first;
            q.pop();
            for(int i = 0; i < graph[node].size(); i++){
                if(dist[graph[node][i].first] > val + graph[node][i].second){
                    dist[graph[node][i].first] = val + graph[node][i].second;
                    q.push({dist[graph[node][i].first], graph[node][i].first});
                }
            }
        }
        int x = *max_element(dist.begin() + 1, dist.end());
        return x==INT_MAX?-1:x;
    }
};
