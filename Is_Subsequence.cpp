class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n==0){
            return true;
        }
        if(m==0){
            return false;
        }
        int i=0,j=0;
        int len=0;
        while(i<m and j<n){
            if(s[j]==t[i]){
                len+=1;
                j+=1;
            }
            i+=1;
        }
        return len==n;
    }
};