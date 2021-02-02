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


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            while(!q.empty() and q.front() <= i - k){
                q.pop_front();
            }
            while(!q.empty() and nums[q.back()] <= nums[i]){
                q.pop_back();
            }
            q.push_back(i);
            if(i >= k - 1){
                result.push_back(nums[q.front()]);
            }
        }
        return result;
    }
};
