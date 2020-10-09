class Solution {
public:
    int helper(string s, int left, int right){
        if(left > right){
            return 0;
        }
        while(left>=0 and right < s.length() and s[left]==s[right]){
            left--;
            right++;
        }
        return right - left -1;
    }
    string longestPalindrome(string s) {
        if( not s.length()){
            return "";
        }
        int start = 0;
        int end = 0;
        for(int i = 0; i < s.length(); i++){
            int len1 = helper(s, i , i);
            int len2 = helper(s, i, i + 1);
            int len = max(len1, len2);
            if(len > end - start){
                start = i - (len - 1)/2;
                end = i + (len)/2;
            }
        }
        //cout<<start<<" "<<end;
        return s.substr(start , end - start + 1);
    }
};
