import sys
class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        
        if not len(nums) or s==0:
            return 0
        
        left = 0
        gsum = 0
        right = 0
        n = len(nums)
        length = sys.maxsize
        while right < n:
            gsum+=nums[right]
            while(gsum>=s) and left<=right:
                length = min(length,right-left+1)
                gsum-=nums[left]
                left+=1
            right+=1
        if length == sys.maxsize:
            return 0
        return length