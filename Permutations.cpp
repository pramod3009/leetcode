class Solution {
public:
    void permuteNum(vector<int>& nums, int l, int r, vector<vector<int>> &result){
        if(l==r)
            result.push_back(nums);
        else {
            for(int i = l; i<=r; i++){
                std::swap(nums[l],nums[i]);
                permuteNum(nums,l+1,r,result);
                std::swap(nums[l],nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> result;
        if(!nums.size())
            return result;
        permuteNum(nums, 0,nums.size()-1,result);
        return result;
    }
};