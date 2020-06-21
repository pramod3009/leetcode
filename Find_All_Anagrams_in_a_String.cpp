class Solution {
public:
    bool match(int d[26], int t[26]){
        for(int i = 0;i < 26; i++){
            if(d[i]!=t[i])
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int> result;
        int d[26] = {0};
        for(int i = 0;i < m; i++){
            d[p[i]-'a']++;
        }
        for(int i = 0;i <= n - m;i++){
            int t[26] = {0};
            for(int j = 0; j < m; j++ ){
                t[s[i+j]-'a']++;
            }
            if(match(d,t)){
                result.push_back(i);
            }
        }
        return result;
    }
};