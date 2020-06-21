class Solution:
    def arrangeCoins(self, n: int) -> int:
        if n==0:
            return 0
        row = 1
        count = 0
        while(n>=0):
            n = n - row
            row+=1
            if n>=0:
                count+=1
            else:
                break
        return count
            