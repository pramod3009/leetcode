class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        if(!arr.size() or k==0){
            return 0;
        }
        int sum = 0;
        int result = 0;
        int copy_k = k;
        for(int i = 0; i < arr.size(); i++){
            if(k){
                sum = sum + arr[i];
                k--;
            } else {
                if(sum/copy_k >= threshold){
                    result++;
                }
                sum = sum + arr[i] - arr[i - copy_k];
            }
        }
        if(sum/copy_k >= threshold){
            result++;
        }
        return result;
    }
};
