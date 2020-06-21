class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        if not len(nums):
            return nums
        n = len(nums)
        left = []
        right = []
        product = 1
        for i in nums:
            product *=i
            left.append(product)
        product = 1
        for i in range(n-1,-1,-1):
            product *=nums[i]
            right.insert(0,product)
        for i in range(0,n):
            if i==0:
                nums[i] = right[1]
            elif i==n-1:
                nums[n-1] = left[n-2]
            else:
                nums[i] = left[i-1] * right[i+1]
        return nums
                    
            
            