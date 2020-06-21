class Solution:
    def reverseWords(self, s: str) -> str:
        s = list(s.strip().split())
        for i in range(len(s)):
            s[i] = s[i][::-1]
        return " ".join(s)
        