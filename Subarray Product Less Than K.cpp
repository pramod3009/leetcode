class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(not nums.size()){
            return 0;
        }
        int n = nums.size();
        int count = 0;
        int product = 1;
        int left = 0;
        for(int right = 0;right<n;right++){
            product = product*nums[right];
            while(product>=k and left<=right){
                product=product/nums[left++];
            }
            count+=right-left+1;
        }
        return count;
    }
};