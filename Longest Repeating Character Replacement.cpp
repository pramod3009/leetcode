//Watched youtube video before solving - https://www.youtube.com/watch?v=00FmUN1pkGE
class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {0};
        int windowStart = 0;
        int maxCount = 0;
        int maxLength = 0;
        for(int windowEnd = 0; windowEnd < s.size(); windowEnd++){
            count[s[windowEnd] - 'A']+=1;
            maxCount = max(maxCount, count[s[windowEnd]-'A']);
            while(windowEnd - windowStart - maxCount + 1 > k){
                count[s[windowStart] - 'A']-=1;
                windowStart++;
            }
            maxLength = max(maxLength, windowEnd - windowStart  + 1);
        }
        return maxLength;
    }
};
