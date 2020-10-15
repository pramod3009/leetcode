class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left = 0;
        int right = 0;
        for(int i = 0; i < k; i++){
            left += cardPoints[i];
        }
        int result = left; 
        for(int i = 0 ; i < k; i++){
            right += cardPoints[cardPoints.size() - i - 1];
            left -= cardPoints[k - i -1 ];
            result = max(result, right + left);
        }
        return result;
    }
};
