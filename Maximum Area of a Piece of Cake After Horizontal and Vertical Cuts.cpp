class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        long maxh = max(horizontalCuts[0], h - horizontalCuts.back());
        for(int i = 1; i < horizontalCuts.size(); i++){
            maxh = max(maxh, long(horizontalCuts[i] - horizontalCuts[i - 1]));
        }
        
        long maxw = max(verticalCuts[0], w - verticalCuts.back());
        for(int i = 1; i < verticalCuts.size(); i++){
            maxw = max(long(verticalCuts[i] - verticalCuts[i-1]), maxw);
        }
        cout<<maxh<<" "<<maxw<<endl;
        return (int)((maxh * maxw)%1000000007);
    }
};
