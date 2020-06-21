class Solution {
public:
    int binarySearch(vector<int>& nums,int key){
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while(left<=right){
            mid = (left+right)/2;
            if(nums[mid]==key){
                return mid;
            } else if (nums[mid]<key){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if(nums[mid]>key and mid==0)
            return mid;
        else if (nums[mid]>key)
           return mid;
        else 
            return mid+1;
    }
    int searchInsert(vector<int>& nums, int target) {
        
        return binarySearch(nums,target);
    }
};