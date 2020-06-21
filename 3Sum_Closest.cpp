class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int length = nums.size();
        if(length == 0 or length<3){
            return -1;
        }
        sort(nums.begin(), nums.end());
        int closestSum = nums[0]+nums[1]+nums[2];
        for(int i=0;i<length;i++){
            int left = i+1;
            int right = length - 1;
            while(left < right){
                int sum = nums[i]+nums[left]+nums[right];
                if (abs(sum - target) < abs(closestSum - target)){
                    closestSum = sum;
                }
                if(sum < target){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return closestSum;
    }
};