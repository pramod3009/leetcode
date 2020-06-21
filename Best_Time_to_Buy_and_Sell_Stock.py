class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not len(prices):
            return 0
        maxprofit = 0
        cp = prices[0]
        for i in range(1, len(prices)):
            if prices[i] < cp :
                cp = prices[i]
            else:
                maxprofit = max(maxprofit, prices[i] - cp)
        return maxprofit        
        
        
        