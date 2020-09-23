class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> m;
        for(int i = 0; i < groupSizes.size(); i++){
            m[groupSizes[i]].push_back(i);
        }
        for(auto it = m.begin(); it!=m.end(); it++){
            int size = it->first;
            vector<int> temp;
            int count = 0;
            for(auto num : it->second){
                
                if(size==count){
                    result.push_back(temp);
                    
                    count = 0;
                    temp.clear();
                }
                temp.push_back(num);
                count++;
            }
            result.push_back(temp);
        }
        return result;
    }
};
