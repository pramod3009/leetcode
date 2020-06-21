class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sur = 0, def  = 0, start = 0;
        for(int i = 0; i < n; i++){
            sur = sur + gas[i] - cost[i];
            if(sur<0){
                def = def + sur;
                start = i + 1;
                sur = 0;
            }
        }
        return sur + def >=0 ? start : -1;
    }
};