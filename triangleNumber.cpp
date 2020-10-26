class Solution {
public:
    
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<3){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int k = 0; k < nums.size() - 2; k++){
            
            int j = k + 2;
            for(int i = k + 1; i < nums.size() - 1 and nums[k]; i++){
                while(j < nums.size() and nums[k] + nums[i] > nums[j]){
                    j++;
                }
                res += j - i - 1;
            }
        }
        return res;
    }
};
