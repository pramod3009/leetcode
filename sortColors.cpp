class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros= 0;
        int ones = 0;
        int twos = 0;
        for(auto num : nums){
            switch(num){
                case 0:
                    zeros++;
                    break;
                case 1:
                    ones++;
                    break;
                case 2:
                    twos++;
                    break;
            }
        }
        cout<<zeros<<ones<<twos;
        fill(nums.begin(), nums.begin() + zeros, 0);
        fill(nums.begin() + zeros, nums.begin() + zeros + ones, 1);
        fill(nums.begin() + zeros + ones, nums.end(), 2);
    }
}; 
