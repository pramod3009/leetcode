class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        d = {}
        for i in S:
            d[i] = d.get(i, 0) + 1
        count = 0
        for i in J:
            count+=d.get(i,0)
        return count
        