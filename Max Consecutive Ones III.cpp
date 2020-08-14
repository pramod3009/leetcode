class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int windowStart = 0;
        int maxCount = 0;
        int maxLength = 0;
        for(int windowEnd = 0; windowEnd < A.size(); windowEnd++){
            if(A[windowEnd]){
                maxCount++;
            }
            while(windowEnd - windowStart - maxCount + 1 > K){
                if(A[windowStart]){
                    maxCount--;
                }
                windowStart++;
                
            }
            maxLength = max(maxLength, windowEnd - windowStart + 1);
        }
        return maxLength;
    }
};
