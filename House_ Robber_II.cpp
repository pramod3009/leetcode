class Solution {
public:
    int getmax(vector<int>&nums, vector<int>&dp, int i, int n){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        dp[i] = max(nums[i] + getmax(nums,dp,i+2,n),getmax(nums,dp,i+1,n));
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        vector dp0(n,-1);
        vector dp1(n,-1);
        return max(getmax(nums, dp0, 0, n-1), getmax(nums, dp1,1,n));
    }
};