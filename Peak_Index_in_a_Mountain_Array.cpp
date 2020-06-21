class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int left = 1, right = A.size();
        while(left<=right){
            int mid = left + (right-left)/2;
            if(A[mid]>A[mid-1] and A[mid]>A[mid+1]){
                return mid;
            } else if(A[mid-1]<A[mid] and A[mid]<A[mid+1]){
                left = mid +1;
            } else {
                right = right -1;
            }
        }
        return -1;
    }
};