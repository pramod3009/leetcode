class Solution {
public:
    int binarySearch(vector<int>& numbers,int target){
        int left = 0;
        int right = numbers.size()-1;
        
        while(left<=right){
            int mid = (left+right)/2;
            if(numbers[mid]==target){
                return mid;
            } else if (numbers[mid]<target){
                left = mid+1;
            } else{
                right = mid - 1;
            }
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i;
        int mid;
        for(i = 0; i<numbers.size();i++){  
                mid = binarySearch(numbers, target - numbers[i]);
                if(mid!=-1 and mid!=i)
                    break;
               
        }
        
       std::vector<int> vec{i+1,mid+1};
       sort(vec.begin(),vec.end());
        return vec;
    }
};