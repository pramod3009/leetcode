class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& nums) {
        int ans = 0, mx = 0;
        for(int i = 0; i < nums.size();i++){
            ans = max(ans, mx + nums[i]-i);
            mx = max(mx, nums[i]+i);
        }
        return ans;
    }
};