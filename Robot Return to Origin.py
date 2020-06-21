class Solution:
    def judgeCircle(self, moves: str) -> bool:
        if not len(moves):
            return True
        d= {"U":0,"D":0,"L":0,"R":0}
        for i in moves:
            d[i] = d[i] + 1
        if d["U"]==d["D"] and d["L"]==d["R"]:
            return True
        return False