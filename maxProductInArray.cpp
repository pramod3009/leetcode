class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(!nums.size()){
            return 0;
        }
        
        int maxsub = nums[0];
        int minsub = nums[0];
        int result = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < 0){
                swap(maxsub, minsub);
            }
            maxsub = max(nums[i], maxsub * nums[i]);
            minsub = min(nums[i], minsub * nums[i]);
            result = max(maxsub, result);
        }
        return result;
    }
};
