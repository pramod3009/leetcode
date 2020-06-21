class Solution {
public:
    int countways(int n, std::map<int,int>&m){
        if(n<=0){
            return 0;
        } else if(n<=2){
            return n;
        }
        if(m.find(n)!=m.end()){
            return m[n];
        }
        m[n] = countways(n-1, m) + countways(n-2, m);
        return m[n];
    }
    int climbStairs(int n) {
        std::map<int,int>m;
        m[n] = countways(n,m);
         return m[n];
    }
};