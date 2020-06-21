class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        d = {}
        for i in nums:
            d[i] = d.get(i,0) + 1
        keys = list(d.keys())
        n = len(nums)
        for i in keys:
            if d[i] > int(n/2):
                return i
            
        