class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& nums) {
        if(not nums.size() or not nums[0].size()){
            return 0;
        }
        int n = nums.size();
        int m = nums[0].size();
        for(int i = 1 ;i < n; i++){
            for(int j = 0;j < m;j++){
                int t1 = INT_MAX, t2 = INT_MAX, t3 = INT_MAX;
                if(i-1>=0){
                    t1 = nums[i-1][j];
                }
                if(i-1>=0 and j-1>=0){
                    t2 = nums[i-1][j-1];
                }
                if(i-1>=0 and j+1<m){
                    t3 = nums[i-1][j+1];
                }
                
                nums[i][j] = nums[i][j] + min(t3,min(t1, t2)); 
                cout<<t1<<" "<<t2<<" "<<t3<<" "<<nums[i][j]<<endl;
                
            }
        }
        cout<<nums[n-1][0];
        int result = nums[n-1][0];
        for(int j=1;j<m;j++){
            result = min(result,nums[n-1][j]);
        }
        return result;
    }
};