class Solution:
    def frequencySort(self, s: str) -> str:
        d = {}
        rev_d = {}
        for i in s:
            d[i] = d.get(i,0)+1
        for i in list(d.keys()):
            a = rev_d.get(d[i],[])
            a.insert(0,i)
            rev_d[d[i]] = a
        values = list(rev_d.keys())
        values.sort()
        values = values[::-1]
        result = ""
        for i in values:
            for j in rev_d[i]:
                result += j*i
        #print(result)
        return result
            
        