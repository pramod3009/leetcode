class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        set<pair<int , int>> s;
        for(int i = 0; i < costs.size(); i++){
            s.insert({costs[i][0] - costs[i][1], i});
        }
        int n = costs.size() / 2;
        int result = 0;
        for(const auto &temp : s){
            if(n-- > 0){
                result += costs[temp.second][0];
            } else {
                result += costs[temp.second][1];
            }
        }
        return result;
    }
};
