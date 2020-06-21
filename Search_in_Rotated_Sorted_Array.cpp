class Solution {
public:
    int binarySearch(vector<int>& nums, int left, int right, int key){
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]==key){
                return mid;
            } else if(nums[mid] > key){
                if (nums[right]>=key and nums[right]<nums[mid]){
                    left = left + 1;
                } else {
                    right = mid -1;
                }
            } else {
                if(nums[left]<=key and nums[left] > nums[mid]){
                    right = mid -1 ;
                } else {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return binarySearch(nums,0,nums.size()-1,target);
        
    }
};