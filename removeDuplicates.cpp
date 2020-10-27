class Solution {
public:
    string removeDuplicates(string st, int k) {
        stack<pair<char, int>> s;
        for(auto c : st){
            if(!s.empty() and c == s.top().first){
                if(s.top().second + 1 == k){
                    s.pop();
                } else {
                    int freq = s.top().second;
                    s.pop();
                    s.push({c, freq + 1});
                }
            } else {
                s.push({c, 1});
            }
        }
        string result = "";
        while(!s.empty()){
            for(int i = 0 ; i < s.top().second; i++){
                result = s.top().first + result;
            }
            s.pop();
        }
        return result;
    }
};
