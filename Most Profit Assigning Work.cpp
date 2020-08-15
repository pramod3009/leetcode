bool compare(vector<int> &a, vector<int> &b){
    return a[0] < b[0];
}
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        if(!difficulty.size() or !profit.size() or !worker.size() or difficulty.size()!=profit.size()){
            return 0;
        }
        vector<vector<int>> combine;
        for(int i = 0; i < difficulty.size(); i++){
            combine.push_back({difficulty[i], profit[i]});
        }
        std::sort(combine.begin(),combine.end(),compare);
        for(int i = 0; i < difficulty.size(); i++){
            difficulty[i] = combine[i][0];
            profit[i] = combine[i][1];
        }
        std::sort(worker.begin(), worker.end());
        int n = worker.size();
        int m = difficulty.size();
        int i = 0;
        int j =0;
        int total_profit = 0;
        int max_profit = 0;
        while(i < n and j < m){
            if(worker[i] >= difficulty[j]){
                max_profit = max(max_profit, profit[j]);
                j++;
            } else {
                total_profit += max_profit;
                i++;
            }
        }
        if(i < n){
            total_profit += (n - i) * max_profit;
        }
        return total_profit;
    }
};
