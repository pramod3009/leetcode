bool comparator(vector<int> &a, vector<int> &b){
    if(a[0] == b[0]){
        return a[1] < b[1];
    }
    return a[0] < b[0];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& intervals) {
        if(intervals.size() == 0){
            return 0;
        }
        if(intervals.size() == 1){
            return 1;
        }
        sort(intervals.begin(), intervals.end(), comparator);
        int start = intervals[0][0];
        int end   = intervals[0][1];
        int result = 0;
        for(int  i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= end){
                start = max(start, intervals[i][0]);
                end = min(end, intervals[i][1]);
            } else {
                ++result;
                start = intervals[i][0];
                end = intervals[i][1];
            }    
        }
        
        return ++result;
    }
};
