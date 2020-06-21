class Solution:
    def wordPattern(self, pattern: str, string: str) -> bool:
        pattern = list(pattern)
        string = string.strip().split(" ")
        if len(pattern)!=len(string):
            return False
        d1 = {}
        d2 = {}
        n = len(string)
        for i in range(0,n):
            if not d1.get(string[i], 0) and not d2.get(pattern[i], 0):
                d1[string[i]] = pattern[i]
                d2[pattern[i]] = string[i]
        for i in range(0, n):
            if d1.get(string[i],"")!=pattern[i]:
                return False
        return True
        
        