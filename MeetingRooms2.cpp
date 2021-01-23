bool comparator(vector<int> &a, vector<int> &b){
    if(a[0] == b[0]){
        return a[1] < b[1];
    }
    return a[0] < b[0];
}
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
         if(intervals.size() == 1){
            return 1;
        }
        sort(intervals.begin(), intervals.end(), comparator);
        priority_queue <int, vector<int>, greater<int> > pq;
        int result = 1;
        pq.push(intervals[0][1]);
        for(int i = 1; i < intervals.size(); i++){
            
           
            if(intervals[i][0] >= pq.top()){
                pq.pop();
            } else{
                result++;
            }
            pq.push(intervals[i][1]);
        }
        return result;
    }
};
