class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int mid, left=0 ,right = nums.size() - 1;
        if(not nums.size())
            return false;
        while(left<right and nums[left]==nums[right]){
            right--;
        }
        nums.erase(nums.begin()+right+1,nums.end());
        left = 0;
        right = nums.size() - 1;
        while(left < right){
            mid = left + (right-left)/2;
            if(nums[mid]>nums[right]){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        //cout<<left<<right;
        if(target>=nums[left] and target<=nums[nums.size()-1]){
            right = nums.size()-1;
        } else {
            left = 0;
            //right = right - 1;
        }
       // cout<<left<<" "<<right;
        while(left<=right){
            mid = left + (right-left)/2;
            if(nums[mid]==target)
                return true;
            else if (target>nums[mid]){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};