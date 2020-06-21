class Solution {
public:
    int binarySearch(vector<int> &nums){
        int left = 1, right = nums.size()-2;
        if (nums.size() == 1){
            return 0;
        }
        if (nums[0]>nums[1])
            return 0;
        if(nums[nums.size()-1]>nums[nums.size()-2])
            return nums.size()-1;
        while(left<=right){
            int mid = left + (right - left)/2;
            if(nums[mid] > nums[mid-1] and nums[mid]>nums[mid+1])
                return mid;
            else if(nums[mid-1]<nums[mid] and nums[mid]<nums[mid+1]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return -1;
    }
    int findPeakElement(vector<int>& nums) {
        if (not nums.size()){
            return -1;
        }
       return binarySearch(nums);
        
    }
};