class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        if(not n){
            return 0;
        }
        
        int i = 0;
        int j = n - 1;
        int boats = 0;
        sort(people.begin(), people.end());
        while(i <= j){
            if(people[i] + people[j] <= limit){
                i++;
                j--;
            } else{
                j--;
            }
            boats++;
        }
        return boats;
    }
};
