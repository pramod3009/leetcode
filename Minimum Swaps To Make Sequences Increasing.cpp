class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        if(not A.size() or not B.size()){
            return -1;
        }
        int n = A.size();
        int swap [n]={1};
        int noswap [n]={0};
    
        for(int i=1;i<n;i++){
            swap[i]=noswap[i]=INT_MAX;
            if(A[i]>A[i-1] and B[i]>B[i-1]){
                noswap[i] = noswap[i-1];
                swap[i] = swap[i-1]+1;
            } if(A[i-1]<B[i] and A[i]>B[i-1]) {
                noswap[i] = min(noswap[i],swap[i-1]);
                swap[i] = min(noswap[i-1]+1,swap[i]);
            }
            
        }
        
        return min(swap[n-1],noswap[n-1]);
    }
};