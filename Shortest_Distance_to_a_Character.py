class Solution:
    def shortestToChar(self, S: str, C: str) -> List[int]:
        result = []
        a =[]
        for i in range(len(S)):
            if S[i] == C:
                a.append(i)
        i = 0
        length = len(S)
        for i in range(len(S)):
            r = length+1
            for j in a:
                r = min(r,abs(i-j))
            result.append(r)
        return result        
        