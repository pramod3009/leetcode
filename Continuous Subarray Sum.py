class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        if not len(nums) or len(nums)<2:
            return False
        csum = [nums[0]]
        n = len(nums)
        for i in range(1,n):
            csum.append(csum[i-1] + nums[i])
        
        for i in range(1,n):
            lsum = csum[i]
            if (lsum==0 and k==0) or (k and lsum % k == 0):
                return True
            for j in range(0,i-1):
                lsum = lsum- nums[j]
                if (lsum==0 and k==0) or (k and lsum % k == 0):
                    return True
               
        return False
        
        
        