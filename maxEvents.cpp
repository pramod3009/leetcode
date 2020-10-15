bool compare(vector<int>&a, vector<int>&b){
    if(a[1] < b[1]){
        return true;
    }
    return a[1]==b[1] ? a[0] < b[0] : false;
}
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), compare);
        int result = 0;
        set<int> s;
        for(int i = 1; i <= events[events.size() - 1][1];i++){
            s.insert(i);
        }
        for(const auto &event : events){
          auto temp = s.lower_bound(event[0]);
           if(temp==s.end() or *temp > event[1]){
               continue;
           }else{
               result++;
               s.erase(*temp);
           }
        }
        return result;
    }
    
};
