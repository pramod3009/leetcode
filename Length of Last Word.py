class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if not len(s):
            return 0
        s = s.strip().split(" ")
        return len(s[-1])