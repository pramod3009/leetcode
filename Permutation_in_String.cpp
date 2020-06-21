class Solution {
public:
    bool matching(int d[26],int t[26]){
        for(int i = 0; i < 26 ;i++ ){
            if(d[i]!=t[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if (n>m)
            return false;
        int d[26] = {0};
        
        
        for(int i = 0; i < n; i++){
            d[s1[i] - 'a']+=1;
        }
        
        for(int i = 0; i <= m-n; i++){
            int t[26] = {0};
            for(int j = 0;j < n ;j++){
                t[s2[i+j] - 'a']+=1;
            }
            if (matching(d, t)){
                return true;
            }
        }
        
        return false;
    }
};