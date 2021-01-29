class Solution {
public:
    vector<int> parent;
    int find(int root){
       while(parent[root] != root){
           root = parent[root];
       }
        return root;
    }
    bool _union(int a, int b){
        int roota = find(a);
        int rootb = find(b);
        if(roota == rootb){
            return false;
        }
        parent[roota] = rootb;
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1){
            return false;
        }
        for(int i = 0; i < n; i++){
            parent.push_back(i);
        }
        
        for(auto edge : edges){
            if(!_union(edge[0], edge[1])){
                return false;
            }
        }
        return true;
    }
};
