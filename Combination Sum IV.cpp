class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        if(not nums.size()){
            return 0;
        }
        unsigned int dp[target+1] = {0};
        dp[0] = 1;
        for(int i=1;i<=target;i++){
            for(auto num:nums){
                if(i>=num){
                    dp[i] = dp[i] + dp[i-num];
                }
            }
        }
        
            
        return dp[target];
    }
};