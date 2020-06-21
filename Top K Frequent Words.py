class Solution:
    def topKFrequent(self, words: List[str], K: int) -> List[str]:
        d = {}
        rd = {}
        for i in words:
            d[i] = d.get(i,0) + 1
            
        keys = list(d.keys())
        result = []
        for i in keys:
            a = rd.get(d[i],[])
            a.append(i)
            rd[d[i]]=a
        keys = list(rd.keys())
        keys.sort()
        keys = keys[::-1]
        for i in keys:
            rd[i].sort()
        k = 0
        flag = 0
        for i in keys:
            if flag:
                break
            for j in rd[i]:
                result.append(j)
                k+=1
                if k==K:
                    flag = 1
                    break
        return result
        
            
        