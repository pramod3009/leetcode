class Solution {
public:
    int helper(vector<int>& weights, int capacity){
        int days = 0;
        int temp_sum = 0;
        for(auto num:weights){
            temp_sum+=num;
            if(temp_sum > capacity){
                temp_sum = num;
                days++;
            }
        }
        return ++days;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        if(!weights.size()){
            return -1;
        }
        int low = 0;
        int high = 0;
        for(auto num:weights){
            low = max(low, num);
            high = high + num;
        }
        low = max(low, high/D);
        while(low<=high){
            int mid = low + (high- low)/2;
            int cnt = helper(weights, mid);
            if(cnt<=D){
                high = mid - 1;
            } else {
                low = mid +1;
            }
        }
        return low;
    }
};
