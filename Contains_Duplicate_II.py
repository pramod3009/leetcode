class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        if not len(nums):
            return 0
        d = {}
        for i in range(0,len(nums)):
            result = d.get(nums[i],-1)
            if result!=-1:
                if i-result<=k:
                    return 1
                else:
                    d[nums[i]] = i
            d[nums[i]] = i
        return 0    
                    