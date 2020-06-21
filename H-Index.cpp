class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(not citations.size()){
            return 0;
        }
        sort(citations.begin(), citations.end());
        int hindex = 0;
        for(int i = citations.size() - 1; i >= 0 ; i--){
            if(hindex>=citations[i]){
                break;
            }
            hindex++;
        }
        return hindex;
    }
};