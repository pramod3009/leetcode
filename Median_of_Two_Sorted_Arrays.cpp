
class Solution {
public:
    void mergeTwoSortedArrays(vector<int>& nums1, vector<int>& nums2, vector<int>& merge)
    {
      vector<int>::iterator itr1 = nums1.begin(),itr2 = nums2.begin();
      while(itr1!=nums1.end() && itr2!=nums2.end()){
        if (*itr1 < *itr2 ) {
           merge.push_back(*itr1);
           itr1++; 
        } else if(*itr1 > *itr2) {
          merge.push_back(*itr2);
          itr2++;  
        } else {
          merge.push_back(*itr1);
          merge.push_back(*itr2);
          itr1++;itr2++;  
        }
      }
      while(itr1!=nums1.end()) {
         merge.push_back(*itr1);
         itr1++; 
      }
      while(itr2!=nums2.end()) {
        merge.push_back(*itr2);
        itr2++;  
      }  
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      vector<int> merge;
      mergeTwoSortedArrays(nums1, nums2, merge); 
      //for(vector<int>::iterator it = merge.begin(); it!=merge.end();it++){
        //  cout<<*it<<" ";
      //}  
      if (merge.size()%2!=0) {
         int index = (int)(merge.size()/2);
         return merge.at(index); 
      } else {
        int index = merge.size()/2;
        
        int num1 =    merge.at(index-1); 
        int num2 =   merge.at(index);
        double result = ((double)num1+(double)num2)/2;
        return result;   
      }
        
    }
};