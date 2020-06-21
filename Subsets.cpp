class Solution {
public:
    vector<vector<int>> result;
    void helper(vector<int>& nums, vector<int> temp,int index = 0){
        result.push_back(temp);
        for(int  i = index;i<nums.size();i++){
            temp.push_back(nums[i]);
            helper(nums,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        helper(nums,temp);
        return result;
    }
};