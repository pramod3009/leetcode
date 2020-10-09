class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        int low = 0;
        int high = tokens.size() - 1;
        int currtokens = 0;
        int maxtokens = 0;
        while(low <= high){
            if(tokens[low]>=P and currtokens == 0){
                return maxtokens;
            }
            if(tokens[low]>P){
                currtokens--;
                P+=tokens[high--];
            }
            if(tokens[low] <= P){
                P-=tokens[low++];
                currtokens++;
            }
            maxtokens = max(maxtokens, currtokens);
        }
        return maxtokens;
    }
};
