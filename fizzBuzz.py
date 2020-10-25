class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        d = {3:"Fizz", 5:"Buzz"}
        res = []
        for i in range(1, n + 1):
            temp = ""
            for key in d.keys():
                if i % key == 0:
                    temp += d[key]
            if temp=="":
                temp+=str(i)
            res.append(temp)
        return res
        
