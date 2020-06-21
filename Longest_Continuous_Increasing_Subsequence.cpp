class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        int n = nums.size();
        if(!n)
            return 0;
        int result = 0;
        int local_result = 1;
        for(int i=1;i<n;i++){
           if(nums[i]>nums[i-1]){
               local_result++;
           } else {
               if (local_result>result){
                   result = local_result;
                   
               }
               local_result = 1;
           }
        }
        return max(result,local_result);
    }
};