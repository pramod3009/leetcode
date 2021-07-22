class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        d = {}
        res = 0;
        for t in time:
            x = t % 60
            y = (60 - x) % 60
            res = res + d.get(y, 0)
            d[x] = d.get(x, 0) + 1
        return res
        
