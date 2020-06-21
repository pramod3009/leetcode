class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> result;
        if(!n or !m){
            return result;
        }
        k = min(k,n*m);
        pair<int,int> index;
        index = {0,0};
        priority_queue<p,vector<p>,greater<p>> q;
        q.push({nums1[0] + nums2[0],index});
        set<pair<int,int>> s;
        s.insert({0,0});
        for(int i = 0; i < k; i++){
            auto val = q.top();
            q.pop();
            int l = val.second.first;
            int m = val.second.second;
            result.push_back({nums1[l],nums2[m]});
            if(l + 1 < nums1.size() and m < nums2.size() and s.find({l+1,m})==s.end()){
                q.push({nums1[l+1]+nums2[m],{l+1,m}});
                s.insert({l+1,m});
            }
            if(l < nums1.size() and m+1 < nums2.size() and s.find({l,m+1})==s.end()){
                q.push({nums1[l]+nums2[m+1],{l,m+1}});
                s.insert({l,m+1});
            }
        }
        return result;
    }
};