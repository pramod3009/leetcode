class Solution {
public:
    vector<double> result;
    unordered_set<string> visited;
    map<string, vector<pair<string,double>>> m;
    
    void dfs(string start, string end,bool &flag, double res = 1){
        if(start == end){
            result.push_back(res);
            flag = true;
            return;
        }
        visited.insert(start);
        for(const auto p : m[start]){
            if(visited.find(p.first)==visited.end() and !flag){
                dfs(p.first, end, flag, res * p.second);
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        bool flag = false;
        for(int i = 0; i < equations.size(); i++){
            m[equations[i][0]].push_back({equations[i][1], values[i]});
            m[equations[i][1]].push_back({equations[i][0], 1.0/values[i]});
        }
        for(const auto &query : queries){
            if(m.find(query[0])==m.end() or m.find(query[1])==m.end()){
                result.push_back(-1.0);
            } else if(query[0]==query[1]){
                result.push_back(1.0);
            } else{
                visited.clear();
                flag = false;
                dfs(query[0], query[1], flag);
                if(!flag){
                    result.push_back(-1.0);
                }
            }
        }
        return result;
    }
};
