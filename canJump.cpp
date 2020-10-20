#include<algorithm>
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(), -1);
        dp[nums.size() - 1] = 1;
        for(int i = nums.size() - 2; i>=0; i--){
            int temp = i + nums[i];
            int maxjump = min(temp , int(nums.size() - 1));
            for(int j = i + 1; j <= maxjump; j++){
                if(dp[j]==1){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[0] == 1 ? true : false;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastbest = nums.size() - 1;
        for(int i = nums.size() - 1;i>=0;i--){
            if(i + nums[i] >= lastbest){
                lastbest = i;
            }
        }
        return lastbest == 0;
    }
};
