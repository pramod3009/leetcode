class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        if len(nums)==1:
            return 0
        rightsum = sum(nums)
        leftsum = 0
        for i in range(0,len(nums)):
            rightsum-=nums[i]
            if rightsum==leftsum:
                return i
            leftsum+=nums[i]
        return -1
        