class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN;
        long second = LONG_MIN;
        long third = LONG_MIN;
        for(int i=0; i<nums.size();i++){
            if (nums[i] > first) {
               third = second;
                second = first;
                first = nums[i];
            } else if(nums[i]>second and nums[i]!=first) {
              third = second;
              second = nums[i];  
            } else if(nums[i]>third and nums[i]!=second and nums[i]!=first){
                third = nums[i];
            }
            
        }
        //cout<<third<<" "<<second<<" "<<first;
        if(third == LONG_MIN)
            return first;
        return third;    
        
    }
};