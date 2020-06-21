class Solution {
public:
    void helper(vector<int>&nums,vector<vector<int>> &result,int l,int r){
        if(l==r){
            result.push_back(nums);
            return;
        }
        map<int,int> m;
        for(int i=l;i<=r;i++){
            if(m.find(nums[i])==m.end()){
                std::swap(nums[i],nums[l]);
                helper(nums,result,l+1,r);
                std::swap(nums[i],nums[l]);
                m[nums[i]]=1;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        if(not nums.size()){
            return result;
        }
        
        helper(nums,result,0,nums.size()-1);
        return result;
    }
};