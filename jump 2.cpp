class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);
        int n = nums.size();
        dp[n -1] = 0;
        for(int i = n-2; i>=0; i--){
            int temp = nums[i] + i;
            int maxindex = min(temp, n - 1);
            for(int j = i + 1; j<=maxindex; j++){
                if(dp[j]!=INT_MAX){
                    dp[i] = min(dp[i], 1 + dp[j]);
                }
            }
        }
        // for(const auto num : dp){
        //     cout<<num<<" ";
        // }
        return dp[0];
    }
};

class Solution {
public:
    int jump(vector<int>& nums) {
        int currmax = 0, dest = 0, steps = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            dest = max(dest, nums[i] + i);
            if(currmax==i){
                currmax = dest;
                steps++;
            }
        }
        return steps;
    }
};
