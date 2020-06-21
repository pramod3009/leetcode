class Solution:
    def rob_dp_sol(self,n:int,nums:List[int],dp:List[int]) -> int:
        if n>=len(nums):
            return 0
        if dp[n]!=-1:
            return dp[n]
        dp[n] = nums[n] + max(self.rob_dp_sol(n+2,nums,dp), self.rob_dp_sol(n+3,nums,dp))
        return dp[n]
    def rob(self, nums: List[int]) -> int:
        dp = [-1]*len(nums)
        return max(self.rob_dp_sol(0,nums,dp),self.rob_dp_sol(1,nums,dp))
      
        
        