class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        if rowIndex ==0:
            return [1]
        a=[1]
        for i in range(1,rowIndex+1):
            row = [1]
            for j in range(1,len(a)):
                row.append(a[j-1]+a[j])
            row.append(1)
            a[:] = []
            a = row
        return a
        
        