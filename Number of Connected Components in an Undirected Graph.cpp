class Solution {
public:
    int result = 0;
    vector<int> parent;
    int find(int a){
        while(a != parent[a]){
            a = parent[a];
        }
        return a;
    }
    void _union(int a, int b){
        int roota = find(a);
        int rootb = find(b);
        
        if(roota == rootb){
            return;
        }
        parent[roota] = rootb;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < n; i++){
            parent.push_back(i);
        }
        for(auto edge : edges){
            _union(edge[0], edge[1]);
        }
        
        for(int i = 0; i < n; i++){
            if(parent[i] == i){
                result++;
            }
        }
        return result;
        
    }
};
