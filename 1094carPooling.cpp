bool comparator(vector<int> &a, vector<int> &b){
    if(a[1] == b[1]){
        return a[2] < b[2];
    }
    return a[1] < b[1];
}
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
       sort(trips.begin(), trips.end(), comparator);
       priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({trips[0][2], trips[0][0]});
        int currCapacity = capacity - trips[0][0];
        
        for(int i = 1; i < trips.size(); i++){
            if(currCapacity - trips[i][0] < 0){
                while(!pq.empty() and pq.top().first <= trips[i][1]){
                    auto p = pq.top();
                    pq.pop();
                    currCapacity += p.second;
                }
            }
            
            if(currCapacity - trips[i][0] < 0){
                return false;        
            } else {
                currCapacity -= trips[i][0];
                pq.push({trips[i][2], trips[i][0]});
            }
        }
        return true;
    }
};
