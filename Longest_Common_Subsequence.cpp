class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        if(n==0 or m==0){
            return 0;
        }
        int lcs[n+1][m+1];
        
        for(int i=0;i<=n;i++){
            lcs[i][0] = 0;
        }
        
        for(int i=0;i<=m;i++){
            lcs[0][i] = 0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    lcs[i][j] = 1 + lcs[i-1][j-1]; 
                } else {
                    lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
                }
                
            }
        }
        return lcs[n][m];
   }
};