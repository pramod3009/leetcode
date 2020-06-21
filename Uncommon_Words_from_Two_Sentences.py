class Solution:
    def uncommonFromSentences(self, A: str, B: str) -> List[str]:
        d1 = {}
        d2 = {}
        A = A.strip().split()
        B = B.strip().split()
        result = []
        for i in A:
            d1[i] = d1.get(i,0) + 1
        for i in B:
            d2[i] = d2.get(i,0) + 1
        for key in list(d1.keys()):
            if not d2.get(key,0) and d1[key]==1:
                result.append(key)
        for key in list(d2.keys()) :
            if not d1.get(key,0) and d2[key]==1:
                result.append(key)
        return result