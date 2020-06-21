class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows==0:
            return []
        if numRows==1:
            return [[1]]
        a=[[1]]
        for i in range(1,numRows):
            row = [1]
            last = a[-1]
            for j in range(1,len(last)):
                row.append(last[j]+last[j-1])
            row.append(1)
            a.append(row)
        return a
        
        