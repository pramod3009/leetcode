class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (not nums.size()){
            return 0;
        }
        int t = nums[0];
        int h = nums[0];
        do{
            t = nums[t];
            h = nums[nums[h]] ;
        }while(t != h);
        int p1 = nums[0];
        int p2 = t;
        while(p1!=p2){
            p1 = nums[p1];
            p2 = nums[p2];
        }
        return p1;
        
        
    }
};