class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> q;
        q.push({nums[0], 0});
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            while(!q.empty() and q.top().second <= i - k){
                q.pop();
            }
            q.push({nums[i], i});
            if(i >= k-1){
                result.push_back(q.top().first);
            }
        }
        return result;
    }
};
