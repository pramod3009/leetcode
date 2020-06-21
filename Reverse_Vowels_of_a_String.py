class Solution:
    def reverseVowels(self, s: str) -> str:
        s = list(s)
        indices = []
        for i in range(0,len(s)):
            if s[i] in ['a','e','i','o','u','A','E','I','O','U']:
                indices.append(i)
        i = 0
        n = len(indices) - 1
        while(i <= n/2):
            print(indices[i],indices[-i])
            s[indices[i]] , s[indices[n-i]] = s[indices[n-i]] ,s[indices[i]]
            i+=1
        return "".join(s)