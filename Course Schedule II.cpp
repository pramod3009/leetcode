class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> graph[numCourses];
        vector<int> in(numCourses,0);
        for(int i = 0; i < prerequisites.size(); i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            in[prerequisites[i][0]]++;
        }
        queue<int> q;
        vector<int> result;
        for(int i = 0 ; i < numCourses; i++){
            if(in[i]==0){
                q.push(i);
                result.push_back(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto u:graph[node]){
                in[u]--;
                if(in[u]==0){
                    q.push(u);
                    result.push_back(u);
                }
            }
        }
        for(int i = 0 ; i < numCourses; i++){
            if(in[i]!=0){
                vector<int> temp;
                return temp;
            }
        }
        return result;
    }
};