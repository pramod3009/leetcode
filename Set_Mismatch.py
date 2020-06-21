class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        d = {}
        for i in nums:
            d[i] = 1+d.get(i,0)
        repeat = 0
        miss = 0
        n = len(nums)
        for i in range(1,n+1):
            if not d.get(i,0):
                miss = i
            elif d.get(i,0) == 2:
                repeat = i
        return [repeat,miss]
            