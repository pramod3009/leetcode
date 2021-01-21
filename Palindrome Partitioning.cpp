class Solution {
public:
    vector<vector<string>> result;
    vector<string> currentlist;
    vector<vector<string>> partition(string s) {
        dfs(s, 0, currentlist);
        return result;
    }
    
    void dfs(string &s, int start, vector<string> &currentlist){
        if(start >= s.length()){
            result.push_back(currentlist);
        }
        
        for(int end = start; end < s.length(); end++){
            if(isPalindrome(s, start, end)){
                currentlist.push_back(s.substr(start, end - start + 1));
                dfs(s, end + 1, currentlist);
                currentlist.pop_back();
            }
        }
    }
    
    bool isPalindrome(string &s, int low, int high){
        while(low < high){
            if(s[low++] != s[high--]) return false;
        }
        return true;
    }
};
