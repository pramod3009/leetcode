class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        if(not n or not m){
            return 0;
        }
        int i = 0, j = 0;
        int kids = 0;
        std::sort(g.begin(), g.end());
        std::sort(s.begin(),s.end());
        while(i<n and j<m){
            if(s[j]>=g[i]){
                kids++;
                j++;
                i++;
            } else {
                j++;
            }
        }
        return kids;
    }
};