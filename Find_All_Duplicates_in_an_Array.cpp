class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for(int i = 0;i<nums.size();i++){
            while(nums[i]!=i+1 and nums[nums[i]-1]!=nums[i]){
                swap(nums[i], nums[nums[i]-1]);
            }
            
        }
        int c = 1;
        for(auto x:nums){
            if(x!=c){
                result.push_back(x);
            }
            c++;
        }
        sort(result.begin(),result.end());
        return result;
    }
};