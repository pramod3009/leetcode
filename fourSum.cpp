class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0 ; i < n; i++){
            if(i != 0 and nums[i]==nums[i - 1]){
                continue;
            }
            for(int j = i + 1; j < n; j++){
                if(j !=i+1 and nums[j]==nums[j - 1]){
                    continue;
                }
                int k = j + 1;
                int l = n - 1;
                while(k < l){
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if(target - sum == 0){
                        cout<<"hit"<<endl;
                        result.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        while(k < l and nums[k] == nums[k - 1]){
                            k++;
                            continue;
                        }
                    } else if (target > sum){
                        k++;
                    } else{
                        l--;
                    }
                }
            }
        }
        return result;
    }
};
