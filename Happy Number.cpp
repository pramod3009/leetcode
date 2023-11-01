#include <cmath>

class Solution {
public:
    int nextNumber(int n) {
        int sum = 0;
        while(n > 0) {
            sum = sum + pow(n % 10, 2);
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slowPointer = n;
        int fastPointer = nextNumber(n);

        while(fastPointer != 1 and fastPointer != slowPointer) {
            slowPointer = nextNumber(slowPointer);
            fastPointer = nextNumber(nextNumber(fastPointer));
        }

        return fastPointer == 1;
    }
};
