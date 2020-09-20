class Solution:
    def buddyStrings(self, a: str, b: str) -> bool:
        if len(a)!=len(b):
            return False
        if a == b:
            seen = set()
            for a_ in a:
                if a_ in seen:
                    return True
                seen.add(a_)
            return False
        count  = 0
        first  = 0
        second = 0
        for i in range(0, len(a)):
            if a[i] != b[i]:
                count+=1
                if count==1:
                    first = i
                elif count==2:
                    second = i
                else:
                    return False
        if count < 2:
            return False
        return a[first]==b[second] and a[second]==b[first]
                    
        
