class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        
        int n = A.size();
        int m = B.size();
        if(not n or not m){
            return 0;
        }
        int dp[n+1][m+1];
        for(int i = 0;i<n;i++){
            dp[i][0] = 0;
        }
        for(int i=0;i<m;i++){
            dp[0][i] = 0;
        }
        int maxlen = INT_MIN;
        for(int i = 1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(A[i-1]==B[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    maxlen = max(maxlen,dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        if(maxlen==INT_MIN)
            return 0;
        return maxlen;
    }
};