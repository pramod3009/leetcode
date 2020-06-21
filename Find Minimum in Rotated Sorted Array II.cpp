class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(not n){
            return -1;
        }
        int left = 0, right = n-1;
        while(left < right and nums[left]==nums[right]){
            right--;
        }
        nums.erase(nums.begin() + right + 1, nums.end());
        left = 0;
        right = nums.size() - 1;
        while(left < right){
            int mid = left + (right-left)/2;
            if(nums[mid]>nums[right]){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        return nums[left];
    }
};