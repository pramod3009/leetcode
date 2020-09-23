class Solution {
public:
    map<int, vector<pair<int, int>>> graph;
   
    
    int djs(int src, int dst, int k ,int n){
        queue<pair<int,int>> q;
        vector<int>dist(n, INT_MAX);
        dist[src] = 0;
        q.push({0, src});
        do{
            int size = q.size();
            int node;
            while(size--){
                int d = q.front().first;
                node = q.front().second;
                q.pop();
                for(const auto neighbor : graph[node]){
                    if(d + neighbor.second < dist[neighbor.first]){
                        dist[neighbor.first] = d + neighbor.second;
                        q.push({dist[neighbor.first], neighbor.first});
                    }
                }
            }
        }while(!q.empty() and k-- > 0);
       return dist[dst]==INT_MAX ? -1 : dist[dst]; 
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        for(const auto &flight : flights){
            graph[flight[0]].push_back({flight[1], flight[2]});
        }
       return djs(src, dst, K, n);
    }
};
