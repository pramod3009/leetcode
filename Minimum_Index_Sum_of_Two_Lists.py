class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        d = {}
        lsum = 10000000
        res = []
        for i in range(len(list1)):
            d[list1[i]] = i
        #print(d)
        for i in range(len(list2)):
            if d.get(list2[i],-1)!=-1:
                #print(list2[i])
                if d[list2[i]] + i  < lsum:
                    res.clear()
                    res.append(list2[i])
                    lsum = d[list2[i]] + i
                elif d[list2[i]] + i  == lsum:
                    res.append(list2[i])
        return res
                    
                    
                
        