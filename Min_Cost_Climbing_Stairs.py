import sys
class Solution:
    def sol(self,n,nums,dp):
        if n>=len(nums):
            return 0
        if dp[n]!=-1:
            return dp[n]
        dp[n] = nums[n] + min(self.sol(n+1,nums,dp),self.sol(n+2,nums,dp))
        return dp[n]
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp = [-1]*len(cost)
        return min(self.sol(0,cost,dp),self.sol(1,cost,dp))
        