class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            return "";
        }
        return helper(strs, 0, strs.size() - 1);
    }
    string helper(vector<string>& strs, int l, int r){
        
        if(l == r){
            return strs[l];
        } else {
            int mid = (l + r)/2;
            string left = helper(strs, l, mid);
            string right = helper(strs, mid + 1, r);
           return commonPrefix(left, right);
        } 
    }
    string commonPrefix(string left, string right){
        int minl = min(left.length(), right.length());
        for(int i = 0; i < minl; i++){
            if(left[i] != right[i]){
                return left.substr(0, i);
            }
        }
        return left.substr(0, minl);
    }
};
