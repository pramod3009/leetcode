class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adjList[manager.size()];
        queue<pair<int, int>> q;

        for(int i = 0; i < manager.size(); i++) {
            if(manager[i] != -1) {
                 adjList[manager[i]].push_back(i);
            }
        }

        q.push({headID, informTime[headID]});

        int timeRequired = INT_MIN;
        while(!q.empty()) {
            auto manager = q.front();
            q.pop();

            timeRequired = max(timeRequired, manager.second);

            for(auto reportee : adjList[manager.first]) {
                q.push({reportee, manager.second + informTime[reportee]});
            }

        }

        return timeRequired;

    }
};
