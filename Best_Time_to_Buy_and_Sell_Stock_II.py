class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not len(prices):
            return 0
        maxprofit = 0
        cp = prices[0]
        n = len(prices)
        for i in range(1, n) :
            #print(maxprofit, cp, prices[i])
            if prices[i] < cp :
                cp = prices[i]
            elif i+1<n and prices[i+1]>prices[i]:
                continue
            else:
                maxprofit +=  prices[i] - cp
                cp = 33000
        return maxprofit  
        