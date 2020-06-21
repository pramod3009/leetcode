class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int result = 0;
        for(int i = 31;i>=0;i--){
            int a = (m>>i) % 2;
            int b = (n>>i) % 2;
            if(a==b){
                result+=a<<i;
            } else{
                break;
            }
        }
        return result;
    }
    
};