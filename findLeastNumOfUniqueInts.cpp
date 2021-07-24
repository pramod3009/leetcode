
class Solution {
public:
    typedef pair<int, int> pi;
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> m;
        for(auto num : arr){
            m[num]++;
        }
        
        priority_queue<pi, vector<pi>, greater<pi>> q;
        for(auto it : m){
            q.push({it.second, it.first});
        }
        
        while(!q.empty()){
            auto p = q.top();
            k = k - p.first;
            if(k < 0){
                break;
            }
            q.pop();
            
        }
        return q.size();
    }
};
