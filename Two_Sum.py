class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for i in range(0,len(nums)):
            d[nums[i]] = i
        for i in nums:
            if d.get(target-i,-1)!=-1:
                if i == target-i and nums.count(i)<2:
                    continue
                return [nums.index(i), d[target-i]] 
                
                