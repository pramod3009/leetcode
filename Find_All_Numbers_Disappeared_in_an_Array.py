class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        d = {}
        missing = []
        for i in nums:
            d[i] = d.get(i,0) + 1
        for i in range(1,len(nums)+1):
            if not d.get(i,0):
                missing.append(i)
        return missing        
            
        
        