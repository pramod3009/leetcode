class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        d = {}
        missing = []
        for i in nums:
            d[i] = d.get(i,0) + 1
        for i in range(1,len(nums)+1):
            if not d.get(i,0):
                missing.append(i)
        return missing        
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(auto num : nums){
            if(nums[abs(num) - 1] > 0){
                nums[abs(num) - 1] = -1*nums[abs(num) - 1];
            }
            
        }
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]>0){
                result.push_back(i+1);
            }
        }
        return result;
    }
};
        
        
