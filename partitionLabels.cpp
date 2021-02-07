class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> m(26 ,0);
        for(int i = 0;i < s.length(); i++){
            m[s[i] - 'a'] = i;
        }
        
        int j = 0;
        int start = 0;
        vector<int> result;
        for(int i = 0; i < s.length(); i++){
            j = max(j, m[s[i] - 'a']);
            if(i == j){
                result.push_back( i - start + 1);
                start = i + 1;
            }
        }
        return result;
    }
};
