class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(not nums.size()){
            return 0;
        }
        int n = nums.size();
        vector<int>csum;
        csum.push_back(nums[0]);
        for(int i = 1;i < n;i++){
           csum.push_back(csum[i-1]+nums[i]); 
        }
        int count = 0;
        for(int i = 0;i<n;i++){
            int lsum = csum[i];
            if (lsum == k ){
                count+=1;
            }
            for(int j =0;j<i;j++){
                lsum-=nums[j];
                if (lsum == k ){
                    count++;
                }
                    
            }
        }
        return count;
    }
};