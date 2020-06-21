class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        zeros = 0
        ones = 0
        twos = 0
        for i in nums:
            if i == 0:
                zeros+=1
            elif i == 1:
                ones+=1
            else:
                twos+=1
        for i in range(0,zeros):
            nums[i] = 0
        for i in range(zeros,zeros+ones):
            nums[i] = 1
        for i in range(zeros+ones,zeros+ones+twos):
            nums[i] = 2
        return nums