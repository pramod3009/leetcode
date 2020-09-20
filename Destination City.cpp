class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> visited;
        for(const auto &edge : paths){
            visited.insert(edge[0]);
        }
        for(const auto &edge : paths){
            if(visited.find(edge[1])==visited.end()){
                return edge[1];
            }
        }
        return "";
    }
};
