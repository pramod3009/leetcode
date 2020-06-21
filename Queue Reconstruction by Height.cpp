bool compare(vector<int> a,vector<int> b){
       return a[0]==b[0]?a[1]<b[1]:a[0]>b[0];
    }
class Solution {
public:
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),compare);
        cout<<"done";
        vector<vector<int>> result;
        for(auto x:people){
            result.insert(result.begin()+x[1],x);
        }
        return result;
    }
};