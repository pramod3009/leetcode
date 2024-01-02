class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> capitalToProfits;

        int projects = profits.size();
        priority_queue<int> profits_queue;
        for(int i = 0 ; i < projects; i++) {
            capitalToProfits.push_back({capital[i], profits[i]});
        }

        sort(capitalToProfits.begin(), capitalToProfits.end());
        int i = 0;
        while(k--) {
            while(i < projects && capitalToProfits[i].first <= w) {
                profits_queue.push(capitalToProfits[i++].second);
            }
            if(profits_queue.size() == 0) {
                return w;
            }
            w = w + profits_queue.top();
            profits_queue.pop();
        }

        return w;
    }
};
