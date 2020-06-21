class Solution:
    
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        if len(s)<10: return []
        ht=collections.defaultdict(int)
        res=set()
        while len(s)>=10:
            ht[s[:10]]+=1
            if ht[s[:10]]>1: res.add(s[:10])
            s=s[1:]            
        return list(res)