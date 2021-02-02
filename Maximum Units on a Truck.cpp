bool comparator(vector<int> &a, vector<int> &b){
        return a[1] > b[1];
    }
class Solution {
public:
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comparator);
        
        int result = 0;
        for(auto temp : boxTypes){
            int x = temp[0];
            if(truckSize < x){
                x = truckSize;
                truckSize = 0;
            }
            result += x * temp[1];
            truckSize -= x;
            if(truckSize <=0 ){
                break;
            }
        }
        return result;
    }
};
