class Solution:
    def intervalIntersection(self, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
        i = 0 
        j = 0
        result = []
        n = len(A)
        m = len(B)
        while i<n and j<m:
            low = max(A[i][0],B[j][0])
            high = min(A[i][1],B[j][1])
            if low<=high:
                result.append([low,high])
            if A[i][1] < B[j][1]:
                i+=1
            else:
                j+=1
        return result
        