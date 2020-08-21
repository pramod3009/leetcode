class Solution {
public:
    int longestMountain(vector<int>& A) {
        if(!A.size()){
            return 0;
        }
        int n = A.size();
        int left[n];
        int right[n];
        left[0] = 1;
        right[n - 1] = 1;
        for(int i = 1;i < n; i++){
            if(A[i] > A[i - 1]){
                left[i] = left[i - 1] + 1;
            } else {
                left[i] = 1;
            } 
        }
    
        for(int j = n - 2; j >= 0; j--){
            if(A[j] > A[j+1]){
                right[j] = right[j + 1] + 1;
            } else {
                right[j] = 1;
            }
        }
        int max = INT_MIN;
        for(int i = 0; i < n; i++){
            if(left[i] > 1 and right [i] > 1 ){
                max = std::max(max,right[i] + left[i] - 1);
            }
            
        }
        
        
        return max>=3?max:0;
    }
};

class Solution {
public:
    int longestMountain(vector<int>& A) {
        if(not A.size()){
            return 0;
        }
        int i = 0;
        int start = 0;
        int top = -1;
        int res = 0;
        int n = A.size();
        while(i < n){
            while(i < n-1 and A[i]>=A[i+1]){
                start++;
                i++;
            }
            if(i==n-1){
                break;
            }
            while(i < n-1 and A[i] < A[i+1]){
                i++;
                top = i;
                
            }
            while(i < n-1 and A[i] > A[i+1]){
                i++;
            }
            if(top < i){
                res = max(res, i - start + 1);
            }
            start = i;
        }
        return res;
    }
};
