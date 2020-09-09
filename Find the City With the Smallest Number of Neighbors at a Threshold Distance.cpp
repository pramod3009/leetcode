class Solution {
public:
    int minNeighbors = INT_MAX;
    int result_node = INT_MIN;
    
    void dijsktras(int n, vector<pair<int , int>> graph[], int k, int start){
        priority_queue<pair<int, int>> q;
        vector<int> d(n, INT_MAX);
        d[start] = 0;
        q.push({0, start});
        
        while(!q.empty()){
            int node = q.top().second;
            q.pop();
            for(const auto &e : graph[node]){
                int neighbor = e.first;
                int dist = e.second;
                if(d[neighbor] > d[node] + dist){
                    d[neighbor] = d[node] + dist;
                    q.push({d[neighbor], neighbor});
                }
            }
        }
        int neighbors = 0;
        for(int i = 0; i < n; i++){
            if(d[i] <= k and i!=start){
                neighbors++;
            }
        }
        cout<<start<<" "<<neighbors<<endl;
        if(neighbors <= minNeighbors){
            minNeighbors = neighbors;
            result_node = start;
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int , int>> graph[n];
        for(const auto &edge : edges){
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        for(int i = 0; i < n; i++){
            if(graph[i].size()){
                dijsktras(n, graph, distanceThreshold, i);
            } else{
                return i;
            }
        }
        return result_node;
    }
};
