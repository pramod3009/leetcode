class Solution {
public:
    vector<int> result;
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> in(n, 0);
        for(const auto edge : edges){
            in[edge[1]]++;
        }
        for(int i = 0; i < n; i++){
            if(!in[i]){
                result.push_back(i);
            }
        }
        return result;
    }
};
