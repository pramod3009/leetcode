class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not len(s):
            return 0
        gcount = 0
        n = len(s)
        i=0
        j=0
        d = {}
        ans = 0 
        while i<n and j<n:
            if d.get(s[j],-1) != -1:
                i = max(i,d[s[j]])
            ans = max(ans,j-i+1)
            d[s[j]] = j+1
            j+=1
        return ans
                
                
        