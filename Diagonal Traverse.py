class Solution:
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        result = []
        if not matrix or not matrix[0]:
            return result
        m = len(matrix)
        n = len(matrix[0])
        q = [[0,0]]
        flag = 1
        d = {str(0)+" "+str(0):1}
        while len(q):
            if not flag:
                size = len(q)
                for i in range(size):
                    r,c=q.pop(0)
                    result.append(matrix[r][c])
                    if c+1 < n and not d.get(str(r)+" "+str(c+1), 0):
                        q.append([r,c+1])
                        d[str(r)+" "+str(c+1)] = 1
                    if r+1<m and not d.get(str(r+1)+" "+str(c), 0):
                        q.append([r+1,c])
                        d[str(r+1)+" "+str(c)] = 1
                flag = 1
            else:
                size = len(q)
                for i in range(size):
                    r,c=q.pop()
                    result.append(matrix[r][c])
                    if r+1<m and not d.get(str(r+1)+" "+str(c),0):
                        q.insert(0,[r+1,c])
                        d[str(r+1)+" "+str(c)] = 1
                    if c+1 < n and not d.get(str(r)+" "+str(c+1), 0):
                        q.insert(0,[r,c+1])
                        d[str(r)+" "+str(c+1)] = 1 
                flag = 0
        return result
        
        