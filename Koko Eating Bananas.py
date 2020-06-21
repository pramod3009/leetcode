import math
class Solution:
    def find(self,mid,piles):
        time = 0
        for i in piles:
            time+=int(math.ceil(float(i)/float(mid)))
        return time
    def minEatingSpeed(self, piles: List[int], H: int) -> int:
        low = 1
        high = max(piles)
        while low<=high:
            mid = int((low+high)/2)
            time = self.find(mid,piles)
            if time>H:
                low = mid + 1
            else:
                high = mid -1
        return low