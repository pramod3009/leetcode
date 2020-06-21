class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        votes_gotten = [0]*(N+1)
        votes_given = [0]*(N+1)
        for i in trust:
            votes_gotten[i[1]]+=1
            votes_given[i[0]]+=1
            
        for i in range(1,N+1):
            if votes_gotten[i]==(N-1) and votes_given[i]==0:
                return i
        return -1
        