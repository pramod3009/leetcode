#include <math.h>
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        if(not asteroids.size()){
            return result;
        }
        int n = asteroids.size();
        result.push_back(asteroids[0]);
        for(int i = 1; i < n; i++){
        
            if((result.size() and signbit(asteroids[i]))){
               if((result.size() and signbit(result.back()))){
                   result.push_back(asteroids[i]);
               } else {
                   int temp = asteroids[i];
                   int flag = 1;
                   while (result.size() and signbit(temp)==1 and signbit(result.back())==0){
                       
                        int num = result.back();
                        cout<<num<<" "<<temp;
                        result.pop_back();
                        if(abs(num)>abs(temp)){
                            temp = num;
                        } else if(abs(num)==abs(temp)){
                            flag = 0;
                            break;
                        } 
                   }
                   if(flag){
                        result.push_back(temp);
                   }
               } 
            } else {
                result.push_back(asteroids[i]);
            }
        
        } 
        return result;
    }

};