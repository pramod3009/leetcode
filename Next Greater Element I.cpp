class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m;
        stack<int> s;
        for(int i = nums2.size()-1; i>=0; i--){
            while(not s.empty() and s.top()<nums2[i]){
                s.pop();
            }
            int next_greater = s.empty()?-1:s.top();
            m[nums2[i]] = next_greater;
            s.push(nums2[i]);
        }
        vector<int>result;
        for(int i = 0; i < nums1.size(); i++){
            result.push_back(m[nums1[i]]);
        }
        
        return result;
    }
};