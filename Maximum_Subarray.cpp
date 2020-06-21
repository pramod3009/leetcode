class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int max_sum = INT_MIN;
        int i = 0;
        int j = 0;
        for(;j<n;j++){
            sum = sum+nums[j];
            if(sum > max_sum) {
                max_sum = sum;
            }
            while(sum<=0 && i<=j){
                
                sum-=nums[i];
                i++;
            }
            
            
        }
        return max_sum;
    }
};