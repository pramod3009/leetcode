bool comparator(vector<int>&a, vector<int> &b){
        return a[1] < b[1];
    }
class Solution {
public:
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        if(not trips.size() and capacity){
            return false;
        }
        if(not capacity){
            return true;
        }
        vector<int>passengers(1001, 0);
        for(const auto &trip : trips){
            passengers[trip[1]]+=trip[0];
             passengers[trip[2]]-=trip[0];
        }
        int local_capacity = 0;
        for(auto const &num : passengers){
            local_capacity += num;
            if(local_capacity > capacity){
                return false;
            }
        }
        return true;
    }
    
};
