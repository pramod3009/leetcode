class Solution {
public:
    void helper(vector<string> &result,int pos,int n, string s, int open,int close){
        if(close==n){
           result.push_back(s);
            return;
        }
        if(open<n){
            s[pos] = '(';
            helper(result,pos+1,n,s,open+1,close);
        }
        if(open>close){
            s[pos] = ')';
            helper(result, pos+1,n,s,open,close+1);
        }
        
    }
    vector<string> generateParenthesis(int n) {
        string  s = std::string(2*n,'#');
        vector<string> result;
        helper(result,0,n,s,0,0);
        return result;
    }
};