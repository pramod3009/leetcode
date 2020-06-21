class Solution:
    def lastSubstring(self, s: str) -> str:
        if not len(s):
            return ""
        result = ""
        for i in range(0,len(s)):
            result = max(result,s[i:])
        return result
        