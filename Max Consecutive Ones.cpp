class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int localCount = 0;
        for(auto num : nums){
            if(num) {
                localCount++;
            } else{
                maxCount = max(maxCount, localCount);
                localCount = 0;
            }
        }
        return max(maxCount, localCount);
    }
};
