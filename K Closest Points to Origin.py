class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        d = {}
        for i in points:
            distance = i[0]**2 + i[1]**2
            a = d.get(distance,[])
            a.append(i)
            d[distance] = a
        result = []
        keys = list(d.keys())
        keys.sort()
        result = []
        k = 0
        flag = 0
        for i in keys:
            if flag:
                break
            for j in d[i]:
                result.append(j)
                k+=1
                if k==K:
                    flag = 1
                    break
        return result