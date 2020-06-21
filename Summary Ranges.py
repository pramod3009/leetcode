class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if not len(nums):
            return []
        result = []
        start = 0
        n = len(nums)
        for i in range(1,n):
            if nums[i]-nums[i-1]!=1:
                if i - start -1!=0:
                    result.append(str(nums[start])+"->"+str(nums[i-1]))
                else:
                    result.append(str(nums[start]))
                start = i
        if start==n-1:
            result.append(str(nums[start]))
        elif start ==0 or start<n-1:
            result.append(str(nums[start])+"->"+str(nums[n-1]))
            
        return result
            
        