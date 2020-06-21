class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void helper(vector<int>& candidates, int target,int index){
        if(target==0){
            result.push_back(path);
            return;
        }
        for(int i= index;i<candidates.size();i++){
            if(candidates[i]>target){
                return;
            }
            path.push_back(candidates[i]);
            helper(candidates,target-candidates[i],i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        helper(candidates,target,0);
        return result;
    }
};