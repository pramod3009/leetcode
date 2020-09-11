class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        ans = ""
        prev_x, prev_y = 0, 0
        for ch in target:
            x = (ord(ch) - ord('a')) // 5
            y = (ord(ch) - ord('a')) % 5
            deltax = x - prev_x
            deltay = y - prev_y
            mov1  = 'R'*deltay if deltay > 0 else 'L'*(-deltay)
            mov2 =  'D'*deltax if deltax > 0 else 'U'*(-deltax)
            ans+= (mov1 + mov2 if (x , y) == (5, 0) else mov2+mov1) + '!'
            prev_x, prev_y = x, y
        return ans
        
