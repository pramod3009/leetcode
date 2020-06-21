class Solution {
public:
    void helper(string s,vector<string>&result,int l,int r){
        if(l==r){
            result.push_back(s);
            return;
        }
        
            if(islower(s[l])){
                s[l] = toupper(s[l]);
                helper(s,result,l+1,r);
                s[l] = tolower(s[l]);
            
            } else if(isupper(s[l])) {
                 s[l] = tolower(s[l]);
                helper(s,result,l+1,r);
                s[l] = toupper(s[l]);
                
            }
            helper(s,result,l+1,r);
           
    }
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        
        if(not S.length()){
            return result;
        }
        helper(S,result,0,S.length());
        return result;
    }
};