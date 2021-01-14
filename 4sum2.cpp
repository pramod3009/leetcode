class Solution {
public:
    int result = 0;
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int, int> absumcount;
        for(auto &a : A){
            for(auto &b : B){
                absumcount[a + b]++;
            }
        }
        for(auto &c : C){
            for(auto &d : D){
                if(absumcount.find(-1 * (c+d)) != absumcount.end()){
                    result += absumcount[-1 * (c+d)];
                }
            }
        }
        return result;
    }
};
