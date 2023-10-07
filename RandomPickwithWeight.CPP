class Solution {
public:
    vector<int> prefixSum;
    Solution(vector<int>& w) {
        for(auto &n : w)
            prefixSum.push_back(prefixSum.empty() ? n : n + prefixSum.back());
    }
    
    int pickIndex() {
        float randNum = (float) rand() / RAND_MAX;
        float target = randNum * prefixSum.back();
        return lower_bound(begin(prefixSum), end(prefixSum), target) - begin(prefixSum);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
