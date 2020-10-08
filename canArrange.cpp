class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> dp(k ,0);
        for(const auto &n : arr){
            dp[((n % k) + k) % k]++;
        }
        if(dp[0] % 2 != 0){
            return false;
        }
        for(int i = 1; i < k; i++){
            if(dp[i] != dp[k - i]){
                return false;
            }
        }
        return true;
    }
};
