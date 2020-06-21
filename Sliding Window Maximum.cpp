class Solution {
public:
    vector<int> result;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size()<k){
            return result;
        }
        map<int,int>m;
        for(int i = 0; i < k; i++){
            m[nums[i]]++;
        }
        result.push_back(m.rbegin()->first);
        for(int i = k ;i < nums.size() ;i++){
            m[nums[i-k]]--;
            if(m[nums[i-k]]==0){
                m.erase(nums[i-k]);
            }
            m[nums[i]]++;
            result.push_back(m.rbegin()->first);
        }
        return result;
    }
};