class Solution:
    def numSubarraysWithSum(self, A: List[int], S: int) -> int:
        prefixArray = [0]
        for i in A:
            prefixArray.append(prefixArray[-1] + i)
        d = {}
        ans = 0
        for i in prefixArray:
            ans+=d.get(i,0)
            d[i+S] = d.get(i+S,0) + 1
        return ans
