class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        if sum(nums)%2!=0:
            return False
        d = {}
        
        return self.canPartitionHelper(nums, 0 , 0, d, sum(nums))
    def canPartitionHelper(self, nums, index, lsum, d, total):
        if lsum > total/2 or index>=len(nums):
            return False
        if 2*lsum == total:
            return True
        current = str(index) + " " + str(lsum)
        if d.get(current,-1)!=-1:
            return d[current]
        found = self.canPartitionHelper(nums, index+1, lsum, d, total) or self.canPartitionHelper(nums, index+1, lsum + nums[index], d,total)
        d[current] = found
        return found
        