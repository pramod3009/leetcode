class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days[days.size() - 1] + 1, 0);
        for(int i = 0 ; i < days.size(); i++){
            dp[days[i]] = INT_MAX;
        }
        for(int i = 1; i < days[days.size() - 1] + 1; i++){
            dp[i] = dp[i] == 0 ? dp[i - 1] : min(dp[max(0, i - 7)] + costs[1],min(dp[max(0, i - 1)] + costs[0],dp[max(0, i - 30)] + costs[2]));
        }
        return dp[days[days.size() - 1]];
    }
};
