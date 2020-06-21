class Solution {
public:
    string getPermutation(int n, int k) {
        std::string num;
        for(int i=1;i<=n;i++){
            num.append(std::to_string(i));
        }
        while(--k){
            std:next_permutation(num.begin(),num.end());
        }    
    return num;
        
    }
};