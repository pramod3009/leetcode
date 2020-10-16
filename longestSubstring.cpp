class Solution {
public:
    int helper(string &s, int start, int end, int k){
        if(end < k){
            return 0;
        }
        int countmap[26] = {0};
        for(int i = start;i < end;i++){
            countmap[s[i]-'a']++;
        }
        for(int mid = start; mid < end; mid++){
            if(countmap[s[mid]-'a']>=k){
                continue;
            }
            int midnext = mid + 1;
            while(midnext < end and countmap[s[midnext]-'a']<k){
                midnext++;
            }
            return max(helper(s, start, mid, k),helper(s,midnext, end,k));
        }
        return end - start;
    }
    int longestSubstring(string s, int k) {
        int n = s.length();
        return helper(s, 0 , n, k);
    }
};
