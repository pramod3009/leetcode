class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(s.length()+1,false);
        dp[0] = true;
        for(int i = 0 ;i < n;i++){
            if(!dp[i]){
                continue;
            }
            for(const auto word:wordDict){
                int length = word.size();
                if(i + length>n){
                    continue;
                }
                if(s.substr(i, length)==word){
                    dp[i+length] = true;
                }
            }
        }
        return dp[n];
    }
};
