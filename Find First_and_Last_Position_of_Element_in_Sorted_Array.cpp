class Solution {
public:
    vector<int> searchRange(vector<int>& a, int target) {
        int low=0 ,mid=0, high=a.size()-1;
        vector<int>bound;
        
        while (low <= high) {
            mid = (low+high)/2;
            if (a[mid] == target){
                int i,j;
                for (i=mid; i>=0 and a[i]==target; i--);
                for (j=mid; j<a.size() and a[j]==target; j++);
                
                bound.push_back(i+1);
                bound.push_back(j-1);
                return bound;
            }
            else if(target<a[mid])
                high = mid-1;
            else
                low = mid+1;
        }
        //cout<<"reached";
        bound.push_back(-1);
        bound.push_back(-1);
        return bound;
    }
};