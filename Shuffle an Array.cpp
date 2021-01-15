class Solution {
public:
    vector<int>& nums;
    default_random_engine seed;
    Solution(vector<int>& nums): nums(nums) {
        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> temp(nums);
        for(int i = 0; i < nums.size(); i++){
            auto idx = uniform_int_distribution<int>(i, nums.size() - 1)(seed);
            swap(temp[i], temp[idx]);
        }
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
