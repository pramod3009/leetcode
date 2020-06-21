class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        
        d = {}
        result = []
        for i in nums:
            d[i] = d.get(i,0)+1
        ordered = sorted(d,key=d.get,reverse=True)
        if len(ordered)<k:
            return 
        for i in range(k):
            result .append(ordered[i])
        return result
        