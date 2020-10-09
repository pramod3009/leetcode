class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int>s;
        for(const auto &num : A){
            s.insert(num);
        }
        vector<int> ret;
        for(const auto &num : B){
            auto it = s.upper_bound(num);
            if(it==s.end()){
                it = s.begin();
            }
            ret.push_back(*it);
            s.erase(it);
        }
        return ret;
    }
};
