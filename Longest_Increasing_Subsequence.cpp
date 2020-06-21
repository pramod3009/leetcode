class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (not nums.size()){
            return 0;
        }
        int lis[nums.size()]={0};
        lis[0]=1;
        for(int i=1;i<nums.size();i++){
            lis[i]=1;
            for(int j = 0;j<i;j++){
                if (nums[j]<nums[i]){
                    lis[i]=max(lis[i],lis[j]+1);
                }
            }
        }
     int result = 0;
        for(int i=0;i<nums.size();i++){
            result = max(result,lis[i]);
        }
        return result;
    }
};