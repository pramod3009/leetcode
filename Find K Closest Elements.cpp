class Solution {
public:
    vector<int> result;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size()-1;
        while (l < r-1) {
            int mid = l+(r-l)/2;
            if (x == arr[mid]) {r = mid;}
            else if (x > arr[mid]) {l = mid;}
            else {r = mid;}
        }
        while(k){
            if(l>=0 and r<=arr.size()-1){
                if(abs(arr[l]-x)<=abs(arr[r]-x)){
                    result.push_back(arr[l]);
                    l--;
                } else {
                    result.push_back(arr[r]);
                    r++;
                }
            } else if(r>=arr.size()){
                result.push_back(arr[l]);
                l--;
            } else if(l < 0) {
                result.push_back(arr[r]);
                r++;
            }
            
            k--;
        }
        std::sort(result.begin(),result.end());
        return result;
    }
};