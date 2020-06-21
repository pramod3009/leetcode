class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        if not nums:
            return 0
        dp = [0]*10001
        for i in nums:
            dp[i]+=i
        for i in range(2,10001):
            dp[i] = max(dp[i]+dp[i-2],dp[i-1])
        return dp[10000]
            
        
        