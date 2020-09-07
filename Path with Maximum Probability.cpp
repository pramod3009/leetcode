#include<float.h>
#include<math.h>
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edge, vector<double>& succProb, int start, int end) {
         vector<pair<int, double>> graph[n];
        for(int i = 0 ; i < succProb.size(); i++){
            graph[edge[i][0]].push_back({edge[i][1], succProb[i]});
            graph[edge[i][1]].push_back({edge[i][0], succProb[i]});
        }
        
        priority_queue<pair<double, int>> q;
        vector<double> d(n, double(-'inf'));
        d[start] = 0.0;
        q.push({0, start});
        
        while(!q.empty()){
            int node = q.top().second;
            q.pop();
            for(const auto &e : graph[node]){
                int neighbor = e.first;
                double dist = e.second;
                
                if(d[neighbor] < d[node] + log(dist)){
                    d[neighbor] = d[node] + log(dist);
                    q.push({d[neighbor], neighbor});
                    
                }
            }
        }
        return d[end]==-double('inf') ? 0 : exp(d[end]);
    }
};
