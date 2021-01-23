bool comparator(string &a, string &b){
    return a + b > b + a;  
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        for(auto &num : nums){
            s.push_back(to_string(num));
        }
        sort(s.begin(), s.end(), comparator);
        string result = "";
        for(auto &num : s){
            result += num;
        }
       
        while(result.length() > 1 and result[0]=='0'){
            result.erase(0, 1);
        }
        return result;
    }
};
