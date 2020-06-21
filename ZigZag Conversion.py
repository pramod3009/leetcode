class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows==1:
            return s
        result = [""]*numRows
        curRow = 0
        down = False
        for i in s:
            print(i)
            result[curRow]+=i
            print(curRow,down)
            if curRow == 0 or curRow == numRows - 1:
                down = not down
            if down:
                curRow+=1
            else:
                curRow-=1
        return "".join(result)
        