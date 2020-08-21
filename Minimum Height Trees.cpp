class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1){
            return {0};
        }
        int indegree[n];
        for(int i = 0; i < n; i++){
            indegree[i] = 0;
        }
        map<int, vector<int>> m;
        for(auto e:edges){
            indegree[e[0]]++;
            indegree[e[1]]++;
            m[e[0]].push_back(e[1]);
            m[e[1]].push_back(e[0]);
        }
        queue<int> q;
        for(int i = 0;i < n;i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }
        vector<int> result;
        while(!q.empty()){
            int size= q.size();
            
            for(int i = 0 ;i < size; i++){
                int node = q.front();
                q.pop();
                result.push_back(node);
                for(int neighbor:m[node]){
                    if(--indegree[neighbor]==1){
                        q.push(neighbor);
                    }
                }
            }
            if(q.empty()){
                return result;
            }
            result.clear();

        }
        return {};
    }
};
