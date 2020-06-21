class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int dp1[n]={0};
        int dp2[n]={0};
        dp1[0]=dp2[0]=arr[0];
        int ans = arr[0];
        for(int i = 1 ;i < n; i++){
            dp1[i] = max(dp1[i-1]+arr[i],arr[i]);
            dp2[i] = max(dp1[i-1], dp2[i-1]+arr[i]);
            ans = max(ans,max(dp1[i],dp2[i]));
        }
        return ans;
    }
};