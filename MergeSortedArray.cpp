class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        if (n==0) {
            return;
        }
         
        if(m==0) {
         for(int i = 0; i < n; i++) {
            nums1[i] = nums2[i];
         }
        }

        while(i>=0 && j >= 0) {
            if(nums2[j] >= nums1[i]){
                nums1[k] = nums2[j];
                print(nums1);
                j--;
            } else {
                nums1[k] = nums1[i];
                print(nums1);
                i--;
            }
            k--;
        }

        while(j >= 0 ) {
            nums1[k--] = nums2[j--];
        }
         
    }
    void print(vector<int> &nums) {
        for(auto n : nums) {
            cout<<n<<" ";
        }
        cout<<endl;
    }
};
