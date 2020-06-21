class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        vector<int> graph[numCourses];
        vector<int>indegree(numCourses,0);
        for(int i = 0; i < prereq.size(); i++){
            graph[prereq[i][1]].push_back(prereq[i][0]);
            indegree[prereq[i][0]]++;
        }
        queue<int> q;
        bool visited[indegree.size()]={false};
        for(int i = 0; i < indegree.size(); i++){
            if(not indegree[i]){
                q.push(i);
                visited[i] = true;
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto u:graph[node]){
                indegree[u]--;
                if(not indegree[u]){
                    q.push(u);
                }
            }    
        }
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i]){
                return false;
            }
        }
        return true;
        
    }
};