class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], k: int) -> int:
        n = len(customers)
        if k>n:
            return 0
        start = 0
        end = k-1
        result = 0
        for i in range(0,k):
            result+=customers[i]*grumpy[i]
        localsum = result
        i = k
        while i < n:
            localsum += customers[i]*grumpy[i] - customers[i-k]*grumpy[i-k]
            if localsum > result:
                result = localsum
                start = i-k+1
                end = i
            i+=1
        
        result = sum(customers[start:end+1])
        print(result,start,end)
        for i in range(0,n):
            if (i<start or i>end) and not grumpy[i]: 
                result += customers[i]
        return result
        