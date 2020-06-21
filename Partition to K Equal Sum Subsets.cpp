class Solution {
public:
    bool checkPartition(int index, int k, int localsum, int targetsum, vector<bool> &used, vector<int>& nums){
        if(k==1){
            return true;
        }
        if(localsum==targetsum){
            return checkPartition(0,k-1,0,targetsum,used,nums);
            
        }
        
        for(int i = index;i<nums.size();i++){
            if(not used[i] and localsum+nums[i]<=targetsum){
                used[i] = true;
                if(checkPartition(i+1,k,localsum+nums[i],targetsum,used,nums)){
                    return true;
                }
                used[i] = false;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto &u:nums){
            sum+=u;
        }
        if(k > sum or sum%k!=0){
            return false;
        }
        vector<bool> used(nums.size(),false);
        return checkPartition(0,k,0,sum/k,used,nums);
    }
};