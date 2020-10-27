class Solution:
    def minSteps(self, s: str, t: str) -> int:
        result = 0
        d1 = {}
        d2 = {}
        for i in s:
            d1[i] = d1.get(i, 0) + 1;
        for i in t:
            d2[i] = d2.get(i, 0) + 1
        keys = list(set(list(d1.keys()) + list(d2.keys())))
        print(d1,d2,keys)
        for key in keys:
            if d2.get(key, 0) < d1.get(key, 0):
                result += d1.get(key, 0) - d2.get(key, 0)
        return result;
        
