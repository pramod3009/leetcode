class Solution {
public:
    char findTheDifference(string s, string t) {
        int d[26] = {0};
        char c;
        for(int i = 0; i < t.size(); i++){
            d[t[i] - 'a']++;
        }
        for(int i = 0;i < s.size(); i++){
            d[s[i]-'a']--;
        }
        for(int i=0; i < 26; i++){
            if(d[i]==1){
                c = char(i + 'a');
                break;
            }
        }
        return c;
    }
};