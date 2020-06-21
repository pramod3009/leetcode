class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = set()
        nums.sort()
        length = len(nums)
        for i in range(0,length):
            left = i+1;
            right= length-1
            while(left<right):
                localSum = nums[i]+nums[left]+nums[right];
                if(localSum==0):
                    res.add((nums[i],nums[left],nums[right]))
                if localSum<0:
                    left+=1
                else:
                    right-=1
        return list(res)
                
        