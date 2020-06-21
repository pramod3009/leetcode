class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length(), m  = s2.length();
        int dp[n+1][m+1];
        
        dp[0][0] = 0;
        for(int i=1;i<=n;i++){
            dp[i][0] = int(s1[i-1])+dp[i-1][0];
        }
        
        for(int j=1;j<=m;j++){
            dp[0][j] = int(s2[j-1])+dp[0][j-1];
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]!=s2[j-1]){
                    dp[i][j] = min(dp[i-1][j]+int(s1[i-1]), int(s2[j-1]+dp[i][j-1]));
                } else {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[n][m];
    }
};