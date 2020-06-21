class Solution {
public:
    vector<vector<int>> result;
    void helper(vector<int>& nums, vector<int> temp,int index = 0){
        result.push_back(temp);
        for(int  i = index;i<nums.size();i++){
            if(not(i>index and nums[i]==nums[i-1])){
                temp.push_back(nums[i]);
                helper(nums,temp,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(),nums.end());
        helper(nums,temp);
        return result;
    }
};