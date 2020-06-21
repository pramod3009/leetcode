class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(!coins.size()){
            return 0;
        }
        int n = coins.size();
        unsigned int table[amount+1];
        table[0] = 0;
        for(int i = 1;i <=amount;i++){
            table[i] = INT_MAX;
        }
        for(int i=1;i<=amount;i++){
            for(int j=0;j<n;j++){
                if(coins[j]<=i){
                    table[i] = std::min(table[i],1+table[i-coins[j]]);
                }
            }
        }
        if(table[amount]==INT_MAX){
            return -1;
        }
        return table[amount];
    }
};