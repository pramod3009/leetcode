class Solution {
public:
    set<string> result;
    int capacity;
    void populate(vector<int> &clock){
        int hrs = 8*clock[0] + 4*clock[1] + 2*clock[2] + clock[3];
        if(hrs > 11){
            return;
        }
        int mins = 32*clock[4] + 16*clock[5] + 8*clock[6] + 4*clock[7] + 2*clock[8] + clock[9];
        if(mins > 59){
            return;
        }
        string time = to_string(hrs);
        if(mins<10){
            time = time + ':'+ '0' + to_string(mins);
        } else {
            time = time + ':' + to_string(mins);
        }
        result.insert(time);
    }
    void helper(vector<int> &clock, int index, int on){
        if(on==capacity){
            populate(clock);
            return;
        }
        for(int i = index; i < 10; i++){
            clock[i] = 1;
            helper(clock, i+1, on + 1);
            clock[i] = 0;
            helper(clock, i+1, on);
        }
    }
    vector<string> readBinaryWatch(int num) {
        vector<int> clock(10,0);
        capacity = num;
        helper(clock, 0, 0);
        vector<string> final_result;
        for(std::set<string>::iterator it = result.begin();it != result.end(); it++){
            final_result.push_back(*it);
        }
        return final_result;
    }
};