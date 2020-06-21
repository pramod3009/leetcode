class Solution:
    def isValid(self, s: str) -> bool:
        a = []
        d = {'}':'{',']':'[',')':'('}
        lengtha=0
        for i in s:
            if i in ['(','[','{']:
                a.insert(0,i)
                lengtha+=1
            else:
                if lengtha and d[i] == a[0]:
                    a.pop(0)
                    lengtha-=1
                else:
                    return False
        if len(a)==0:
            return True
        else:
            return False
            
        