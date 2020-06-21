class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        d = {}
        if not len(text):
            return 0
        for i in text:
            if i in ['b','a','l','o','n']:
                d[i] = d.get(i,0) + 1
        import sys
        result = sys.maxsize
        print(d)
        for i in ['b','a','l','o','n']:
            if i in ['l','o']:
                result = min(result,d.get(i,0)//2)
            else:
                result = min(result,d.get(i,0))
        return result
        