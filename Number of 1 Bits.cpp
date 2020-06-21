class Solution {
public:
    int count;
    int hammingWeight(uint32_t n) {
        count = 0;
        while(n){
            count+=(n)&(0x1);
           n>>=1;
           cout<<n<<endl;     
        }
        return count;
    }
};