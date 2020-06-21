class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        newNums = list(set(nums))
        return len(newNums) != len(nums)
        