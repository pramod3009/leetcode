class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> res(nums.size(), 0);
        
        for(int i = 2 * nums.size() - 1; i >= 0; i--){
            while(!s.empty() and nums[s.top()]<=nums[i % nums.size()]){
                s.pop();
            }
            res[i % nums.size()] = s.empty()? -1 : nums[s.top()];
            s.push(i % nums.size());
        }
        return res;
    }
};
