class Solution:
    def reverseWords(self, s: str) -> str:
        x=s.strip().split()
        x=x[::-1]
        return ' '.join(x)
        