class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        n = len(secret)
        bull = 0
        
        for i in range(0,n):
            if secret[i]==guess[i]:
                bull+=1
        
        cow = 0
        d = {}
        for i in secret:
            d[i] = d.get(i,0) + 1
        
        for i in guess:
            if d.get(i,0):
                d[i] = d[i] - 1
                cow+=1
        return str(bull)+"A"+str(cow-bull)+"B"
                
        