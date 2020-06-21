class Solution {
public:
    int find(vector<int> &parent, int x){
        if(parent[x]==x){
            return x;
        }
       return find(parent,parent[x]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> result(2,0);
       if(!edges.size() or !edges[0].size()){
           return result;
       } 
       vector<int> parent(edges.size() + 1, 0);
       for(int i = 0; i <= edges.size(); i++){
           parent[i] = i;
       } 
       for(int i = 0; i < edges.size(); i++){
           int x = find(parent,edges[i][0]);
           int y = find(parent,edges[i][1]);
           if(x!=y){
               parent[x] = y;
           } else {
               result[0] = edges[i][0];
               result[1] = edges[i][1];
           }
       } 
     return result;                  
    }
};