class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k<0 or nums.size()<2){
            return 0;
        }
        set<pair<int,int>> s;
        std::sort(nums.begin(), nums.end());
        int i = 0, j = 1;
        while(i < nums.size() and j < nums.size()){
            if(nums[j]-nums[i]==k and i!=j){
                s.insert({nums[i], nums[j]});
                j++;
            } else if(nums[j] - nums[i] < k){
                j++;
            } else {
                i++;
            }
        }
        return s.size();
    }
};