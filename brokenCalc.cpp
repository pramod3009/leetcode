class Solution {
public:
    int brokenCalc(int x, int y) {
        int result = 0;
        while(y > x ){
            result++;
            y = y % 2 == 0 ? y / 2 : y + 1;
        }
        return result + x - y;
    }
};
